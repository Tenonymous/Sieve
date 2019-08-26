#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

void sieve(std::vector<int>&, int, int);
void print(const std::vector<int>&);

int main()
{
    constexpr int max = 30;
    std::vector<int> vec(max - 2); 
    std::iota(vec.begin(), vec.end(), 2);
    auto square = std::sqrt(max);
    sieve(vec, static_cast<int>(square), 0);
    print(vec);
}

void sieve(std::vector<int>& vec, int square, int actual)
{
    vec.erase(std::remove_if(vec.begin() + actual + 1, vec.end(),  [=](int x){return x % vec[actual] == 0;}),vec.end());   
    if (actual  <= square) return sieve(vec, square, actual + 1);
}

void print(const std::vector<int>& vec)
{
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}
