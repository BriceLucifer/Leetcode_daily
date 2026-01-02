#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> map{};
        for(const auto& n: nums){
            map[n] += 1;
        }

        for(const auto& [x, y]: map){
            if (y > 1){
                return y;
            }
        }
        return nums.back();
    }
};
