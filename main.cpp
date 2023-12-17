#include <iostream>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstring>
#include <memory>


#include "User.h"
#include "Circle.h"
#include "Semaphore.h"

using namespace std;

mutex mtx;


void threadFunction()
{
    // Wait
    mtx.lock(); 
    std::cout << "\nEntered.." << endl;

    this_thread::sleep_for(chrono::seconds(2));

     std::cout << "\nJust exiting.." << endl;
    mtx.unlock(); 
}

void threadFunctionForRAIISemaphores(int id, Semaphore& semaphore)
{
    semaphore.wait();
    std::cout << "Thread " << id << " entered.." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread " << id << " exiting..." << std::endl;
    semaphore.signal();
}

int main()
{
    unique_ptr<Cr::Circle> circle(new Cr::Circle(5));

    cout << "-----------------------------------"<<endl
         << circle->getArea()<<endl;

    shared_ptr<User> firstUser(new User("cipi", "123")); 

    cout << "-----------------------------------"<<endl
         << "user1: "<<endl << firstUser->getUsername() <<endl << firstUser->getPassword() <<endl;

    User secondUser = move(*firstUser);

    cout << "-----------------------------------"<<endl
         << "user2: "<<endl << secondUser.getUsername() <<endl << secondUser.getPassword() <<endl;

    
    thread t1(threadFunction);
    this_thread::sleep_for(chrono::seconds(1));
    thread t2(threadFunction);
    this_thread::sleep_for(chrono::seconds(5));

    Semaphore semaphore(1);
    thread t3(threadFunctionForRAIISemaphores, 1, ref(semaphore));
    thread t4(threadFunctionForRAIISemaphores, 2, ref(semaphore));

    t1.join();
    t2.join();

    t3.join();
    t4.join();    

    return 0;
}