#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long happy {0};
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        for(int i = 0; i < k; i++){
            happy += max(0, happiness[i] - i);
        }

        return happy;
    }
};
