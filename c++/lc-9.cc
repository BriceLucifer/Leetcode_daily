#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        vector<int> v;
        auto temp = x;
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }

        auto n = v.size();
        auto y = 0;

        for (int i = 0; i < n; i++){
            y = y * 10 + v[i];
        }

        return temp == y;
    }
};

int main(){
    int x = 121;
    auto s = Solution();
    auto result = s.isPalindrome(x);

    if (result){
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
}
