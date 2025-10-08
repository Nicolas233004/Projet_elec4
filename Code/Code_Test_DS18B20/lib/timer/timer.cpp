#include "timer.h"

Timer::Timer(unsigned long interval)
    : _interval(interval), _startTime(0), _running(false) {}

void Timer::start() {
    _startTime = millis();
    _running = true;
}

void Timer::stop() {
    _running = false;
}

void Timer::reset() {
    _startTime = millis();
}

void Timer::setInterval(unsigned long interval) {
    _interval = interval;
}

bool Timer::isElapsed() {
    if (!_running) return false;
    return (millis() - _startTime) >= _interval;
}

bool Timer::isRunning() const {
    return _running;
}
