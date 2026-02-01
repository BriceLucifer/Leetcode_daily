class Solution {
public:
    int countMonobit(int n) {
        auto result {0};
        auto predict {0};

        while (predict <= n) {
            result += 1;
            predict = (predict << 1) + 1;
        }

        return result;
    }
};
