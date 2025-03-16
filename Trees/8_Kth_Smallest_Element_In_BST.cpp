// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inOrderTraversal(TreeNode *root, int k, int& count, int& ans){
        if(root == nullptr) return;

        inOrderTraversal(root->left, k, count, ans);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        inOrderTraversal(root->right, k, count, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        inOrderTraversal(root,k,count,ans);
        return ans;
    }
};
    