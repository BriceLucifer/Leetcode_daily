#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        vector<int> result;
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] > target){
                j--;
            }else if (numbers[i] + numbers[j] < target){
                i++;
            }else {
                return {i+1, j+1};
            }
        }

        return result;
    }
};

int main(){
    auto numbers = vector<int>{2, 7, 11, 15};
    auto target = 9;
    auto s = Solution();
    auto result = s.twoSum(numbers, target);

    for (auto &x: result){
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
