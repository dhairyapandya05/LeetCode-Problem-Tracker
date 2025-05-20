class Solution {
public:
    int n;
    vector<int> segmentTree;
    vector<int> lazy;

    void buildTree(int i, int s, int e, vector<int>& nums, vector<int>& tree) {
        if (s == e) {
            tree[i] = nums[s];
            return;
        }
        int mid = (s + e) / 2;
        buildTree(2 * i, s, mid, nums, tree);
        buildTree(2 * i + 1, mid + 1, e, nums, tree);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    void updateRange(int qS, int qE, int i, int left, int right, int val,
                     vector<int>& tree, vector<int>& lazy) {
        if (lazy[i] != 0) {
            tree[i] += lazy[i]; // Apply lazy updates
            if (left != right) { // Propagate to children
                lazy[2 * i] += lazy[i];
                lazy[2 * i + 1] += lazy[i];
            }
            lazy[i] = 0; // Clear lazy for this node
        }

        // Out of range
        if (qS > right || qE < left || left > right)
            return;

        // Total overlap
        if (qS <= left && qE >= right) {
            tree[i] += val;
            if (left != right) { // Propagate to children
                lazy[2 * i] += val;
                lazy[2 * i + 1] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (left + right) / 2;
        updateRange(qS, qE, 2 * i, left, mid, val, tree, lazy);
        updateRange(qS, qE, 2 * i + 1, mid + 1, right, val, tree, lazy);

        // Merge results
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    int queryRange(int qS, int qE, int i, int left, int right, vector<int>& tree, vector<int>& lazy) {
        // Resolve lazy updates if present
        if (lazy[i] != 0) {
            tree[i] += lazy[i];
            if (left != right) { // Propagate to children
                lazy[2 * i] += lazy[i];
                lazy[2 * i + 1] += lazy[i];
            }
            lazy[i] = 0; // Clear lazy for this node
        }

        // No overlap
        if (qS > right || qE < left || left > right)
            return INT_MIN; // Neutral value for maximum query

        // Total overlap
        if (qS <= left && qE >= right)
            return tree[i];

        // Partial overlap
        int mid = (left + right) / 2;
        int leftResult = queryRange(qS, qE, 2 * i, left, mid, tree, lazy);
        int rightResult = queryRange(qS, qE, 2 * i + 1, mid + 1, right, tree, lazy);

        // Merge the results
        return max(leftResult, rightResult);
    }

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        segmentTree.resize(4 * n + 1);
        lazy.resize(4 * n + 1, 0); // Ensure lazy vector is initialized to zero
        buildTree(1, 0, n - 1, nums, segmentTree);
        for (auto it : queries) {
            int rS = it[0];
            int rE = it[1];
            updateRange(rS, rE, 1, 0, n - 1, -1, segmentTree, lazy);
        }

        int ans = queryRange(0, n - 1, 1, 0, n - 1, segmentTree, lazy);
        return ans <= 0; // Assuming the root node stores the maximum value
    }
};
