#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto size = temperatures.size();
        // 存index
        auto buffer = vector<int>();
        // 默认为0
        auto answers = vector<int>(size);

        for (int i = size - 1; i >= 0; --i) {
            while (buffer.empty() == false && temperatures[i] >= temperatures[buffer.back()]) {
                buffer.pop_back();
            }

            if (buffer.empty() == false) {
                answers[i] = buffer.back() - i;
            }

            buffer.push_back(i);
        }

        return answers;
    }
};

int main(){
    auto temperatures = vector<int>{73,74,75,71,69,72,76,73};
    auto s = Solution();
    auto result = s.dailyTemperatures(temperatures);
    for (auto &x: result) {
        cout << x << " ";
    }

    cout << "\n";
    return 0;
}
