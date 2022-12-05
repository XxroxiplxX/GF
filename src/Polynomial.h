//
// Created by piotrkali on 12/3/22.
//

#ifndef GF_POLYNOMIAL_H
#define GF_POLYNOMIAL_H
#include "vector"
#include "math.h"
template <class T>
class Polynomial {


public:
    std::vector<T> coefficients;    //indeks wektora to potega zmiennej,\
    0 na k-tej pozycji oznacza 0=0*x^k
    Polynomial();
    explicit Polynomial(std::vector<T> vector);
    Polynomial<T> operator +(const Polynomial<T>& p);
    Polynomial<T> operator -(const Polynomial<T>& p);
    Polynomial<T> operator *(const Polynomial<T>& p);

    long evaluate(double x);

    //friend std::istream& operator >>(std::istream& is, const Polynomial<T>& p);

};

template<class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T> &p) {
    std::vector<T> v;
    if (this->coefficients.size() > p.coefficients.size()) {
        for (int i = 0; i < p.coefficients.size(); i++) {
            v.push_back(this->coefficients[i] + p.coefficients[i]);
        }
        for (int i = p.coefficients.size(); i < this->coefficients.size(); i++) {
            v.push_back(this->coefficients[i]);
        }
    } else {
        for (int i = 0; i < this->coefficients.size(); i++) {
            v.push_back(this->coefficients[i] + p.coefficients[i]);
        }
        for (int i = this->coefficients.size(); i < p.coefficients.size(); i++) {
            v.push_back(p.coefficients[i]);
        }
    }
    return Polynomial<T>(v);
}

template<class T>
Polynomial<T>::Polynomial() = default;

template<class T>
Polynomial<T>::Polynomial(std::vector<T> vector) : coefficients(vector) {

}

template<class T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T> &p) {
    std::vector<T> v;
    if (this->coefficients.size() > p.coefficients.size()) {
        for (int i = 0; i < p.coefficients.size(); i++) {
            v.push_back(this->coefficients[i] - p.coefficients[i]);
        }
        for (int i = p.coefficients.size(); i < this->coefficients.size(); i++) {
            v.push_back(this->coefficients[i]);
        }
    } else {
        for (int i = 0; i < this->coefficients.size(); i++) {
            v.push_back(this->coefficients[i] - p.coefficients[i]);
        }
        for (int i = this->coefficients.size(); i < p.coefficients.size(); i++) {
            v.push_back(0-p.coefficients[i]);
        }
    }
    return Polynomial<T>(v);
}

template<class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T> &p) {
    std::vector<T> vector = std::vector<T>(this->coefficients.size() + p.coefficients.size()-1, 0);
    for (int i = 0; i < this->coefficients.size(); i++) {
        for (int j = 0; j < p.coefficients.size(); j++) {
            vector[i + j] += p.coefficients[j] * this->coefficients[i];
        }
    }
    return Polynomial<T>(vector);
}

template<class T>
long Polynomial<T>::evaluate(double x) {
    long e = 0;
    for (int i = 0; i < coefficients.size(); i++) {
        e += coefficients[i]*pow(x,i);
    }
    return e;
}

template<class T>
std::ostream &operator<< (std::ostream &os, const Polynomial<T> &p) {
    int i = 1;
    os << p.coefficients[0] << " + ";
    for (; i < p.coefficients.size() - 1; i++) {
        os << p.coefficients[i] << "x^" << i << " + ";
    }
    os << p.coefficients[i+1] << "x^" << i+1;
    return os;
}


#endif //GF_POLYNOMIAL_H
