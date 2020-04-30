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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(root == NULL){
            return false;
        }
        int n = arr.size();
        int ind = 0;
        bool result = helperSolveFindSeq(root,arr,ind,n);
        
        return result;
    }
    
    bool helperSolveFindSeq(TreeNode* root, vector<int> &arr,int ind, int n){
        if(root == NULL){
            return false;
        }
        if(ind == n-1 ){
			//If we are at last index, just compare the value with node
			//Also check if it is a leaf node
            if(root->left || root->right){
                return false;
            }else if(arr[ind] == root->val ){
                return true;
            }else{
                return false;
            }
        }
        else{
			//If node value matches with the element at index ind in arr
			//Then recurse on the left as well as on the right of the node
			//And Acc. store values of left and right
			//And return true if a path exists either on left or right
            if(root->val == arr[ind]){
                bool leftCheck = helperSolveFindSeq(root->left,arr,ind+1,n);
                bool rightCheck = helperSolveFindSeq(root->right,arr,ind+1,n);
                return leftCheck || rightCheck;
            }else{
                return false;
            }
        }
    }
};