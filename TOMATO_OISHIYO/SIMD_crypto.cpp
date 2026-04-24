#include <cstdint>
#include <vector>
#include <type_traits>
#include <array>
#include <x86intrin.h>
#include <iostream>
#include <thread>
#include <openssl/sha.h>
#include <random>

std::random_device seed_gen;
std::mt19937 engine{seed_gen()};
std::uniform_real_distribution<> dist(0.0, 512.0);


void hoge(){
    __m128 x;
    __m512d x;
    __m256 y;
}
