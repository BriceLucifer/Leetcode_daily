#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        for(auto &n: nums1){
            map1[n] += 1;
        }

        vector<int> result{};

        for(auto &n: nums2){
            if (map1[n]){
                result.push_back(n);
                map1[n] -= 1;
            }
        }

        return result;
    }
};
