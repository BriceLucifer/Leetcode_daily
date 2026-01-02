#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto carry = false;
        auto size = digits.size();
        auto result = digits;

        if (result[size - 1] < 9) {
            result[size - 1] += 1;
            return result;
        }

        for(int i = size - 1; i >= 0; i--){
            if (result[i] == 9 ) {
                carry = true;
                result[i] = 0;
            } else {
                if (carry){
                    result[i] += 1;
                    carry = false;
                    return result;
                }
            }
        }

        if (carry){
            result.insert(result.begin(), 1);
        }

        return result;
    }
};

int main(){
    auto digits = vector<int>{9};
    auto result = Solution().plusOne(digits);
    for(auto &x: result){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
