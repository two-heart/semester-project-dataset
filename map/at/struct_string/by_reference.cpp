#include <iostream>
#include <map>
#include <string>

void __attribute__ ((noinline)) sink(std::string val) {
    std::cout << val << std::endl;
}


using namespace std;
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

void __attribute__ ((noinline)) prevent_opt(map<xy, string>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<xy, string>* num) {
    xy t = {1, 2};
	sink((*num).at(t));
}

int main() {
    map<xy, string> m;
    prevent_opt(&m);
    ins(&m);
    prevent_opt(&m);
    return 0;
}

