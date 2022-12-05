//
// Created by piotrkali on 10/27/22.
//
#include "iostream"
#ifndef GF_GF_H
#define GF_GF_H


class GF {


    long long load;
    int ex_gcd(int a, int b, int *x, int *y);
public:
    static const int range = 1234577;
    GF();
    GF(long long load);
    GF(const GF& gf);
    ~GF();
    GF operator +(const GF& g);
    GF operator -(const GF& g);
    GF operator *(const GF& g);
    GF operator /(const GF& g);
    GF operator %(const GF& g);
    GF operator ^(const GF& g);
    bool operator ==(const GF& g);
    bool operator <(const GF& g);
    bool operator <=(const GF& g);
    bool operator >=(const GF& g);
    bool operator >(const GF& g);
    GF operator <<(const GF& g);
    GF operator >>(const GF& g);
    GF operator <<(int x);
    GF operator >>(int x);
    friend std::ostream& operator <<(std::ostream& os, const GF& g);
    friend std::istream& operator >>(std::istream& is, const GF& g);
    int GF_to_int();
};


#endif //GF_GF_H
