#include <iostream>
#include <vector>
#include <thread>
#include <numeric>




int total_sum = 0;
void sum_part(const std::vector<int>& data, int start, int end) {
    int partial_sum = std::accumulate(data.begin() + start, data.begin() + end, 0);

    
    total_sum += partial_sum; 
}
int main() {
	const size_t dataSize = 1000000;
    std::vector<int> large_vector(dataSize, 1);

	const size_t num_tasks = 10;
    size_t part_size = dataSize / num_tasks;

	std::vector<std::thread> threads;
	for (int i = 0; i < num_tasks; i++) {
		int start = i * part_size;
		int end = (i == num_tasks - 1) ? dataSize : start + part_size;
		threads.emplace_back(sum_part, std::cref(large_vector), start, end);
    }
 
    for (auto& th : threads) {
        th.join();
    }
    
    std::cout << "Kokonaisumma on: " << total_sum << std::endl;

    return 0;
}
