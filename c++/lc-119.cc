#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row {1};
        if (rowIndex == 0) return row;
        for(int i = 0; i <= rowIndex; i++){
            vector<int> temp(i+1, 1);
            for(int j = 1; j < i; j++){
                temp[j] = row[j] + row[j-1];
            }
            row = std::move(temp);
        }

        return row;
    }
};
