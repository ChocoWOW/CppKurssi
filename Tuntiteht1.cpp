#include <iostream>
#include <vector>
#include <future>
#include <numeric>

// Funktio, joka laskee osataulukon summan
long long sum_part(const std::vector<int>& data, size_t start, size_t end) {
    return std::accumulate(data.begin() + start, data.begin() + end, 0LL);
}

int main() {
    // Suuren taulukon luominen (vektori)
    const size_t dataSize = 1000000;  // Miljoona elementtiä
    std::vector<int> large_vector(dataSize, 1); // Jokainen elementti on 1
    
    // Määritellään asynkronisten tehtävien (osien) määrä
    const size_t num_tasks = 10;
    size_t part_size = dataSize / num_tasks;
    
    // Vektori, joka sisältää tulevaisuusobjektit (futures) tuloksia varten
    std::vector<std::future<long long>> futures;
    
    // Luodaan asynkroniset tehtävät ja annetaan niille laskettavaksi osa vektorista
    for (size_t i = 0; i < num_tasks; ++i) {
        size_t start = i * part_size;
        size_t end = (i == num_tasks - 1) ? dataSize : start + part_size;
        futures.push_back(std::async(std::launch::async, sum_part, std::cref(large_vector), start, end));
    }
    
    // Yhdistetään kaikkien tehtävien tulokset
    long long total_sum = 0;
    for (auto& future : futures) {
        total_sum += future.get();  // Odottaa tehtävän valmistumista ja hakee tuloksen
    }

    // Tulostetaan kokonaissumma
    std::cout << "Kokonaisumma on: " << total_sum << std::endl;

    return 0;
}
