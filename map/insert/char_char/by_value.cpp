#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, char>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<char, char> ins(map<char, char> num) {
    num['a'] = 'c';
    return num;
}

int main() {
    // init
    map<char, char> m;
    prevent_opt(&m);
    m = ins(m);
    prevent_opt(&m);
    return 0;
}
