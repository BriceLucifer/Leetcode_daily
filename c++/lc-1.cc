#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map{};
        vector<int> result{};
        for(int i = 0; i < nums.size(); i++){
            if (map.contains(target - nums[i])){
                result.push_back(map[target - nums[i]]);
                result.push_back(i);
            } else {
                map[nums[i]] = i;
            }
        }

        return result;

    }
};

// 左hashmap负责：插入和查询
// 右面枚举和检测
