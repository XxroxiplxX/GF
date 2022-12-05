#include <iostream>
#include "GF.h"

using namespace std;
int main(int argc, char** argv) {
    auto g = (GF(1)/GF(2))*(GF(1)/GF(2));
    auto c = GF(2)^GF(-2);
    cout << g << endl;

    cout << c << endl;


    return 0;
}
