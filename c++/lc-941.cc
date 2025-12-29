#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int i = 0;

        // 上升阶段
        while (i + 1 < n && arr[i] < arr[i + 1])
            i++;

        // 检查是否根本没有上升，或者直接到顶（无下降空间）
        if (i == 0 || i == n - 1)
            return false;

        // 下降阶段
        while (i + 1 < n && arr[i] > arr[i + 1])
            i++;

        return i == n - 1;
    }
};

int main(){
    vector<int> v {0, 2, 3, 4, 5, 2, 1, 0};
    auto result = Solution().validMountainArray(v);
    if (result){
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}
