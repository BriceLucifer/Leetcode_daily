#include <iostream>
class Solution {
public:
    int hammingWeight(int n) {
        auto i {0};
        for(;n != 0;){
            i += n % 2;
            n = n/2;
        }
        return i;
    }
};

int main(){
    auto n = 11;
    auto result = Solution().hammingWeight(n);
    std::cout << result <<'\n';
}
