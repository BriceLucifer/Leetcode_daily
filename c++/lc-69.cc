
#include <cstdlib>
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        // x_(n+1) = 1 / 2 (x_n + a / x_n)
        double root = static_cast<double>(x);
        while (abs(x - root * root) > 1e-5) {
            root = (x / root + root) / 2.0;
        }
        return root;
    }
};
