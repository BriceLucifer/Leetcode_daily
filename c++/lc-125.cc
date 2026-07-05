#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	// dealing with upper and lower case string
    	// the idea is to select the alphabatic then convert the upper case to lowwer case and choose the number
    	auto begin = 0;
    	int end = s.length() - 1;
        for(; begin < end; ){
            if (!isalnum(s[begin])) {
                begin ++;
                continue;
            }

            if (!isalnum(s[end])) {
                end --;
                continue;
            }

            auto c1 = tolower(s[begin]);
            auto c2 = tolower(s[end]);
            if (c1 != c2){
                return false;
            }
            begin++, end--;
        }

        return true;

    }
};
