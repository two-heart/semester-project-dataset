#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, char>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 'b'));
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    map<char, char> m[it];
    prevent_opt(&m[it / 2]);
    for (int j = 0; j < rand(); j++) {
        m[j/2].insert(make_pair(j, j / 'b'));
    }
    prevent_opt(&m[it / 2]);
    return 0;
}

