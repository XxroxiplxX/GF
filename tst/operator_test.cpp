//
// Created by piotrkali on 11/10/22.
//
#include "gtest/gtest.h"
#include "GF.h"
#include "iostream"
#include "math.h"

using namespace std;
TEST(operator_test, basic_operands) {
    GF g1 = GF(14);
    GF g2 = GF(12);
    GF g3 = g1 + g2;
    //std::cout << g3.load << std::endl;
    GF g4 = g3 >> 1;
    EXPECT_TRUE(g1 > g2);
    EXPECT_FALSE(g1 < g2);
    EXPECT_TRUE(GF(26) == g3);

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
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 6; j++) {
            auto x = GF(i)^GF(j);
            EXPECT_EQ(x.GF_to_int(), (long long) pow((double) i, (double ) j));
            //cout << x << endl;
        }
    }
}
TEST(operator_test, stream) {
    auto gf = GF(1234567890);
    cout << "Galois field's element: " << gf << endl;
}
TEST(operator_test, division) {
    try {
        auto r = GF(3)/0;
    } catch (const char* msg) {
        cerr << msg << endl;
    }
}
TEST(operator_test, init) {
    try {
        auto g = GF(1234567899999);
    } catch (const char*msg) {
        cerr << msg << endl;
    }
}
