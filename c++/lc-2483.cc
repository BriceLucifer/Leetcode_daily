#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        // 即求i使得[0,i-1]中"N"与[i,n-1]中"Y"数量和最少
        int n = customers.length();
        vector<int> prefix(n + 1), suffix(n + 1);
        prefix[0] = 0; suffix[n] = 0;
        suffix[n - 1] = (int)(customers.back() == 'Y');
        for(int i = 1; i < n; ++i) {
            if(customers[i - 1] == 'N') prefix[i] = prefix[i - 1] + 1;
            else prefix[i] = prefix[i - 1];

            if(customers[n - i - 1] == 'Y') suffix[n - i - 1] = suffix[n - i] + 1;
            else suffix[n - i - 1] = suffix[n - i];
        }
        prefix[n] = (int)(customers.back() == 'N') + prefix[n - 1];
        int cmp = INT_MAX, idx = -1;
        for(int i = 0; i <= n; ++i) {
            int tmp = suffix[i] + prefix[i];
            if(tmp < cmp) {
                cmp = tmp;
                idx = i;
            }
        }
        return idx;
    }
};
