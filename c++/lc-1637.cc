#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        const int len = points.size();
        vector<int> xs(len);

        for(int i = 0; i < len; i++){
            xs[i] = points[i].front();
        }

        sort(xs.begin(), xs.end());
        int result {0};

        for(int i = 0; i < len - 1; i++){
            const int answer = abs(xs[i+1] - xs[i]);
            if (answer != 0){
                result = max(answer, result);
            }
        }

        return result;
    }
};
