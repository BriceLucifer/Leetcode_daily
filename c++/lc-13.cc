#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        unordered_map<char, int> maps{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I' && i != s.length() - 1) {
                if (s[i + 1] == 'V') {
                    result += 4;
                    i++;
                } else if (s[i + 1] == 'X') {
                    result += 9;
                    i++;
                } else {
                    result += maps[s[i]];
                }
            } else if (s[i] == 'X' && i != s.length() - 1) {
                if (s[i + 1] == 'L') {
                    result += 40;
                    i++;
                } else if (s[i + 1] == 'C') {
                    result += 90;
                    i++;
                } else {
                    result += maps[s[i]];
                }
            } else if (s[i] == 'C' && i != s.length() - 1) {
                if (s[i + 1] == 'D') {
                    result += 400;
                    i++;
                } else if (s[i + 1] == 'M') {
                    result += 900;
                    i++;
                } else {
                    result += maps[s[i]];
                }
            } else {
                result += maps[s[i]];
            }
        }

        return result;
    }
};
