//
// Created by piotrkali on 12/3/22.
//

#ifndef GF_POLYNOMIAL_H
#define GF_POLYNOMIAL_H
#include "vector"
#include "math.h"
#include <algorithm>
#include <iostream>
template <class T>
class Polynomial {

    void populate_with_zeros(int p, int q);
public:
    std::vector<T> coefficients;    //indeks wektora to potega zmiennej,\
    0 na k-tej pozycji oznacza 0=0*x^k
    Polynomial(T zero_flag);
    Polynomial(int size, T zero_flag);
    explicit Polynomial(std::vector<T> vector, T zero_flag);
    Polynomial(const Polynomial<T>& polynomial);
    Polynomial<T> operator +(const Polynomial<T>& p);
    Polynomial<T> operator -(const Polynomial<T>& p);
    Polynomial<T> operator *(const Polynomial<T>& p);
    Polynomial<T> operator /(const Polynomial<T>& p);
    Polynomial<T> operator %(const Polynomial<T>& p);
    bool operator ==(const Polynomial<T>& p);
    bool operator !=(const Polynomial<T>& p);
    long evaluate(double x);
    T zero_flag;
    void clean();
    //friend std::istream& operator >>(std::istream& is, const Polynomial<T>& p);

};
template<class T>
bool Polynomial<T>::operator ==(const Polynomial<T>& p) {
    if (this->coefficients.size() != p.coefficients.size()) {
        return false;
    }
    for (int i = 0; i < this->coefficients.size(); i++) {
        if (this->coefficients[i] != p.coefficients[i]) {
            return false;
        }
    }
    return true;
}
template<class T>
bool Polynomial<T>::operator !=(const Polynomial<T>& p) {
    if (this->coefficients.size() != p.coefficients.size()) {
        return true;
    }
    
    for (int i = 0; i < this->coefficients.size(); i++) {
        if (this->coefficients[i] != p.coefficients[i]) {
            return true;
        }
    }
    return false;
}
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
    return Polynomial<T>(v, zero_flag);
}

template<class T>
Polynomial<T>::Polynomial(T zero_flag) : zero_flag(zero_flag){}

template<class T>
Polynomial<T>::Polynomial(std::vector<T> vector, T zero_flag) : coefficients(vector), zero_flag(zero_flag) {

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
    return Polynomial<T>(v, zero_flag);
}

template<class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T> &p) {
    std::vector<T> vector = std::vector<T>(this->coefficients.size() + p.coefficients.size()-1, 0);
    for (int i = 0; i < this->coefficients.size(); i++) {
        for (int j = 0; j < p.coefficients.size(); j++) {
            vector[i + j] += p.coefficients[j] * this->coefficients[i];
        }
    }
    return Polynomial<T>(vector, zero_flag);
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
Polynomial<T> Polynomial<T>::operator/(const Polynomial<T> &q) {
    std::vector<T> dividend = this->coefficients;
    std::reverse(dividend.begin(), dividend.end());
    std::vector<T> divisor = q.coefficients;
    std::reverse(divisor.begin(), divisor.end());
    std::vector<T> quotient;
	quotient = dividend;
    
	int normalizer = divisor[0];
	
	for (int i = 0; i < dividend.size() - (divisor.size() - 1); i++)
	{
		quotient[i] /= normalizer;
		int coef = quotient[i];

		if (coef != 0) 
		{
			for (int j = 1; j < divisor.size(); j++)
			{
				quotient[i + j] += -divisor[j] * coef;
			}
        }

	}
    int s = quotient.size();
    for (int i = s-1; i > s - divisor.size(); i--) {
        quotient.pop_back();
    }
    std::reverse(quotient.begin(), quotient.end());
    for (auto it : quotient) {
        std::cout << it << " ";
    }
    std::cout << "\n";
        return Polynomial<T>(quotient, zero_flag);

}
template<class T>
Polynomial<T>Polynomial<T>::operator %(const Polynomial<T>& p) {
    std::vector<T> dividend = this->coefficients;
    std::reverse(dividend.begin(), dividend.end());
    std::vector<T> divisor = p.coefficients;
    std::reverse(divisor.begin(), divisor.end());
    std::vector<T> quotient;
	quotient = dividend;
    
	int normalizer = divisor[0];
	
	for (int i = 0; i < dividend.size() - (divisor.size() - 1); i++)
	{
		quotient[i] /= normalizer;
		int coef = quotient[i];

		if (coef != 0) 
		{
			for (int j = 1; j < divisor.size(); j++)
			{
				quotient[i + j] += -divisor[j] * coef;
			}
        }

	}
    std::vector<T> remainder;
    int s = quotient.size();
    for (int i = s-1; i > s - divisor.size(); i--) {
        
        remainder.push_back(quotient[i]);
    }
    
        return Polynomial<T>(remainder, zero_flag);
}
template<class T>
Polynomial<T>::Polynomial(int size, T zero_flag) : zero_flag(zero_flag) {
    coefficients = std::vector<T>(size);
}

template<class T>
void Polynomial<T>::populate_with_zeros(int p, int q) {
    for (int i = p; i <= q; i++) {
        coefficients[i] = zero_flag;
    }
}

template<class T>
Polynomial<T>::Polynomial(const Polynomial<T> &polynomial) {
    this->zero_flag = polynomial.zero_flag;
    for (int i = 0; i < polynomial.coefficients.size(); i++) {
        this->coefficients.push_back(polynomial.coefficients[i]);
    }
}

template<class T>
void Polynomial<T>::clean() {
    int i = coefficients.size() - 1;
    while (coefficients[i] == zero_flag) {
        coefficients.pop_back();
        i--;
    }
}

template<class T>
std::ostream &operator<< (std::ostream &os, const Polynomial<T> &p) {
    int i = 1;
    os << p.coefficients[0] << " + ";
    for (; i < p.coefficients.size() - 1; i++) {
        os << p.coefficients[i] << "x^" << i << " + ";
    }
    os << p.coefficients[i] << "x^" << i;
    return os;
}


#endif //GF_POLYNOMIAL_H
