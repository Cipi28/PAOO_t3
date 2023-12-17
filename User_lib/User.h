#include <string>
using namespace std;

class User {
    private:
        char* username;
        char* password;
    public:
        //constructor
        User(char* username, char* password);
        //copy constructor
        User(const User& u);
        //move constructor
        User(User&& u);
        //destructor
        ~User();
        
        string getUsername();
        void setUsername(const char* username);
        string getPassword();
        void setPassword(const char* password);
};