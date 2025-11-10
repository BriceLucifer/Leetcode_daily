#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto area {0};

        // 从公式出发 (底边) * height{i} = area
        // for (auto i = 0; i < height.size(); ++i) {
        //     for (auto j = i + 1; j < height.size(); ++j) {
        //         if (height[i] >= height[j]) {
        //             auto a = height[j] * (j - i);
        //             area = area > a ? area : a;
        //         } else {
        //             auto a = height[i] * (j - i);
        //             area = area > a ? area : a;
        //         }
        //     }
        // }
        auto i {0};
        auto j {height.size() - 1};

        for (;i <= j;) {
            area = max<int>(area,(min(height[i], height[j]) * (j - i)));
            if (height[i] <= height[j]) {
                ++i;
            } else {
                --j;
            }
        }

        return area;
    }
};

int main() {
    vector<int> nums1 {1,8,6,2,5,4,8,3,7};
    vector<int> nums2 {1,1};
    Solution s{};
    cout << s.maxArea(nums1) << endl;
    return 0;
}
