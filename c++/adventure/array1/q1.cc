#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result = nums;
        result.reserve(nums.size() * 2);
        for (auto y: nums) {
            result.push_back(y);
        }
        return result;
    }
};
