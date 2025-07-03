/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, long long int>> qe;
        qe.push_back({root, 0});
        long long int ans = 0;
        while (!qe.empty()) {
            int N = qe.size();
            auto fr = qe.front();
            auto bk = qe.back();
            ans = max(ans, bk.second - fr.second + 1);

            while (N--) {
                auto [node,index]=qe.front();
                index-=fr.second;
                qe.pop_front();
                if (node->left) {
                    qe.push_back({node->left, 2 * index});
                }
                if (node->right) {
                    qe.push_back({node->right, (2 *index) + 1});
                }
            }
        }
        return ans;
    }
};