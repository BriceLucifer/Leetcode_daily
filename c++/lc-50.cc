#include <cstdlib>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;

        // x * x
        long long pows = llabs((long long)n);
        double ans = 1.0;

        // n = C_(k-1)*2^(k-1)
        while (pows != 0) {
            if (pows & 1){
                ans = ans * x;
            }
            x = x * x;
            pows >>= 1;
        }

        return n > 0 ? ans : 1/ans;
    }
};
