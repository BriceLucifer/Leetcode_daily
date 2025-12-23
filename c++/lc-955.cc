#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        /*
         * a[i] represents the prefix of strs[i]
         * formed by the columns we decided to keep so far.
         *
         * Invariant:
         *   a[0] <= a[1] <= ... <= a[n-1]  (lexicographical order)
         *
         * This is the compressed DP state.
         */
        vector<string> a(n, "");

        int deletions = 0;

        // Process columns from left to right
        for (int col = 0; col < m; col++) {
            bool must_delete = false;

            /*
             * Try to keep the current column.
             * We check whether appending this column
             * would break the lexicographical order.
             *
             * Only adjacent strings matter because
             * lex order is transitive.
             */
            for (int i = 0; i < n - 1; i++) {
                // Compare prefixes + current character
                if (a[i] + strs[i][col] > a[i + 1] + strs[i + 1][col]) {
                    // Order would be violated -> irreversible
                    must_delete = true;
                    break;
                }
            }

            if (must_delete) {
                // This column cannot be kept under any circumstance
                deletions++;
            } else {
                // Safe to keep: update DP state (prefixes)
                for (int i = 0; i < n; i++) {
                    a[i].push_back(strs[i][col]);
                }
            }
        }

        return deletions;
    }
};



int main(){
    auto strs = vector<string>{"xc","yb","za"};
    auto s = Solution().minDeletionSize(strs);
    cout << s << '\n';
}
