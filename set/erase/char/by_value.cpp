#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (char c : *num) {
        cout << c << endl;
    }
}

set<char> ins(set<char> num) {
    num.erase('A');
    return num;
}

int main() {
    set<char> num;
    prevent_opt(&num);
    ins(num);
    prevent_opt(&num);
    return 0;
}
