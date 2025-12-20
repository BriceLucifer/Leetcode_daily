#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto block = needle.size();
        for(int i = 0; i < haystack.size(); i++){
            if (haystack[i] == needle.front()){
                string temp;
                for(int j = 0; j < block; j++){
                    if (i + j < haystack.size()){
                        temp.push_back(haystack[i+j]);
                    }
                }

                if (temp == needle){
                    return i;
                }
            }
        }

        return -1;
    }
};
