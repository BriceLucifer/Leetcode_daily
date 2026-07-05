#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto i = m - 1;
        auto j = n - 1;
        auto k = m + n - 1;

        for(; j >= 0; k--){
            if (i >= 0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i -= 1;
            } else {
                nums1[k] = nums2[j];
                j -= 1;
            }
        }
    }
};
