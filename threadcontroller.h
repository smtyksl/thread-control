#ifndef THREADCONTROLLER_H
#define THREADCONTROLLER_H

#include <thread>

class ThreadController : std::thread
{
    State getState() const;
    void setState(State state);
    int getSleepTime(State state) const;
    void setSleepTime(State state, int sleepTime);

private:
    enum State {
        Running = 0,
        Pause = 1,
        Start = 2,
        Stop = 3
    };

    std::atomic<State> runningState { Running };
    std::atomic<int> sleepTimes[4] { 100, 500, 50, 0 };
};

#endif // THREADCONTROLLER_H
