class Solution {
public:
    int findClosestMeetingNode(
        const unordered_map<int, int>& distanceMap1,
        const unordered_map<int, int>& distanceMap2) {
        int resultNode = -1;
        int minMaxDistance = numeric_limits<int>::max();

        for (const auto& [node, dist1] : distanceMap1) {
            if (distanceMap2.count(node)) {
                int dist2 = distanceMap2.at(node);
                int maxDist = max(dist1, dist2);

                if (maxDist < minMaxDistance || 
                    (maxDist == minMaxDistance && node < resultNode)) {
                    minMaxDistance = maxDist;
                    resultNode = node;
                }
            }
        }

        return resultNode;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, int> distanceMap1;
        unordered_map<int, int> distanceMap2;
        int currentNode = node1;
        int distance = 0;
        while (!distanceMap1.count(currentNode) && currentNode!=-1){
            distanceMap1[currentNode] = distance;
            distance++;
            currentNode = edges.at(currentNode);
        }

        currentNode = node2;
        distance = 0;
        while (!distanceMap2.count(currentNode) && currentNode!=-1){
            distanceMap2[currentNode] = distance;
            distance++;
            currentNode = edges.at(currentNode);
        }

        return findClosestMeetingNode(distanceMap1, distanceMap2);
    }
};
