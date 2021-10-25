#include <vector>
#include <unordered_map>
#include <iostream>
#include <random>


using namespace std;

class RandomizedSet {
public:

    RandomizedSet() {
    }

    bool insert(int val) {
        if (pos.find(val) == pos.end()) {
            vec.push_back(val);
            pos[val] = vec.size() - 1;
            return true;
        } else {
            return false;
        }
    }

    // vec: 5, 2, 3, 1, 4
    // pos: 0, 1, 2, 3, 4
    // remove 3
    // vec: 5, 2, 4, 1, 3
    // pos: 0, 1, 2, 3, 4
    bool remove(int val) {
        if (pos.find(val) == pos.end()) {
            return false;
        } else {
            pos[vec.back()] = pos[val];      // pos[4] = 2
            vec[pos[val]] = vec.back();      // vec[2] = 4
            vec.pop_back();
            pos.erase(val);
            return true;
        }
    }

    // void debug() {
    //     cout << "vec: ";
    //     for (const auto v: vec) cout << v << " ";
    //     cout << endl;

    //     cout << "pos: " << endl;
    //     for (const auto &[v, i]: pos) cout << v << ", " << i << endl;
    // }

    int getRandom() {
        return vec[random() % vec.size()];
    }

private:
    unordered_map<int, int> pos;
    vector<int> vec;
};

int main() {
    RandomizedSet s;
    s.insert(5);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.remove(3);
    s.debug();
    return 0;
}
