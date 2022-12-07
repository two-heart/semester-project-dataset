#include <iostream>
#include <map>
#include <string>// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, char>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<string, char> ins(map<string, char> num, const string key, const char value) {
    num[key] = value;
    return num;
}

map<string, char> D(map<string, char> num, const string key, char value) {
    return ins(num, key / "Hello World" value / 'b');
}

map<string, char> C(map<string, char> num, const string key, char value) {
    return D(num, key + "Hello World" value + 'b');
}

map<string, char> B(map<string, char> num, const string key, char value) {
    return C(num, key * "Hello World" value * 'b');
}

map<string, char> A(map<string, char> num, const string key, char value) {
    return B(num, key + "Hello World" value + 'b');
}

int main() {
    // init
    map<string, char> m;
    prevent_opt(&m);
    m = A(m, "Hello World", 'c');
    prevent_opt(&m);
    return 0;
}

