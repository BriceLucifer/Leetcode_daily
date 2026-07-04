// #include <algorithm>
// #include <queue>
// #include <vector>

// using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         priority_queue<int> p{};
//         auto result {0};
//         for(int i = prices.size() - 1; i >= 0; i--){
//             if (p.empty()){
//                 p.push(prices[i]);
//             } else {
//                 result = max(result, p.top() - prices[i]);
//                 p.push(prices[i]);
//             }
//         }

//         return result;
//     }
// };
//

#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int size = prices.size();
       if (size == 1) return 0;

       priority_queue<int, vector<int>, greater<int>> q {};

       auto minPrice = prices[0];
       // auto dp = vector<int>(size, 0);
       auto maxProfit = 0;
       for(int i = 0; i < size; i++){
           // minPrice = min(minPrice, prices[i]); // 其实min可以用priority_queue去维护 因为可以设置min么 顺序
           if (q.empty()){
               q.push(prices[i]);
           } else {
               maxProfit = max(maxProfit, prices[i] - q.top());
               q.push(prices[i]);
           }
       }
       return maxProfit;
    }
};
