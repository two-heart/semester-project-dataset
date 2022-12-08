#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, xy>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(j, t));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second.x << it->second.y << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<char, xy> ins(map<char, xy> num, const char key, const xy value) {
    num.erase(key);
    return num;
}

map<char, xy> D(map<char, xy> num, const char key, xy value) {
    value.x = value.x / 2;
    value.y = value.y / 2;
    return ins(num, key / 2, value);
}

map<char, xy> C(map<char, xy> num, const char key, xy value) {
    value.x = value.x + 2;
    value.y = value.y + 2;
    return D(num, key + 2, value);
}

map<char, xy> B(map<char, xy> num, const char key, xy value) {
    value.x = value.x * 2;
    value.y = value.y * 2;
    return C(num, key * 2, value);
}

map<char, xy> A(map<char, xy> num, const char key, xy value) {
    value.x = value.x + 1;
    value.y = value.y + 1;
    return B(num, key + 1, value);
}

int main() {
    xy t = {1, 2};
    map<char, xy> m;
    prevent_opt(&m);
    m = A(m, 'a', t);
    prevent_opt(&m);
    return 0;
}

