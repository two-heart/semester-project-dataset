#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) sink(char val) {
    printf("%c", val);
}

vector<char> ins(vector<char> num) {
    sink(num.at(1));
    return num;
}

void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    char a = num->at(rand());
    printf("%c", a);
}

int main() {
    vector<char> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}

