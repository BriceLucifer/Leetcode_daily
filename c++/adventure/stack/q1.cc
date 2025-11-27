#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        string push {"Push"};
        string pop {"Pop"};

        int size = target.size();

        int i = 1;
        for (auto &x: target) {
            if (x == i) {
                result.push_back(push);
                i += 1;
            } else {
                while (i != x) {
                    result.push_back(push);
                    result.push_back(pop);
                    i += 1;
                }
                result.push_back(push);
                i += 1;
            }
        }

        return result;
    }
};

int main() {
    auto nums = vector<int>{1,2};
    auto n = 3;

    auto s = Solution();
    auto result = s.buildArray(nums, n);
    for (auto x: result) {
        cout << x << " ";
    }
    cout << "\n";
}
