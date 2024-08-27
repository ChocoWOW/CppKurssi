#include <iostream>
#include <vector>
#include <future>
#include <mutex>

class BankAccount {
public:
    BankAccount() : balance(0) {}

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance -= amount;
    }

    int get_balance() const {
        return balance;
    }

private:
    int balance;
    std::mutex mtx;
};

void deposit_money(BankAccount &account, int num_transactions, int amount) {
    for (int i = 0; i < num_transactions; ++i) {
        account.deposit(amount);
    }
}

void withdraw_money(BankAccount &account, int num_transactions, int amount) {
    for (int i = 0; i < num_transactions; ++i) {
        account.withdraw(amount);
    }
}

int main() {
    BankAccount account;
    const int num_transactions = 10000;
    const int amount = 1;

    auto deposit_future = std::async(std::launch::async, deposit_money, std::ref(account), num_transactions, amount);
    auto withdraw_future = std::async(std::launch::async, withdraw_money, std::ref(account), num_transactions, amount);

    deposit_future.get();
    withdraw_future.get();

    std::cout << "Final balance: " << account.get_balance() << std::endl;

    return 0;
}
