/* Minimum Depth of Binary Tree
** https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
*/
class Solution {
public:
    int nonZeroMin(int left, int right) {
        if (!left) return right;
        if (!right) return left;
        return min(left, right);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + nonZeroMin(minDepth(root->left), minDepth(root->right));
    }
};
