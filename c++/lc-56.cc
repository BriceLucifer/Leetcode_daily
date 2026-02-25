#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(
        vector<vector<int>>& intervals
    ) {
        vector<vector<int>> result;
        int size = intervals.size();
        result.reserve(size);

        // sort it
        sort(intervals.begin(), intervals.end());

        // we need a left untill it can not do it anymore
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < size; i++){
            if (intervals[i][0] <= right) {
                // right update
                right = max(intervals[i][1], right);
            } else {
                result.push_back({left, right});
                // updat left to the new element of the left
                left = intervals[i][0];
                // same here
                right = intervals[i][1];
            }
        }

        result.push_back({left, right});
        return result;
    }
};
