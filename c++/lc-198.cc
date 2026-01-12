#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums){
        const int len = nums.size();
        pair<int, int> state {0, 0};

        for(int i = 0; i < len; i++){
            int new_choose = state.first + nums[i];
            int new_nochoose = max(state.second, state.first);

            state.second = new_choose;
            state.first = new_nochoose;
        }

        return max(state.first, state.second);
    }
};
