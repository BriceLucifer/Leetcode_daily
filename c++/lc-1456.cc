#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        auto check_size = [&](string s) -> int {
            auto size = 0;
            for(auto &i: s) {
                if (i == 'a' || i == 'e' || i == 'o' || i == 'i' || i == 'u')
                    size += 1;
            }
            return size;
        };
        auto check_vowel = [](char c) -> bool {
            return (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') ? true : false;
        };
        auto sub_str = s.substr(0, k);
        int max_size = check_size(sub_str);
        auto res = max_size;
        for (int i = k; i < s.size(); i++){
            if (check_vowel(s[i - k])) res--;
            if (check_vowel(s[i])) res++;
            max_size = max(res, max_size);
        }
        return max_size;
    }
};

int main(){
    string test = "tryhard";
    auto k = 4;
    auto s = Solution();
    auto r = s.maxVowels(test, k);

    cout << r << "\n";
    return 0;
}
