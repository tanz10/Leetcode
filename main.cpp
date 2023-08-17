#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        size_t size = n + 1;
        int catched[size];
        vector<int> result;
        for (int i = 0; i < size; i++) {
            catched[i] = 0;
        }
        int i = 1;
        int round = 1;
        while (1) {
            cout << i << ' ' << endl;
            catched[i] += 1;
            if (catched[i] == 2) {
                break;
            }
            i += k * round;
            round++;
            i % n != 0 ? i %= n: i = n;
        }

        for (int i = 1; i < size; i++) {
            if (catched[i] == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> res = solution.circularGameLosers(5, 3);
    for (auto r: res) {
        cout << r << ' ';
    }
    return 0;
}
