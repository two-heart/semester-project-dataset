#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<double>* num) {
    // insert a random number elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    //print a random element into num
    double a = num->at(rand());
    printf("%f", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(double val) {
    printf("%f", val);
}

int main() {
    int it = nolibrand();
    vector<double> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        sink(num.at(nolibrand()));
    }
    prevent_opt(&num);
    return 0;
}

