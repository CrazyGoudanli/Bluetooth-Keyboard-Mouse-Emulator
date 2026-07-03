#include "imuMouse.h"
#include <M5Cardputer.h>
#include <math.h>

namespace {
// Gyro units returned by M5Unified are degrees/second for BMI270.
// Tune these if the real device feels too slow/fast or if an axis is inverted.
constexpr float GYRO_DEADZONE_DPS = 6.0f;
constexpr float GYRO_SENSITIVITY = 0.16f;
constexpr float FILTER_ALPHA = 0.35f;
constexpr int MAX_DELTA = 20;

float filteredX = 0.0f;
float filteredY = 0.0f;
bool imuReady = false;

float applyDeadzone(float value)
{
    if (fabsf(value) < GYRO_DEADZONE_DPS) {
        return 0.0f;
    }
    return value > 0 ? value - GYRO_DEADZONE_DPS : value + GYRO_DEADZONE_DPS;
}

int8_t clampToMouseDelta(float value)
{
    if (value > MAX_DELTA) return MAX_DELTA;
    if (value < -MAX_DELTA) return -MAX_DELTA;
    return static_cast<int8_t>(value);
}
} // namespace

void setupImuMouse()
{
    imuReady = M5.Imu.isEnabled();
    filteredX = 0.0f;
    filteredY = 0.0f;
}

MouseDelta readImuMouseDelta()
{
    MouseDelta delta = {0, 0};

    if (!imuReady) {
        imuReady = M5.Imu.isEnabled();
        if (!imuReady) {
            return delta;
        }
    }

    float gx = 0.0f;
    float gy = 0.0f;
    float gz = 0.0f;
    if (!M5.Imu.getGyro(&gx, &gy, &gz)) {
        return delta;
    }

    // Air-mouse style mapping for Cardputer-Adv held in normal landscape orientation:
    // yaw around Z controls left/right, pitch around X controls up/down.
    // Invert Y so tilting/rotating the top away generally moves the cursor up.
    float rawX = applyDeadzone(gz) * GYRO_SENSITIVITY;
    float rawY = -applyDeadzone(gx) * GYRO_SENSITIVITY;

    filteredX = (FILTER_ALPHA * rawX) + ((1.0f - FILTER_ALPHA) * filteredX);
    filteredY = (FILTER_ALPHA * rawY) + ((1.0f - FILTER_ALPHA) * filteredY);

    delta.x = clampToMouseDelta(filteredX);
    delta.y = clampToMouseDelta(filteredY);
    return delta;
}
