#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, string>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, to_string(j)));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<int, string> ins(map<int, string> num) {
    num[2] = "Hi";
    return num;
}

int main() {
    // init
    map<int, string> m;
    prevent_opt(&m);
    m = ins(m);
    prevent_opt(&m);
    return 0;
}

