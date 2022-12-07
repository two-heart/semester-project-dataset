#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, double>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 2.0));
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    // init
    int it = nolibrand();
    map<int, double> m[it];
    prevent_opt(&m[it / 2]);
    for (int j = 0; j < rand(); j++) {
        // opt init
        m->insert(make_pair(j, j / 2.0));
    }
    prevent_opt(&m[it / 2]);
    return 0;
}
