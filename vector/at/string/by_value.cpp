#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

vector<string> ins(vector<string> num) {
    num.at(1);
    return num;
}

void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    //print a random element into num
    string a = num->at(rand());
    printf("%s", a.c_str());
}

int main() {
    vector<string> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}

