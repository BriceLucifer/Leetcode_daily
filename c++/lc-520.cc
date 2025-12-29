#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        auto size = word.size();
        auto one = 1;

        if (size == 1) {
            return true;
        }
        auto count {0};
        for(auto &s: word){
            if (s >='A' && s <= 'Z'){
                count += 1;
            }
        }

        if (count == 1 && word.front() >= 'A' && word.front() <= 'Z'){
            return true;
        }

        return count == size || count == 0? true : false;
    }
};


int main(){
    auto str = string{"USA"};
    auto result = Solution().detectCapitalUse(str);
    if (result){
        cout << "true\n";
    } else {
        cout << "false\n";
    }
}
