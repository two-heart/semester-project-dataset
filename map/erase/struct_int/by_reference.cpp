#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<xy, char>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, j / 137));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<xy, char>* num) {
    xy t = {1, 2};
    (*num).erase(t);
}

int main() {
    map<xy, char> m;
    prevent_opt(&m);
    ins(&m);
    prevent_opt(&m);
    return 0;
}

