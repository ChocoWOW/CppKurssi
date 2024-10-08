#include <iostream>
#include <thread>
#include <mutex>
std::mutex mutex;
class BankAccount {
public:
    
    BankAccount() : balance(200) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> guard(mutex);
        balance += amount;
        total_deposits++;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> guard(mutex);
        balance -= amount;
        total_withdrawals++;
        
    }

    int get_balance() const {
        return balance;
    }

    int get_total_deposits() const {
        return total_deposits;
    }

    int get_total_withdrawals() const {
        return total_withdrawals;
    }

private:
    int balance;
    int total_deposits = 0;
    int total_withdrawals = 0;
    
};

void deposit_task(BankAccount& account) {
    for (int i = 0; i < 10000; ++i) {
        account.deposit(1);
    }
}

void withdraw_task(BankAccount& account) {
    for (int i = 0; i < 10000; ++i) {
        account.withdraw(1);
    }
}

int main() {
    BankAccount account;

    std::thread t1(deposit_task, std::ref(account));
    std::thread t2(withdraw_task, std::ref(account));

    t1.join();
    t2.join();

    std::cout << "Final balance: " << account.get_balance() << std::endl;
    std::cout << "Total deposits: " << account.get_total_deposits() << std::endl;
    std::cout << "Total withdrawals: " << account.get_total_withdrawals() << std::endl;

    return 0;
}