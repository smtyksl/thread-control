#include <iostream>
#include "threadcontroller.h"

ThreadController::State ThreadController::getState() const {
    return runningState.load();
}

void ThreadController::setState(State state) {
    std::cout << "Thread state changed to code : " << state << " message :" << stateToString(state) <<std::endl;
    runningState.store(state);
}

int ThreadController::getSleepTime(State state) const {
    return sleepTimes[state]->load();
}

void ThreadController::setSleepTime(State state, int sleepTime) {
    sleepTimes[state]->store(sleepTime);
}

std::string ThreadController::stateToString(State state) {
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
