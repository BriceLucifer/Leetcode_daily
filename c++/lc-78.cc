#include <vector>

using namespace std;

// using dfs is the best

class Solution {
public:
    void backtrace(vector<vector<int>>& result, vector<int>& nums, int i){
        if (i >= nums.size()) return;

        if (result.empty()){
            result.push_back({nums[i]});
            result.push_back({});
        }else{
            int n = result.size();
            for(int z = 0; z < n; z++){
                auto temp = result[z];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }

        backtrace(result, nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // nums = [1,2,3]
       // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
       vector<vector<int>> result {};
       if (nums.empty()){
           return {{}};
       }

       backtrace(result, nums, 0);

       return result;
    }
};
