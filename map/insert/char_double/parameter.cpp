#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, double>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 2.0));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<char, double>* num, const char key, const double val) {
    (*num)[key] = val;
}

int main() {
    map<char, double> m;
    prevent_opt(&m);
    ins(&m, 'a', 13.37);
    prevent_opt(&m);
    return 0;
}

