#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    const size_t N = 1000000;
    std::vector<int> data(N);

    
    std::iota(data.begin(), data.end(), 0);

    
    std::for_each(std::execution::seq, data.begin(), data.end(), [](int &x) { x += 1; });

    std::cout << "First element after std::execution::seq: " << data[0] << std::endl;

    
    std::iota(data.begin(), data.end(), 0);

    
    std::for_each(std::execution::par, data.begin(), data.end(), [](int &x) { x += 1; });

    
    std::cout << "First element after std::execution::par: " << data[0] << std::endl;

    
    std::iota(data.begin(), data.end(), 0);

    std::for_each(std::execution::par_unseq, data.begin(), data.end(), [](int &x) { x += 1; });

    

    return 0;
}