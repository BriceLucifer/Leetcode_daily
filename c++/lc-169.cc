
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map{};
        for(auto &item: nums){
            map[item] += 1;
        }
        auto result = 0;
        auto times = 0;
        for(auto &item: map){
            if (item.second > times){
                result = item.first;
                times = item.second;
            }
        }

        return result;
    }
};
