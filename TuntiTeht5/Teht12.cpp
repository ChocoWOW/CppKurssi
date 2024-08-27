#include <iostream>
#include <vector>
#include <algorithm>

// a. 
void reduce_hp(int &hp) {
    if (hp > 100) {
        hp -= 100;
    } else {
        hp = 0;
    }
}

// b. 
struct ReduceHPFunctor {
    void operator()(int &hp) const {
        if (hp > 100) {
            hp -= 100;
        } else {
            hp = 0;
        }
    }
};

int main() {
    std::vector<int> hitpoints = {350, 200, 100, 50, 600};

    // a.
    std::for_each(hitpoints.begin(), hitpoints.end(), reduce_hp);

    
    std::cout << "After reduce_hp function: ";
    for (const auto &hp : hitpoints) {
        std::cout << hp << " ";
    }
    std::cout << std::endl;

    
    hitpoints = {350, 200, 100, 50, 600};

    // b.
    std::for_each(hitpoints.begin(), hitpoints.end(), ReduceHPFunctor());

    
    std::cout << "ReduceHPFunctor: ";
    for (const auto &hp : hitpoints) {
        std::cout << hp << " ";
    }
    std::cout << std::endl;

    
    hitpoints = {350, 200, 100, 50, 600};

    // c. 
    std::for_each(hitpoints.begin(), hitpoints.end(), [](int &hp) {
        if (hp > 100) {
            hp -= 100;
        } else {
            hp = 0;
        }
    });

    
    std::cout << "lambda function: ";
    for (const auto &hp : hitpoints) {
        std::cout << hp << " ";
    }
    std::cout << std::endl;

    
    hitpoints = {350, 200, 100, 50, 600};

    // d.
    auto reduce_hp_lambda = [](int &hp) {
        if (hp > 100) {
            hp -= 100;
        } else {
            hp = 0;
        }
    };

    std::for_each(hitpoints.begin(), hitpoints.end(), reduce_hp_lambda);

    std::cout << "After named lambda function: ";
    for (const auto &hp : hitpoints) {
        std::cout << hp << " ";
    }
    std::cout << std::endl;

    // Järjestä vektori suurimmasta pienimpään käyttämällä std::sort ja lambda-funktiota
    std::sort(hitpoints.begin(), hitpoints.end(), [](int a, int b) {
        return a > b;
    });

    
    std::cout << "After sorting (descending): ";
    for (const auto &hp : hitpoints) {
        std::cout << hp << " ";
    }
    std::cout << std::endl;

    return 0;
}
