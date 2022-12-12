#include <fstream>
#include <numeric>

std::vector<u64> get_primes_up_to(u64 max);

// int main() {
int main(i32 argc, char **argv) {
    if (argc != 2)
        return 1;

    auto max = std::stoull(std::string(argv[1]));
    // auto max = std::numeric_limits<u32>::max();
    auto result = get_primes_up_to(max - 1);

    auto f = std::ofstream("primes.txt");
    for (auto n : result)
        f << n << "\n";

    return 0;
}

std::vector<u64> get_primes_up_to(u64 max) {
    auto nums = std::vector<bool>(max - 2); // We remove 0 and 1
    std::fill(nums.begin(), nums.end(), false);

    u64 last_prime = 2;

algo_start:
    u64 i = 2;
    for (u64 n = last_prime * i; n < max; n = last_prime * i) {
        nums[n - 2] = true;
        ++i;
    }

    for (size_t n = last_prime - 1; n < nums.size(); ++n) {
        if (!nums[n]) {
            last_prime = n + 2;
            goto algo_start;
            break;
        }
    }

    std::cout << "Done" << std::endl;

    std::vector<u64> result;

    for (size_t n = 0; n < nums.size(); ++n) {
        if (!nums[n])
            result.push_back(n + 2);
    }
    return result;
}