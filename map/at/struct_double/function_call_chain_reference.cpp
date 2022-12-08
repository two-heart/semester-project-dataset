#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

void __attribute__ ((noinline)) sink(double val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<xy, char>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, j / 13.37));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<xy, char>* num, const xy key, const char value) {
	sink((*num).at(key));
}

void D(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x / 2, key.y / 2};
    ins(num, t, value / 13.37);
}

void C(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    D(num, t, value + 13.37);
}

void B(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    C(num, t, value * 13.37);
}

void A(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    B(num, t, value + 13.37);
}

int main() {
    xy t = {1, 2};
    map<xy, char> m;
    prevent_opt(&m);
    A(&m, t, 13.37);
    prevent_opt(&m);
    return 0;
}

