#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include "threadcontroller.h"


void myThreadFunction(ThreadController& controller) {
    while (controller.getState() != ThreadController::Stop) {
        ThreadController::State state = controller.getState();
        int sleepTime = controller.getSleepTime(state);

        if (state == ThreadController::Running) {
            // do something while running
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        } else if (state == ThreadController::Pause) {
            // do something while pause   d
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        } else if (state == ThreadController::Start) {
            // do something while starting
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
}

int main()
{
    ThreadController controller;
    std::thread myThread(myThreadFunction, std::ref(controller));

    // set the state of the thread to "Start"
    controller.setState(ThreadController::Stop);

    // wait for the thread to finish
    myThread.join();
    for(size_t i = 0; i< static_cast<ThreadController::State>(ThreadController::State::Stop); i++)
        controller.setState(static_cast<ThreadController::State>(i));


    return 0;
}
