#include <iostream>
#include <fstream>
#include <memory>
#include <ctime>

template<typename T>
class Log_Ptr {
private:
    T* ptr;
    std::ofstream logFile;

    // Funktio aikaleiman saamiseksi
    std::string getTimestamp() const {
        time_t now = time(0);
        char* dt = ctime(&now);
        return std::string(dt).substr(0, std::string(dt).size() - 1); // Poistaa rivinvaihdon
    }

public:
    // Konstruktori
    explicit Log_Ptr(T* p = nullptr) : ptr(p), logFile("log_ptr.txt", std::ios::app) {
        if (ptr) {
            logFile << getTimestamp() << " omistajuus siirretty " << ptr << std::endl;
        }
    }

    // Destruktori
    ~Log_Ptr() {
        if (ptr) {
            logFile << getTimestamp() << " olio tuhottu " << ptr << std::endl;
            delete ptr;
        }
    }

    // Kopiointi estetty
    Log_Ptr(const Log_Ptr&) = delete;
    Log_Ptr& operator=(const Log_Ptr&) = delete;

    // -> operaattori
    T* operator->() {
        if (ptr) {
            logFile << getTimestamp() << " operator-> " << ptr << std::endl;
        }
        return ptr;
    }

    // * operaattori
    T& operator*() {
        if (ptr) {
            logFile << getTimestamp() << " operator* " << ptr << std::endl;
        }
        return *ptr;
    }
};

// Testiluokka
class Test {
public:
    void sayHello() {
        std::cout << "Hello from Test class!" << std::endl;
    }
    Test() {
        std::cout << "Test constructor" << std::endl;
    }
    ~Test() {
        std::cout << "Test destructor" << std::endl;
    }
};

// Pääohjelma
int main() {
    {
        Log_Ptr<Test> logPtr(new Test());
        logPtr->sayHello();  // Käytetään -> operaattoria
        (*logPtr).sayHello();  // Käytetään * operaattoria
    }
    std::cout << "Log_Ptr object out of scope." << std::endl;
    return 0;
}
