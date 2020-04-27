/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res;
        res = helperCalDia(root);
        return res;
    }
    
    int helperCalDia(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftH = findHeights(root->left);
        int rightH = findHeights(root->right);
        
        int leftDia = helperCalDia(root->left);
        int rightDia = helperCalDia(root->right);
        
        return max(leftH + rightH, max(leftDia,rightDia) );
        
    }
    
    int findHeights(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftH =  findHeights(root->left);
        int rightH = findHeights(root->right);
        
        return 1 + max(leftH,rightH);
    }
};