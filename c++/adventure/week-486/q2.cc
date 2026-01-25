#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        const int length = nums.size();
        if (length == 1) return nums;

        auto array = queue<int>{};
        auto index = vector<int>{};

        for(int i = 0; i < length; i++){
            if (nums[i] >= 0) {
                array.push(nums[i]);
                index.push_back(i);
            }
        }

        if (array.size() == 1 || array.size() == 0) return nums;

        for(int i = 0; i < k % array.size(); i++){
            auto item = array.front();
            array.pop();
            array.push(item);
        }

        for(auto &n: index){
            auto top = array.front(); array.pop();
            nums[n] = top;
        }

        return nums;

    }
};
