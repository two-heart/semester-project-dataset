#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(auto val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, string>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, to_string(j)));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<double, string>* num, const double key, const string val) {
	sink((*num).at(key));
}

int main() {
    // init
    map<double, string> m;
    prevent_opt(&m);
    ins(&m, 14.14, "Hi");
    prevent_opt(&m);
    return 0;
}
