//
// Created by piotrkali on 12/3/22.
//
#include "gtest/gtest.h"

#include "iostream"
#include "Polynomial.h"
#include "vector"
using namespace std;
TEST(Polynomial_test, basic_operands) {
    vector<int> v1 = {1,2,3,4};
    vector<int> v2 = {1,2,3,4,5,6};
    auto p1 = Polynomial<int>(v1,0);
    auto p2 = Polynomial<int>(v2,0);
    auto p3 = p1 + p2;
    for (auto item : p3.coefficients) {
        cout << item << endl;
    }
    auto p4 = p1*p2;
    EXPECT_EQ(p4.coefficients.size(), 10);
}
TEST(Polynomial_test, multiply) {
    vector<int> v1 = {4,3,1};
    vector<int> v2 = {-1,8,-2,4};
    auto p1 = Polynomial<int>(v1,0);
    auto p2 = Polynomial<int>(v2,0);
    auto p3 = p1*p2;
    vector<int> control = {-4,29,15,18,10,4};
    EXPECT_EQ(p3.coefficients, control);
    cout << p3;
}
TEST(Polynomial_test, vec) {
    vector<int> v1 = {1,1,1,0,1,0,1,1};
    vector<int> v2 = {1,1,0,1};
    auto p1 = Polynomial<int>(v1,0);
    auto p2 = Polynomial<int>(v2,0);
    auto p3 = p1 % p2;
    cout << p3 << endl;
}