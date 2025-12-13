#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        auto n = isActive.size();


        auto check_string = [](const std::string& s) -> bool {
            if (s.empty()) return false;

            for (char c : s) {
                if ((c >= 'a' && c <= 'z') ||
                    (c >= 'A' && c <= 'Z') ||
                    (c >= '0' && c <= '9') ||
                    c == '_') {
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        };


        auto check_category = [](string& s)->bool{
            if (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant") {
                return true;
            }
            return false;
        };

        auto rate_category = [](string& s) -> int {
            if (s == "electronics") return 1;
            if (s == "grocery") return 2;
            if (s == "pharmacy") return 3;
            if (s == "restaurant") return 4;
            return 0;
        };

        auto valid = vector<pair<int, string>>();

        for(int i = 0; i < n; i++){
            if (isActive[i] && check_string(code[i]) && check_category(businessLine[i])) {
                valid.push_back({rate_category(businessLine[i]), code[i]});
            }
        }

        sort(valid.begin(), valid.end());
        vector<string> result;
        for(auto item: valid){
            result.push_back(item.second);
        }

        return result;
    }
};
