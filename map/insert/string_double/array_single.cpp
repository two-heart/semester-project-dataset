#include <iostream>
#include <map>
#include <string>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, double>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(to_string(j), j / 2.0));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    map<string, double> m[it];
    prevent_opt(&m[it / 2]);
    m[it / 2]["Hello World"] = 13.37;
    prevent_opt(&m[it / 2]);
    return 0;
}

