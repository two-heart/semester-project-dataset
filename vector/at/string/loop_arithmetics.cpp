#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    // insert a random number elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    //print a random element into num
    string a = num->at(rand());
    printf("%s", a.c_str());
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(string val) {
    printf("%s", val.c_str());
}

int main() {
    int it = nolibrand();
    vector<string> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        int a = i + it - it / 2 - 2;
        sink(num.at(a));
    }
    prevent_opt(&num);
    return 0;
}
