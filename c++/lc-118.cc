#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result {};
        vector<int> pre {};
        for (int i = 0; i < numRows; i++){
            vector<int> now {};
            for(int k = 0; k <= i; k++){
                now.push_back(1);
            }
            if (i >= 2) {
                for (int n = 1; n < i; n++){
                    now[n] = pre[n-1] + pre[n];
                }
            }
            result.push_back(now);
            pre = now;
        }
        return result;
    }
};
