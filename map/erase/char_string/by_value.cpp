#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, string>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<char, string> ins(map<char, string> num) {
    num.erase('a');
    return num;
}

int main() {
    map<char, string> m;
    prevent_opt(&m);
    m = ins(m);
    prevent_opt(&m);
    return 0;
}

