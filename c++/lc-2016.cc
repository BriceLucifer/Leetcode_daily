class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        auto minItem = nums[0];
        auto diff = 0;
        for(int i = 0; i < nums.size(); i++){
            minItem = min(minItem, nums[i]);
            diff = max(diff, nums[i] - minItem);
        }
        return diff == 0 ? -1 : diff;
    }
};
