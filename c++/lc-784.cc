#include <cctype>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(vector<string> &res, string s, int i){
        if (i == s.size()){
            res.push_back(s);
            return ;
        }
        dfs(res, s, i + 1);
        if (isalpha(s[i])) {
            s[i] ^= (1 << 5);
            dfs(res, s, i + 1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        auto res = vector<string>();
        dfs(res, s, 0);
        return res;
    }
};
