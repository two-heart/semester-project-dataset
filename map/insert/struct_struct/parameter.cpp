#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<xy, xy>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, t));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second.x << it->second.y << endl;
    }
}

void ins(map<xy, xy>* num, const xy key, const xy val) {
    (*num)[key] = val;
}

int main() {
    xy t = {1, 2};
    map<xy, xy> m;
    prevent_opt(&m);
    ins(&m, t, t);
    prevent_opt(&m);
    return 0;
}

