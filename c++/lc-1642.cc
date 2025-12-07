#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        auto size = heights.size();
        auto compare = vector<int>(size - 1);
        for (int i = 0; i < size - 1; i++){
            compare[i] = heights[i+1] - heights[i];
        }

        auto heap = priority_queue<int>();

        for(int i = 0; i < size-1; i++){
            auto x = compare[i];
            if (x <= 0){
                continue;
            }

            bricks -= x;
            heap.push(x);

            if (bricks < 0){
                if (ladders == 0) return i;
                bricks += heap.top();
                heap.pop();
                ladders -= 1;
            }
        }

        return size-1;
    }
};

int main(){
    auto heights = vector<int>{4,12,2,7,3,18,20,3,19};
    auto bricks = 10;
    auto ladders = 2;

    auto s = Solution();
    auto result = s.furthestBuilding(heights, bricks, ladders);
    cout << result << "\n";
}
