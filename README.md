# ThreadController

ThreadController is a C++11 compliant wrapper for `std::thread`. The ThreadController class can be used to control the state of a running thread. It can also be used to change the execution speed and pause time of the thread.

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)	![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)

# Build Status

[![CMake](https://github.com/smtyksl/thread-control/actions/workflows/cmake.yml/badge.svg)](https://github.com/smtyksl/thread-control/actions/workflows/cmake.yml)

## Dependencies

* `std::thread`
* `std::atomic`
* `std::array`
* `iostream`

## Configuration

The ThreadController class can be configured and installed through `cmake`. The `cmake` version should be at least 3.5.Kurulum

```bash
$ mkdir build && cd build
$ cmake ..
$ make
$ sudo make install
```

# Usage

The ThreadController class includes the header file `threadcontroller.h`. After adding this header file to your project, you can use the ThreadController class as follows:

```c
#include "threadcontroller.h"

// Thread func
void myThreadFunction(ThreadController& controller) {
    while (controller.getState() != ThreadController::Stop) {
        ThreadController::State state = controller.getState();
        int sleepTime = controller.getSleepTime(state);

        if (state == ThreadController::Running) {
            // at running do something
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        } else if (state == ThreadController::Pause) {
            // at pause do something
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        } else if (state == ThreadController::Start) {
            // at start do something
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
}

int main() {
    ThreadController controller;

    // initial state
    controller.setState(ThreadController::Start);

    myThread.join();

    return 0;
}

```

# Header-only Library

ThreadController is also available as a header-only library. You can download the [threadcontroller.hpp](https://github.com/smtyksl/thread-control/blob/master/headers/threadcontroller.hpp)  file and add it to your project directly.

## GCC Version

ThreadController is written to be compliant with C++11 standards. Therefore, it requires GCC 4.8 or later.
