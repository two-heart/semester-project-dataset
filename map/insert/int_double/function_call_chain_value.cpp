#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, double>* num) {
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

map<int, double> ins(map<int, double> num, const int key, const double value) {
    num[key] = value;
    return num;
}

map<int, double> D(map<int, double> num, const int key, double value) {
    return ins(num, key / 2, value / 2.2);
}

map<int, double> C(map<int, double> num, const int key, double value) {
    return D(num, key + 2, value + 2.2);
}

map<int, double> B(map<int, double> num, const int key, double value) {
    return C(num, key * 2, value * 2.2);
}

map<int, double> A(map<int, double> num, const int key, double value) {
    return B(num, key + 1, value + 1.2);
}

int main() {
    map<int, double> m;
    prevent_opt(&m);
    m = A(m, 2, 13.37);
    prevent_opt(&m);
    return 0;
}

