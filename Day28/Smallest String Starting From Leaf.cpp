class Solution {
public:
    string result = "";
    
    
    void solve(TreeNode* root, string curr) {
        if(root == NULL) {
            return;
        }
        
        curr = char(root->val + 'a') + curr; //This will take O(length of curr) but I have ignored this. You can condiser this as well in calculating T.C
        
        if(root->left == NULL && root->right == NULL) {
            if(result == "" || result > curr) {
                result = curr;
            }
            return;
        }
        
        solve(root->left, curr);
        solve(root->right, curr);
        
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        
        return result;
    }
};
