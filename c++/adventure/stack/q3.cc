#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> stack;

        // 设置time Enum
        enum class Time {
             Start,
             End,
        };

        // input处理
        auto parser = [&](vector<string>& strs)-> vector<pair<int, pair<Time, int>>>{
            auto elements = vector<pair<int, pair<Time, int>>>();
            for (auto str: strs)  {
                istringstream ss(str);
                string func_name;
                string excution;
                string time_stamp;

                getline(ss, func_name, ':');
                getline(ss, excution, ':');
                getline(ss, time_stamp, ':');

                Time ex;
                if (excution == "start") {
                    ex = Time::Start;
                } else {
                    ex = Time::End;
                }

                elements.push_back({stoi(func_name), {ex, stoi(time_stamp)}});
            }

            return elements;
        };

        auto pre_parsed_log = parser(logs);
        auto results = vector<int>(n);
        auto buffer = vector<pair<int, pair<Time, int>>>();
        for (auto &log: pre_parsed_log){
            if (log.second.first == Time::Start) {
                if (!buffer.empty()) {
                    results[buffer.back().first] += log.second.second - buffer.back().second.second;
                }
                // 为空就推入
                buffer.push_back(log);
            } else {
                results[log.first] += log.second.second - buffer.back().second.second + 1;
                buffer.pop_back();

                // 停止的函数再次执行
                if (!buffer.empty()) {
                    buffer.back().second.second = log.second.second + 1;
                }
            }
        }

        return results;
    }
};

int main() {
    auto logs = vector<string>{"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
    auto s = Solution();
    auto n = 2;
    auto results = s.exclusiveTime(n, logs);

    for (auto& x:results) {
        cout << x << " ";
    }

    cout << "\n";
}
