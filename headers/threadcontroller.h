#ifndef THREADCONTROLLER_H
#define THREADCONTROLLER_H
#include <thread>
#include <atomic>

class ThreadController : std::thread
{
public:
    enum State {
        Running = 0,
        Pause = 1,
        Start = 2,
        Stop = 3
    };

private:
    std::atomic<State> runningState { Running };
    std::array<std::atomic<int>*, 4> sleepTimes { {
        new std::atomic<int>{100},
        new std::atomic<int>{500},
        new std::atomic<int>{50},
        new std::atomic<int>{0}
    } };

    std::string stateToString(State state);
public:
    State getState() const;
    void setState(State state);
    int getSleepTime(State state) const;
    void setSleepTime(State state, int sleepTime);

};

#endif // THREADCONTROLLER_H
