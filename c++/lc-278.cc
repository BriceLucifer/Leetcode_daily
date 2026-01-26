// The API isBadVersion is defined for you.
bool isBadVersion(int version){
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        auto left {1};
        auto right {n};
        auto mid = left + (right - left + 1) / 2;
        while (left <= right) {
            if (isBadVersion(mid)){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = left + (right - left + 1) / 2;
        }

        return left;
    }
};
