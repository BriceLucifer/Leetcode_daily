#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map{};
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] += 1;
        }

        if (map.size() == nums.size()) return false;
        return true;
    }
};
