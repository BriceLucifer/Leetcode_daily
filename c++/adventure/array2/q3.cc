#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int size = nums.size();
        auto result = vector<int>();

        std::map<int, int> counter;
        for (int i = 1; i <= size; ++i){
            counter[i] = 0;
        }

        for (auto i: nums) {
            counter[i] += 1;
        }

        for (auto i: counter) {
            if (i.second == 0) {
                result.push_back(i.first);
            }
        }

        return result;
    }
};


int main(){
    vector<int> nums {1,1};
    auto s = Solution();
    auto r  = s.findDisappearedNumbers(nums);

    for (auto i: r) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
