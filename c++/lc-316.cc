#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(256, 0);
        vector<bool> in_stack(256, 0);
        for(auto &c: s) cnt[c] += 1;

        string stack {};
        for(auto &c: s){
            cnt[c]--;

            if (in_stack[c]) continue;
            while (!stack.empty() && stack.back() > c && cnt[stack.back()] > 0) {
                in_stack[stack.back()] = false;
                stack.pop_back();
            }

            stack.push_back(c);
            in_stack[c] = true;
        }

        return stack;
    }
};

int main(){
    auto s = Solution().removeDuplicateLetters("cbacdcbc");
    cout << s << '\n';
}
