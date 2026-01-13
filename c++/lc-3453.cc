#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total_area = 0.0;
        double max_y = 0.0;

        // 计算总面积 & 搜索上界
        for (auto& s : squares) {
            double y = s[1];
            double l = s[2];
            total_area += l * l;
            max_y = max(max_y, y + l);
        }

        auto check = [&](double y) {
            double area = 0.0;
            for (auto& s : squares) {
                double yi = s[1];
                double l = s[2];
                if (yi < y) {
                    area += l * min(y - yi, l);
                }
            }
            return area >= total_area / 2.0;
        };

        double left = 0.0, right = max_y;

        // 二分 80 次足够 double 精度
        for (int i = 0; i < 80; ++i) {
            double mid = (left + right) / 2.0;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return (left + right) / 2.0;
    }
};
