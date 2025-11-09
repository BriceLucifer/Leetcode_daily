#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        auto length {0};

        if (nums.size() == 0) {
            return length;
        }

        std::map<int, int> n {};
        for (int num: nums) {
            n[num] += 1;
        }
        for (auto &[key, value]: n){
            if (value >= 2) {
                nums[length] = key;
                nums[length+1] = key;
                length += 2;
            } else {
                nums[length] = key;
                length += 1;
            }
        }

        return length;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    Solution s{};
    cout << s.removeDuplicates(nums) << endl;
}
