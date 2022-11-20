//
// Created by piotrkali on 10/27/22.
//
#include "iostream"
#ifndef GF_GF_H
#define GF_GF_H


class GF {

    static const int range = 1234567891;
    int load;
public:
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
    GF int_to_GF(const int x);
    int GF_to_int();
};


#endif //GF_GF_H
