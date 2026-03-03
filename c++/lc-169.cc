#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map{};

        for(auto &i: nums){
            map[i] += 1;
        }

        int times{0};
        int element;
        for(auto &[x, y]: map){
            if (y > times){
               times = y;
               element = x;
            }
        }
        return element;
    }
};
