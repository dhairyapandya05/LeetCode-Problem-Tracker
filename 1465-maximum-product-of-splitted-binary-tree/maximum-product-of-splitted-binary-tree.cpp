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
    const unsigned int MOD = 1e9 + 7;
    long ans = 0;
    long sumTotalTree=0;
    int sumTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return sumTree(root->left) + sumTree(root->right) + root->val;
    }
    long find(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        long leftans=find(root->left);
        long rightans=find(root->right);
        long s1 = leftans+rightans+root->val;
        ans = max(ans, s1 * (sumTotalTree - s1));
        return s1;
    }
    int maxProduct(TreeNode* root) {
        sumTotalTree = sumTree(root);
        // long maxProduct = 0;
        find(root);

        return ans % MOD;
    }
};