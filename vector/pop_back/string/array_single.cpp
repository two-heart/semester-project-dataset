#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    string a = num->at(rand());
    printf("%s", a.c_str());
}
int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    vector<string> num[it];
    prevent_opt(&num[it / 2]);
    num[it / 2].pop_back();
    prevent_opt(&num[it / 2]);
    return 0;
}

