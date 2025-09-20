class Router {
public:
    struct packet {
        int source;
        int destination;
        int timestamp;
    };

    int capacity;
    deque<packet> packets;
    unordered_set<string> activePackets;
    map<int, vector<int>> destTimestamps;

    Router(int memoryLimit) : capacity(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(destination) + "-" + to_string(source) + "-" + to_string(timestamp);

        if (activePackets.count(key)) return false;

        packet pc{source, destination, timestamp};
        packets.push_back(pc);
        activePackets.insert(key);
        destTimestamps[destination].push_back(timestamp);

        if ((int)packets.size() > capacity) {
            packet oldest = packets.front();
            packets.pop_front();

            string oldKey = to_string(oldest.destination) + "-" +
                            to_string(oldest.source) + "-" +
                            to_string(oldest.timestamp);

            activePackets.erase(oldKey);

            auto &vec = destTimestamps[oldest.destination];
            if (!vec.empty() && vec.front() == oldest.timestamp) {
                vec.erase(vec.begin());
            }
            if (vec.empty()) destTimestamps.erase(oldest.destination);
        }
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};

        packet pc = packets.front();
        packets.pop_front();

        string key = to_string(pc.destination) + "-" +
                     to_string(pc.source) + "-" +
                     to_string(pc.timestamp);
        activePackets.erase(key);

        auto &vec = destTimestamps[pc.destination];
        if (!vec.empty() && vec.front() == pc.timestamp) vec.erase(vec.begin()); 
        if (vec.empty()) destTimestamps.erase(pc.destination);

        return {pc.source, pc.destination, pc.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.count(destination)) return 0;
        auto &vec = destTimestamps[destination];

        auto low = lower_bound(vec.begin(), vec.end(), startTime);
        auto high = upper_bound(vec.begin(), vec.end(), endTime);

        return (int)(high - low);
    }
};
