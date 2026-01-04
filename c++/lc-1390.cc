#include <cmath>
#include <numeric>
#include <print>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    constexpr unordered_set<int> splitnum(int n){
        auto set = unordered_set<int>{};
        set.insert(1);

        for(int i = 1; i <= sqrt(n); i++){
            if (n % i == 0){
                set.insert(n / i);
                set.insert(i);
            }
        }

        return set;
    }

    constexpr int sumFourDivisors(vector<int>& nums) {
        auto temp = vector<unordered_set<int>>(nums.size(), unordered_set<int>{});
        for(int i = 0; i < nums.size(); i++){
            temp[i] = splitnum(nums[i]);
        }

        auto result = 0;
        for(auto &e: temp){
            if (e.size() == 4){
                result = accumulate(e.begin(), e.end(), result);
            }
        }

        return result;
    }
};

int main(){
    auto nums = vector<int>{21,4,7};
    auto s = Solution().sumFourDivisors(nums);
    println("{}", s);
    return 0;
}
