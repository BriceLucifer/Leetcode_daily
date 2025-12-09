#include <iostream>
#include <queue>
#include <vector>

using namespace std;


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        /*
         * target = postion of the endpoint
         * startFuel = initial fuel
         * stations = {postion: fuel}
         */
         if (target == startFuel){
             return 0;
         }

         priority_queue<int> heap;
         auto prev = 0;
         auto count = 0;

         for(auto &x: stations){
             auto dis = x[0] - prev;
             startFuel -= dis;

             while (startFuel < 0) {
                 if (heap.empty()) return -1;
                 startFuel += heap.top();
                 heap.pop();
                 count += 1;
             }

             heap.push(x[1]);
             prev = x[0];
         }

         // 怕加油站全部结束之后 我还没到target
         // hints: 1 <= positioni < positioni+1 < target
         startFuel -= (target - prev);
         while (startFuel < 0) {
             if (heap.empty()) return -1;
             startFuel += heap.top();
             heap.pop();
             count += 1;
         }

         return count;
    }
};


int main(){
    auto target = 100;
    auto startFuel = 1;
    auto stations = vector<vector<int>>{{10,100},};

    auto s = Solution();
    auto result = s.minRefuelStops(target, startFuel, stations);

    cout << result << '\n';
    return 0;
}
