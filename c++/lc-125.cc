#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // 先处理大小写
        string ss {};

        for(auto &c: s){
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                auto cc = c;
                if (cc >= 'A' && cc <= 'Z'){
                    cc |= (1 << 5);
                }
                ss.push_back(cc);
            }

            if (c >= '0' && c <= '9'){
                ss.push_back(c);
            }
        }

        bool result = true;

        const int len = ss.size();
        for(int i = 0, j = len - 1; i < j; i++, j--){
            if (ss[i] != ss[j]) {
                result = false;
                break;
            }
        }

        return result;
    }
};
