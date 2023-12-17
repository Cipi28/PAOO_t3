#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <string>
#include <semaphore.h>

using namespace std;

class Semaphore {
public:
    explicit Semaphore(int initialCount = 1) : count(initialCount) {}

    void wait();
    void signal();

private:
    std::mutex mutex;
    std::condition_variable condition;
    int count;
};

#endif