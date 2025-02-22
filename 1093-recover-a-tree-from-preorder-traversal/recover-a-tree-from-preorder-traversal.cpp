/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solver(string &traversal, int &i, int depth){
        if(i >= traversal.size()) return NULL;

        int d = 0;
        while(traversal[i] == '-'){
            d++;
            i++;
        }

        if(d < depth){
            i -= d;
            return NULL;
        }

        int value = 0;
        while(isdigit(traversal[i])){
            value = (value * 10) + (traversal[i] - '0');
            i++;
        }

        TreeNode *node = new TreeNode(value);

        node->left = solver(traversal, i, depth+1);
        node->right = solver(traversal, i, depth+1);

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        TreeNode* root = solver(traversal, i, 0);
        return root;
    }
};