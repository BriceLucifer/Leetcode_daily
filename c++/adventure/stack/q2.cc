#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // ["2","1","+","3","*"]
    int evalRPN(vector<string>& tokens) {
        auto check_operation = [&](const string& t) -> bool {
            return t != "*" && t != "/" && t != "+" && t != "-";
        };

        vector<int> operators;
        for (auto token: tokens) {
            if (check_operation(token)) {
                operators.push_back(stoi(token));
            } else {
                if (token == "*") {
                    int result = 0;
                    result = operators.back();
                    operators.pop_back();
                    result *= operators.back();
                    operators.pop_back();
                    operators.push_back(result);
                } else if (token == "+") {
                    int result = 0;
                    result = operators.back();
                    operators.pop_back();
                    result += operators.back();
                    operators.pop_back();
                    operators.push_back(result);
                } else if (token == "-") {
                    int sub = operators.back();
                    operators.pop_back();
                    int min = operators.back();
                    operators.pop_back();
                    operators.push_back(min - sub);
                } else if (token == "/") {
                    int divisor = operators.back();
                    operators.pop_back();
                    int divd = operators.back();
                    operators.pop_back();
                    operators.push_back(divd / divisor);
                }
            }
        }
        return operators.front();
    }
};

int main() {
    auto tokens = vector<string>{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    auto s = Solution();

    auto result = s.evalRPN(tokens);
    cout << result << "\n";
    return 0;
}
