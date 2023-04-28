# ThreadController

ThreadController, C++11 standartlarına uygun şekilde yazılmış, bir `std::thread` sarmalayıcısıdır. ThreadController sınıfı, çalışan bir thread'in durumunu kontrol etmek için kullanılabilir. Ayrıca thread'in çalışma hızını ve duraklatma süresini değiştirmek için de kullanılabilir.

## Bağımlılıklar

ThreadController sınıfı, aşağıdaki kütüphanelere bağımlıdır:

* `std::thread`
* `std::atomic`
* `std::array`
* `iostream`

## Yapılandırma

ThreadController sınıfı, `cmake` aracılığıyla yapılandırılabilir ve kurulabilir. `cmake` sürümü en az 3.5 olmalıdır.

### Kurulum

```
$ mkdir build && cd build
$ cmake ..
$ make
$ sudo make install
```

Kullanım

ThreadController sınıfı, `threadcontroller.h` başlık dosyasını içerir. Bu başlık dosyasını projenize ekledikten sonra, ThreadController sınıfını aşağıdaki gibi kullanabilirsiniz:

```
#include "threadcontroller.h"

// Thread fonksiyonu
void myThreadFunction(ThreadController& controller) {
    while (controller.getState() != ThreadController::Stop) {
        ThreadController::State state = controller.getState();
        int sleepTime = controller.getSleepTime(state);

        if (state == ThreadController::Running) {
            // running durumunda yapılacak işlemler
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        } else if (state == ThreadController::Pause) {
            // pause durumunda yapılacak işlemler
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        } else if (state == ThreadController::Start) {
            // start durumunda yapılacak işlemler
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
    }
}

int main() {
    ThreadController controller;

    // Thread'i başlatmak için State'i Start'a ayarla
    controller.setState(ThreadController::Start);

    // Thread'in bitmesini bekle
    myThread.join();

    return 0;
}

```

## GCC Versiyonu

ThreadController, C++11 standartlarına uygun olarak yazılmıştır. Bu nedenle, GCC 4.8 veya daha yeni bir sürümü gerektirir. ThreadController sınıfının kullanımı aşağıdaki GCC sürümlerinde test edilmiştir:

* GCC 4.8.5
* GCC 5.4.0
* GCC 6.5.0
* GCC 7.5.0
* GCC 8.5.0
* GCC 9.3.0
* GCC 10.3.0
