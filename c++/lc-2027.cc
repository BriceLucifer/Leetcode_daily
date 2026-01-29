#include <string>

using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        const auto length = s.size();
        auto ans {0};
        for(int i = 0; i < length; i++){
            if (s[i] == 'X'){
                ans += 1;
                i += 2;
            }
        }

        return ans;
    }
};
