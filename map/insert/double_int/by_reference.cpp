#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, int>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 2));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<double, int>* num) {
    (*num)[14.14] = 1;
}

int main() {
    map<double, int> m;
    prevent_opt(&m);
    ins(&m);
    prevent_opt(&m);
    return 0;
}

