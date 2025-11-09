#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Move to the next line after printing all elements
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto first {0}, second {1};
        auto length {0};

        if (nums.size() == 0) {
            return length;
        }

        for (;second < nums.size(); second+=1,first+=1) {
            if (nums[first] != nums[second]) {
                length += 1;
                nums[length] = nums[second];
            }
            print(nums);
        }

        return length+1;
    }
};

int main() {
    vector<int> n {0,0,1,1,1,2,2,3,3,4};
    Solution s{};
    cout << s.removeDuplicates(n) << endl;
    return 0;
}
