//
// Created by piotrkali on 10/27/22.
//

#include "GF.h"

GF::GF() :load(0) {

}

GF::GF(long long int load) :load(load) {

}

GF::GF(const GF &gf) {
    this->load = gf.load;
}

GF::~GF() {
    std::cout << "deleted" << std::endl;
}

GF GF::operator+(const GF &g) {
    return GF((this->load + g.load)%range);
}

GF GF::operator-(const GF &g) {
    return GF((this->load - g.load)%range);
}

GF GF::operator*(const GF &g) {
    return GF((this->load * g.load)%range);
}

GF GF::operator/(const GF &g) {
    return GF();
}

GF GF::operator^(const GF &g) {
    GF result = GF(1);

    return GF();
}

GF GF::operator==(const GF &g) {
    return GF();
}

GF GF::operator<(const GF &g) {
    return GF();
}

GF GF::operator<=(const GF &g) {
    return GF();
}

GF GF::operator>=(const GF &g) {
    return GF();
}

GF GF::operator>(const GF &g) {
    return GF();
}

GF GF::operator<<(const GF &g) {
    return GF();
}

GF GF::operator>>(const GF &g) {
    return GF();
}

GF GF::int_to_GF(const int x) {
    return GF();
}

int GF::GF_to_int(const GF g) {
    return 0;
}

GF GF::operator%(const GF &g) {
    return GF(this->load%g.load);
}

GF GF::operator<<(int x) {
    return GF(this->load << x);
}

GF GF::operator>>(int x) {
    return GF(this->load >> x);
}
