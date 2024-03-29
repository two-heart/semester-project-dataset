#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, double>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 2.0));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<double, double>* num, const double key, const double value) {
    (*num).erase(key);
}

void D(map<double, double>* num, const double key, double value) {
    ins(num, key / 2.6, value / 2.2);
}

void C(map<double, double>* num, const double key, double value) {
    D(num, key + 2.6, value + 2.2);
}

void B(map<double, double>* num, const double key, double value) {
    C(num, key * 2.6, value * 2.2);
}

void A(map<double, double>* num, const double key, double value) {
    B(num, key + 1.6, value + 1.2);
}

int main() {
    map<double, double> m;
    prevent_opt(&m);
    A(&m, 14.14, 13.37);
    prevent_opt(&m);
    return 0;
}

