#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        auto max = 0;
        auto size = heights.size();

        return max;
    }
};

int main(){
    auto height = vector<int>{2,1,5,6,2,3};
    auto s = Solution();
    auto r = s.largestRectangleArea(height);

    cout << r << "\n";
    return 0;
}
