class Solution {
public:
    void getDistances(int start, const vector<int>& edges, vector<int>& dist) {
        int d = 0;
        while (start != -1 && dist[start] == -1) {
            dist[start] = d++;
            start = edges[start];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        getDistances(node1, edges, dist1);
        getDistances(node2, edges, dist2);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist ) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};