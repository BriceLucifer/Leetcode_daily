#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int length = arr.size();
        auto min_abs {INT_MAX};
        for(int i = 1; i < length; i++){
            min_abs = min(min_abs, arr[i] - arr[i-1]);
        }
        vector<vector<int>> result {};

        for(int i = 1; i < length; i++){
            if (arr[i] - arr[i-1] == min_abs) {
                result.push_back({arr[i-1], arr[i]});
            }
        }

        return result;
    }
};
