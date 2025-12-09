#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int countTriples(int n) {
        auto count {0};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j){
                    auto s = sqrt(i*i + j*j);
                    // check if it is int
                    if( s == floor(s) && s <= n) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};

int main(){
    auto n = 5;
    auto s = Solution();
    auto result = s.countTriples(n);
    cout << result << '\n';

    return 0;
}
