#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size * 2, 0);

        for(int i = 0; i < size; i++){
            result[i] = nums[i];
            result[i + size] = result[i];
        }

        return result;
    }
};
