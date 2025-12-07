#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /*
         * k -> max target project
         * w -> current captical
         * profits -> each project profits
         * capital -> each project the cost
         */

         // 先活命
         auto init = w;
         auto size = profits.size();
         vector<pair<int, int>> a;
         a.reserve(size);

         // 创建pair
         for(int i = 0; i < size; i++){
             a.push_back({capital[i], profits[i]});
         }

         // 排序
         sort(a.begin(), a.end());
         priority_queue<int> max_heap;
         // while 循环指针
         int idx = 0;

         for(int i = 0; i < k; i++){
             while (idx < size && a[idx].first <= w) {
                 max_heap.push(a[idx].second);
                 idx++;
             }

             // break if empty
             if(max_heap.empty()) break;

             w += max_heap.top();
             max_heap.pop();
         }

         return w;
    }
};

int main(){
    auto k = 2;
    auto w = 0;
    auto profits = vector<int>{1,2,3};
    auto capital = vector<int>{0,1,1};
    auto s = Solution();
    auto max_profit = s.findMaximizedCapital(k, w, profits, capital);

    cout << max_profit << '\n';
    return 0;
}
