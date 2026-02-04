#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int size = nums.size();

        auto result = nums;
        for(int i = 0; i < size; i++){
            if (nums[i] > 0){
                // right go (i + nums[i] % size)
                // 3,-2,1,1
                int index = (i+nums[i]) % size;
                result[i] = nums[index];
            } else if (nums[i] < 0){
                // left go (abs(i + nums[i] % size))
                int index = (size + (i+nums[i]) % size) % size;
                result[i] = nums[index];
            } else {
                result[i] = nums[i];
            }
        }

        return result;

    }
};
