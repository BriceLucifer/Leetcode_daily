#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()){
            return {};
        }
        vector<int> stack;
        auto size = nums.size();

        vector<string> result;
        for(auto &x: nums){
            if (stack.empty()){
                stack.push_back(x);
                continue;
            }

            if (x - stack.back() == 1){
                stack.push_back(x);
                continue;
            }

            if (x - stack.back() != 1){
                if (stack.size() == 1){
                    stringstream ss;
                    ss << stack.front();
                    result.push_back(ss.str());
                } else {
                    stringstream ss;
                    ss << stack.front() << "->" << stack.back() ;
                    result.push_back(ss.str());
                }
                stack.clear();
                stack.push_back(x);
            }

        }
        if (stack.size() == 1){
            stringstream ss;
            ss << stack.front();
            result.push_back(ss.str());
        } else {
            stringstream ss;
            ss << stack.front() << "->" << stack.back() ;
            result.push_back(ss.str());
        }
        return result;
    }

};
