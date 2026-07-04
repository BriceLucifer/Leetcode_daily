#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        auto result = vector<vector<int>>();
        auto pre = vector<int>();
        //    1
        //   1 1
        //  1 2 1
        // 1 3 3 1
        // 1 4 6 4 1

        for(int i = 0; i < numRows; i++){
            // loop now -> pre
            auto now = vector<int>{};
            for(int j = 0; j <= i; j++){
                now.push_back(1);
            }
            if (i >= 2){
                for(int n = 1; n < i; n++){
                    now[n] = pre[n] + pre[n-1];
                }
            }
            pre = now;
            result.push_back(now);
        }

        return result;
    }
};
