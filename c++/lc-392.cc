#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
         * s = "abc", t = "ahbgdc"
         * Output: true
         */
        auto i = 0;
        auto j = 0;

        for(; j < t.length(); j++){
            if (i < s.length() && s[i] == t[j]){
                i += 1;
            }
        }

        return i == s.length();
    }
};
