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
    //std::cout << g3.load << std::endl;
    GF g4 = g3 >> 1;
    int x = 26;
    x = x << 1;
    //std::cout << x << std::endl;
    //std::cout << g4.load << std::endl;
    if (g2 > g1) {
        std::cout<<"ok"<<std::endl;
    }
     GF g = GF(3);
     GF zero = GF(0);
    if (g > zero) {
        std::cout<<"ok"<<std::endl;

    }
    //int num = 123400000000;
    //std::cout << sizeof(num) << std::endl;
}
TEST(operator_test, assign) {
    auto g1 = GF(3);
    auto g2 = g1;
    auto g3 = g2 * g1;
    g3 = g3* GF(2);
    EXPECT_EQ(g3.GF_to_int(), 18);
}

TEST(operator_test, power) {
    auto result = GF(2)^GF(3);
    auto r2 = GF(10)^GF(9);
    EXPECT_EQ(1000000000, r2.GF_to_int());
    EXPECT_EQ(8,result.GF_to_int());
}
TEST(operator_test, stream) {
    auto gf = GF(1234567891);
    cout << gf << endl;
}