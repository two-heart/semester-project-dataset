#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, char>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 'b'));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    map<int, char> m;
    prevent_opt(&m);
    for (int j = 0; j < rand(); j++) {
        m.erase((j / 7 + 8) * 9);
    }
    prevent_opt(&m);
    return 0;
}

