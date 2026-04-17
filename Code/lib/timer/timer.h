#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {
public:
    Timer(unsigned long interval = 1000); // Default interval: 1000 ms

    void start();
    void stop();
    void reset();
    void setInterval(unsigned long interval);
    bool isElapsed();
    bool isRunning() const;

private:
    unsigned long _interval;
    unsigned long _startTime;
    bool _running;
};

#endif // TIMER_H
