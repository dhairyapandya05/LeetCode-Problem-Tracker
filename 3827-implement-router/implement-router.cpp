class Router {
    struct Packet {
        int source;
        int destination;
        int timestamp;

        bool operator==(const Packet& other) const {
            return tie(source, destination, timestamp) == tie(other.source, other.destination, other.timestamp);
        }
    };

    struct PacketHash {
        size_t operator()(const Packet& p) const {
            return hash<int>()(p.source) ^ hash<int>()(p.destination << 1) ^ hash<int>()(p.timestamp << 2);
        }
    };

    struct DestinationData {
        vector<int> timestamps;
        int start = 0;
        int end = -1;
    };

    int memoryLimit;
    queue<Packet> packetQueue;
    unordered_set<Packet, PacketHash> packetSet;
    unordered_map<int, DestinationData> destinationMap;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet packet{source, destination, timestamp};

        if (packetSet.count(packet)) return false;

        if ((int)packetQueue.size() >= memoryLimit) {
            // Evict the oldest packet
            Packet oldest = packetQueue.front();
            packetQueue.pop();
            packetSet.erase(oldest);

            auto& data = destinationMap[oldest.destination];
            data.start++;
        }

        // Add new packet
        packetQueue.push(packet);
        packetSet.insert(packet);

        auto& data = destinationMap[destination];
        data.timestamps.push_back(timestamp);
        data.end++;

        return true;
    }

    vector<int> forwardPacket() {
        if (packetQueue.empty()) return {};

        Packet packet = packetQueue.front();
        packetQueue.pop();
        packetSet.erase(packet);

        auto& data = destinationMap[packet.destination];
        data.start++;

        return {packet.source, packet.destination, packet.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destinationMap.find(destination);
        if (it == destinationMap.end() || it->second.start > it->second.end) return 0;

        const auto& timestamps = it->second.timestamps;
        int startIdx = it->second.start;
        int endIdx = it->second.end;

        auto first = timestamps.begin() + startIdx;
        auto last = timestamps.begin() + endIdx + 1;

        auto lower = lower_bound(first, last, startTime);
        auto upper = upper_bound(first, last, endTime);

        return max(0, (int)(upper - lower));
    }
};