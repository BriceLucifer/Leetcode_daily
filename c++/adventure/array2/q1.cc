#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> maps ;
        for (int i = 1; i <= nums.size(); ++i) {
            maps[i] = 0;
        }

        for (auto i: nums) {
            maps[i] += 1;
        }

        int sub, miss;
        for (auto element: maps) {
            if (element.second == 2) {
                sub = element.first;
            }

            if (element.second == 0) {
                miss = element.first;
            }
        }

        return {sub, miss};
    }
};


int main(){
    auto nums = vector<int>{1, 1};
    auto s = Solution();
    auto result = s.findErrorNums(nums);

    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}
