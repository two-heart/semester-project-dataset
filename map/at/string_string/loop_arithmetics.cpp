#include <iostream>
#include <map>
#include <string>

void __attribute__ ((noinline)) sink(std::string val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, string>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(to_string(j), to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    map<string, string> m;
    prevent_opt(&m);
    for (int j = 0; j < rand(); j++) {
	sink(m.at(to_string(j) + "asdf"));
    }
    prevent_opt(&m);
    return 0;
}

