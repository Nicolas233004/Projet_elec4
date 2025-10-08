#ifndef CONTROL_LOOP_H
#define CONTROL_LOOP_H

#include <PID_v1.h>

enum ControlOperatingMode
{
    Manual = MANUAL,
    Automatic = AUTOMATIC
};

enum PidDirection
{
    Direct = DIRECT,
    Reverse = REVERSE
};

struct ControlLoopConfig
{
    // Control mode
    ControlOperatingMode mode;
    PidDirection direction;

    // Setpoints
    double setpoint;
    double minSetpoint;
    double maxSetpoint;

    // Control output
    double minControlOutput;
    double maxControlOutput;

    // Tuning parameters for PID control
    // https://en.wikipedia.org/wiki/Proportional%E2%80%93integral%E2%80%93derivative_controller#Controller_theory
    double kp; // Proportional gain
    double ki; // Integral gain
    double kd; // Derivative gain
    int pOn; // Proportionnal on measurement or on error

    // Control loop status
    bool enabled;
    bool inAlarm;

    // Alarm limits
    double highAlarmLimit;
    double lowAlarmLimit;

    // Control loop performance metrics
    // float integralError;
    // float lastError;
    // float errorRate;

    // Timing parameters
    uint32_t sampleTime; // in milliseconds
    // uint32_t lastUpdateTime;
};

class PIDControlLoop {
public:
    PIDControlLoop(ControlLoopConfig& config);

    void start(double setpoint);
    void stop(void);
    bool isRunning(void);
    void setup();
    void update(double processVariable);
    void reset();
    double getOutput() const;
    void setTunings(double kp, double ki, double kd);
    void setMode(ControlOperatingMode mode);

private:
    ControlLoopConfig& cfg;
    double input;
    double output;
    PID pid;
};

#endif // CONTROL_LOOP_H