#include <Arduino.h>
#include "control_loop.h"

PIDControlLoop::PIDControlLoop(ControlLoopConfig &config)
    : cfg(config),
      input(0.0), output(0.0),
      pid(&input, &output, &cfg.setpoint, cfg.kp, cfg.ki, cfg.kd, cfg.direction)
{

    pid.SetOutputLimits(cfg.minControlOutput, cfg.maxControlOutput);
    pid.SetSampleTime(cfg.sampleTime);
    pid.SetMode(cfg.mode);
}

void PIDControlLoop::setup()
{
    pid.SetTunings(cfg.kp, cfg.ki, cfg.kd, cfg.pOn);
    pid.SetOutputLimits(cfg.minControlOutput, cfg.maxControlOutput);
    pid.SetSampleTime(cfg.sampleTime);
    pid.SetMode(MANUAL);
    output = cfg.minControlOutput;
    pid.SetMode(cfg.mode);
    pid.SetControllerDirection(cfg.direction);
}

void PIDControlLoop::update(double processVariable)
{
    if (!cfg.enabled)
        return;

    input = processVariable;
    pid.Compute();

    cfg.inAlarm = (input < cfg.lowAlarmLimit || input > cfg.highAlarmLimit);
}

void PIDControlLoop::reset()
{
    if (cfg.enabled)
        return;
    pid.SetMode(MANUAL);
    output = cfg.minControlOutput;
    pid.SetMode(cfg.mode);
}

double PIDControlLoop::getOutput() const
{
    if (!cfg.enabled)
        return 0;
    return output;
}

void PIDControlLoop::setTunings(double kp, double ki, double kd)
{
    cfg.kp = kp;
    cfg.ki = ki;
    cfg.kd = kd;
    pid.SetTunings(kp, ki, kd);
}

void PIDControlLoop::setMode(ControlOperatingMode mode)
{
    cfg.mode = mode;
    pid.SetMode(mode);
}

void PIDControlLoop::start(double setpoint)
{
    cfg.setpoint = setpoint;
    cfg.enabled = true;
}

void PIDControlLoop::stop(void)
{
    cfg.enabled = false;
}

bool PIDControlLoop::isRunning(void)
{
    return cfg.enabled;
}
