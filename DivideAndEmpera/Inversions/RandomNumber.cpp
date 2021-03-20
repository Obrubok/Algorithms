#include <random>

long getRandomNumberDiap(long a, long b) {
    std::random_device rd;
    std::mt19937_64 mersenne(rd());
    std::uniform_int_distribution<> distribution(a, b);
    return distribution(mersenne);
}