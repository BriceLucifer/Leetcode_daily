#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(auto &c: magazine){
            map[c] += 1;
        }
        auto result {false};
        for(auto &c: ransomNote){
            if (map[c] > 0){
                map[c] -= 1;
            } else {
                return false;
            }
        }

        return true;
    }
};
