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
private:
    int maxpath_sum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        solvePathSum(root);
        return maxpath_sum;
    }
    
    int solvePathSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
		//Find the maximum sum from the left and right sub tree
        int left = max(0,solvePathSum(root->left));
        int right = max(0,solvePathSum(root->right));
        
		//Update the maxpath_sum
        maxpath_sum = max(maxpath_sum, left + right + root->val);
        
		//Return the left or right path sum with root that has max value 
        int sum = max(left,right) + root->val;
        return sum;
    }
};