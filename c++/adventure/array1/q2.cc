#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;

        for(auto i = 0; i < n ; ++i){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }

        return result;
    }
};

int main(){
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;

    auto s = Solution();
    auto r = Solution().shuffle(nums, n);

    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << " ";
    }

    return 0;
}
