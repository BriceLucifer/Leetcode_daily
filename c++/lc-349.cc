#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        for(auto &n: nums1){
            map1[n] += 1;
        }
        unordered_map<int, int> map2;
        for(auto &n: nums2){
            map2[n] += 1;
        }

        unordered_map<int, int> map;
        for(auto &[x, y]: map1){
            map[x] += 1;
        }
        for(auto &[x, y]: map2){
            map[x] += 1;
        }

        vector<int> result{};
        for(auto &[x, y]: map){
            if (y > 1){
                result.push_back(x);
            }
        }

        return result;
    }
};
