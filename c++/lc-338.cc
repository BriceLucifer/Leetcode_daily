#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        auto nums {0};
        vector<int> ans(n + 1);
        for(int i = 0; i <= nums; i++){
            if (i % 2 == 0){
                ans[i] = ans[i/2];
            } else {
                ans[i] = ans[i/2] + 1;
            }
        }
    }
};
