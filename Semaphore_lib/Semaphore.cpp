#include <iostream>
#include <string>
#include "Semaphore.h"

using namespace std;

void Semaphore::wait() {
        std::unique_lock<std::mutex> lock(this->mutex);
        this->condition.wait(lock, [this] { return count > 0; });
        this->count--;
    }

void Semaphore::signal() {
        std::unique_lock<std::mutex> lock(this->mutex);
        this->count++;
        this->condition.notify_one();
    }