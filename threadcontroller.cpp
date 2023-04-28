#include "threadcontroller.h"

ThreadController::State ThreadController::getState() const {
    return runningState.load();
}

void ThreadController::setState(State state) {
    runningState.store(state);
}

int ThreadController::getSleepTime(State state) const {
    return sleepTimes[state].load();
}

void ThreadController::setSleepTime(State state, int sleepTime) {
    sleepTimes[state].store(sleepTime);
}
