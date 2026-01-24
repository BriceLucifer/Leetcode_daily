#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int length = nums.size();

        auto maxReach {0};
        auto time {0};
        auto currentEnd {0};


        for(int i = 0; i < length - 1; i++){
            maxReach = max(maxReach, i + nums[i]);

            if (i == currentEnd){
                time ++;
                currentEnd = maxReach;
            }
        }

        return time;
    }
};
