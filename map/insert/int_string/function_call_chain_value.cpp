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

map<int, string> ins(map<int, string> num, const int key, const string value) {
    num[key] = value;
    return num;
}

map<int, string> D(map<int, string> num, const int key, string value) {
    return ins(num, key / 2, value + "A");
}

map<int, string> C(map<int, string> num, const int key, string value) {
    return D(num, key + 2, value + "A");
}

map<int, string> B(map<int, string> num, const int key, string value) {
    return C(num, key * 2, value + "A");
}

map<int, string> A(map<int, string> num, const int key, string value) {
    return B(num, key + 1, value + "A");
}

int main() {
    // init
    map<int, string> m;
    prevent_opt(&m);
    m = A(m, 2, "Hi");
    prevent_opt(&m);
    return 0;
}

