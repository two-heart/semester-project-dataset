#include <iostream>
#include <map>
#include <string>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, int>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(to_string(j), j / 2));
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    map<string, int> m[it];
    prevent_opt(&m[it / 2]);
    for (int j = 0; j < rand(); j++) {
        m[j/2].insert(make_pair(to_string(j), j / 2));
    }
    prevent_opt(&m[it / 2]);
    return 0;
}

