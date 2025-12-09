#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for (auto &n: nums){
            max_heap.push(n);
        }
        for (int i = 1; i < k; i++){
            max_heap.pop();
        }
        return max_heap.top();
    }
};

int main(){
    auto nums = vector<int>{3,2,3,1,2,4,5,5,6};
    auto k = 4;
    auto s = Solution();
    auto result = s.findKthLargest(nums, k);
    cout << result << '\n';

    return 0;
}
