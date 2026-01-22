#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         unordered_map<int, int> map{};
//         for (auto &c: nums){
//             map[c] += 1;
//         }
//         auto result {0};

//         for(auto &[_, value]: map){
//             // 组合树 C(n, 2)
//             result += value * (value - 1) / 2;
//         }

//         return result;
//     }
// };
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map{};
        auto result {0};
        for(int i = 0; i < nums.size(); i++){
            if (map.contains(nums[i])){
                result += map[nums[i]];
            }
            map[nums[i]] += 1;
        }

        return result;
    }
};
