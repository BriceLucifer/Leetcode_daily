#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        auto rows = board.size();
        auto cols = board[0].size();
        auto replace = 'R';

        function<void(int, int, char)> dfs = [&](int i, int j, char sign){
            if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] == 'X' || board[i][j] == sign) return ;
            board[i][j] = sign;
            dfs(i+1, j, sign);
            dfs(i-1, j, sign);
            dfs(i, j-1, sign);
            dfs(i, j+1, sign);
        };

        for(int i = 0; i < rows; i++){
            if( i == 0 || i == rows - 1) {
                for(int j = 0; j < cols; j++){
                    if (board[i][j] == 'O')
                        dfs(i, j, replace);
                }
            } else {
                if (board[i][0] == 'O') dfs(i, 0, replace);
                if (board[i][cols-1] == 'O') dfs(i, cols-1, replace);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == replace) board[i][j] = 'O';
            }
        }

    }
};


int main(){
    vector<vector<char>> board{};
    auto s = Solution();
    for(auto row: board){
        for (auto item: row){
            cout << item << ' ';
        }
        cout << '\n';
    }
}
