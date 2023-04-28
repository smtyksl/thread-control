#ifndef THREADCONTROLLER_H
#define THREADCONTROLLER_H

#include <thread>
#include <atomic>
#include <array>
#include <string>

class ThreadController : std::thread
{
public:
    enum State {
        Running = 0,
        Pause = 1,
        Start = 2,
        Stop = 3
    };

    ThreadController() = default;
    ~ThreadController() = default;

    State getState() const {
        return runningState.load();
    }

    void setState(State state) {
        std::cout << "Thread state changed to code : " << state << " message :" << stateToString(state) <<std::endl;
        runningState.store(state);
    }

    int getSleepTime(State state) const {
        return sleepTimes[state]->load();
    }

    void setSleepTime(State state, int sleepTime) {
        sleepTimes[state]->store(sleepTime);
    }

private:
    std::atomic<State> runningState { Running };
    std::array<std::atomic<int>*, 4> sleepTimes { {
        new std::atomic<int>{100},
        new std::atomic<int>{500},
        new std::atomic<int>{50},
        new std::atomic<int>{0}
    } };

    std::string stateToString(State state) {
        switch (state) {
            case State::Running:
                return "Running";
            case State::Pause:
                return "Pauseing";
            case State::Start:
                return "Starting";
            case State::Stop:
                return "Stoping";
            default:
                return "";
        }
    }
};

#endif // THREADCONTROLLER_H

