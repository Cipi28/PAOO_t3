#include <iostream>
#include <string>
#include "User.h"
using namespace std;


//constructor
User::User(char* username, char* password)
    {
        this->username = static_cast<char*>(malloc(strlen(username) + 1));
        strcpy(this->username, username);
        this->password = static_cast<char*>(malloc(strlen(password) + 1));
        strcpy(this->password, password);
        cout<<"User constrution"<<endl;
    }

// copy constructor
User::User(const User& u) {
    this->username = static_cast<char*>(malloc(strlen(u.username) + 1));
    strcpy(this->username, u.username);
    this->password = static_cast<char*>(malloc(strlen(u.password) + 1));
    strcpy(this->password, u.password);
        cout << "User copy" << endl;
    }

// move constructor
User::User(User&& u) {
    this->username = u.username;
    this->password = u.password;

    u.username = nullptr;
    u.password = nullptr;

    cout << "User move constructor" << endl;
}

//destructor
User::~User() {
        free(this->username);
        free(this->password);
    cout<<"User destruciton"<<endl;
}

string User::getUsername()
{
    if(this->username == nullptr) {
        return "null";
    }
    return string(this->username);
}

void User::setUsername(const char* username)
{
    strcpy(this->username, username);
}

string User::getPassword()
{
    if(this->password == nullptr) {
        return "null";
    }
    return string(this->password);
}

void User::setPassword(const char* password)
{
    strcpy(this->password, password);
}