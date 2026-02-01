#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class RideSharingSystem {
private:
    list<int> riders;   // 按到达顺序存 riderId
    list<int> drivers;  // 按到达顺序存 driverId

    // riderId -> 在 riders list 里的位置，方便 O(1) cancel
    unordered_map<int, list<int>::iterator> riderPos;

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push_back(riderId);
        auto it = riders.end();
        --it;
        riderPos[riderId] = it;
    }

    void addDriver(int driverId) {
        drivers.push_back(driverId);
    }

    vector<int> matchDriverWithRider() {
        if (drivers.empty() || riders.empty()) return {-1, -1};

        int driverId = drivers.front();
        int riderId  = riders.front();

        drivers.pop_front();

        // 删除 rider，同时清理索引
        riders.pop_front();
        riderPos.erase(riderId);

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        auto it = riderPos.find(riderId);
        // 题目保证一定存在且未匹配；这里写个保护也无妨
        if (it == riderPos.end()) return;

        riders.erase(it->second);
        riderPos.erase(it);
    }
};
