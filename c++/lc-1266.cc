#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        const int rows = points.size();
        const int cols = points.size();
        int times {0};

        for(int i = 1 ; i < rows; i++){
            times += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1] - points[i-1][1]));
        }

        return times;

    }
};
