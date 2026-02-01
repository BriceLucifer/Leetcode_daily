#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq{};
        for(auto &c: letters){
            if (c > target){
                pq.push({c - target, c});
            }
        }

        if (pq.empty()){
            return letters[0];
        } else {
            return pq.top().second;
        }
    }
};
