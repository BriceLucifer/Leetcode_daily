#include <algorithm>
#include <vector>

using namespace std;

// overlap: a1|--------|b1          right: min(b1, b2)
//              a2|----------|b2    left: max(a1, a1)
// overlap length is > 0 for right - left
// if overlop is <= 0, then they have no intersection

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        const int len = bottomLeft.size();
        long long ans {0};
        for(int i = 0; i < len; i++){
            for (int j = i+1; j < len; j++){
                const int overlap_x = min(topRight[i][0], topRight[j][0])
                                        - max(bottomLeft[i][0], bottomLeft[j][0]);
                if (overlap_x <= 0) continue;

                const int overlap_y = min(topRight[i][1], topRight[j][1])
                                        - max(bottomLeft[i][1], bottomLeft[j][1]);

                if (overlap_y <= 0) continue;

                if (overlap_x > 0 && overlap_y > 0){
                    const long long rectangle = min<long long>(overlap_x, overlap_y);
                    ans = max(ans, static_cast<long long>(rectangle * rectangle));
                }
            }
        }

        return ans;
    }
};
