#include <iostream>
#include <string>
#include <iostream>


#include <thread>
#include <mutex>
#include <chrono>
#include <cstring>
#include <memory>
#include <semaphore>


#include "User.h"
#include "Circle.h"
#include "Semaphore.h"

using namespace std;
// counting_semaphore<int> mySemaphore(2); 

mutex mtx;


void threadFunction(string names[])
{
    static int i = 0;
    string name = names[i++];
    this_thread::sleep_for(chrono::seconds(1));
    std::cout << "\nStart: " << name << endl;
    lock_guard<mutex> lock(mtx);
    // std::cout << "\nEntered.." << endl;
    
    names[i--] = name;

    //  std::cout << "\nJust exiting.." << endl;

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

    
    //create an array of names
    string names[4] = { "Ion", "Ana", "Irina", "Cosmin" };
    thread t1(threadFunction, names);
    thread t2(threadFunction, names);
    thread tt1(threadFunction, names);
    thread tt2(threadFunction, names);

    t1.join();
    t2.join();
    tt1.join();
    tt2.join();
    cout << "Reordered array" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << names[i] << endl;
    }
    this_thread::sleep_for(chrono::seconds(5));

    Semaphore semaphore(1);
    // thread t3(threadFunctionForRAIISemaphores, 1, ref(semaphore));
    // thread t4(threadFunctionForRAIISemaphores, 2, ref(semaphore));

    // t3.join();
    // t4.join();    

    return 0;
}