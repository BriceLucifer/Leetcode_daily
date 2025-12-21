#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<string> a(n); // 最终得到的字符串数组
        int ans = 0;
        for (int j = 0; j < m; j++) {
            bool del = false;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] + strs[i][j] > a[i + 1] + strs[i + 1][j]) {
                    // j 列不是升序，必须删
                    ans++;
                    del = true;
                    break;
                }
            }
            if (!del) {
                // j 列是升序，不删更好
                for (int i = 0; i < n; i++) {
                    a[i] += strs[i][j];
                }
            }
        }
        return ans;
    }
};


int main(){
    auto strs = vector<string>{"xc","yb","za"};
    auto s = Solution().minDeletionSize(strs);
    cout << s << '\n';
}
