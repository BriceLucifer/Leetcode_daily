#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
/*
 * 骚操作
 * count_odds -> (0~high)的odd - (0~low-1)的odd
 * 0～n的odd是(n + 1) / 2
 */

int main(){
    auto s = Solution() ;
    auto result = s.countOdds(8, 10);
    cout << result << '\n';
}
