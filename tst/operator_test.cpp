//
// Created by piotrkali on 11/10/22.
//
#include "gtest/gtest.h"
#include "GF.h"
#include "iostream"

using namespace std;
TEST(operator_test, add) {
    GF g1 = GF(14);
    GF g2 = GF(12);
    GF g3 = g1 + g2;
    std::cout << g3.load << std::endl;
    GF g4 = g3 >> 1;
    int x = 26;
    x = x << 1;
    //std::cout << x << std::endl;
    std::cout << g4.load << std::endl;

    //int num = 123400000000;
    //std::cout << sizeof(num) << std::endl;
}