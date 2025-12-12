#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";

        priority_queue<pair<int, char>> heap;
        // hint: 0 <= a, b <= 100
        if (a > 0) heap.push({a, 'a'});
        if (b > 0) heap.push({b, 'b'});

        // useless code
        // auto length = a + b;
        while (!heap.empty()) {
            auto [count1, char1] = heap.top();
            heap.pop();

            auto use = true;
            if (s.size() >= 2 && s[s.size() - 1] == char1 && s[s.size() - 2] == char1){
                use = false;
            }

            if (use){
                s.push_back(char1);
                count1 -= 1;
                if (count1 > 0) heap.push({count1, char1});
            } else {
                if (heap.empty()) break;
                auto [count2, char2] = heap.top();
                heap.pop();
                s.push_back(char2);
                count2 -= 1;
                if (count2 > 0) heap.push({count2, char2});

                heap.push({count1, char1});
            }
        }

        return s;
    }
};

int main(){
    auto a = 1, b = 2;
    auto s = Solution();
    auto res = s.strWithout3a3b(a, b);

    cout << res << '\n';
}
