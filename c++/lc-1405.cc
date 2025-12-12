#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> heap;
        if (a > 0) heap.push({a, 'a'});
        if (b > 0) heap.push({b, 'b'});
        if (c > 0) heap.push({c, 'c'});

        string res = "";
        while (!heap.empty()) {
            auto [count1, char1] = heap.top();
            heap.pop();

            bool can_use1 = true;
            if (res.size() >= 2 && res[res.size() - 1] == char1 && res[res.size() - 2] == char1){
                can_use1 = false;
            }

            if (can_use1){
                res.push_back(char1);
                count1 -= 1;
                if (count1 > 0) heap.push({count1, char1});
            } else {
                if (heap.empty()) break;
                auto [count2, char2] = heap.top();
                heap.pop();
                res.push_back(char2);
                count2 -= 1;

                if (count2 > 0) heap.push({count2, char2});
                heap.push({count1, char1});
            }
        }

        return res;
    }
};

int main(){
    int a = 1, b = 1, c = 7;
    auto s = Solution();
    auto result = s.longestDiverseString(a, b, c);

    cout << result << '\n';
    return 0;
}
