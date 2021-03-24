class Solution {
public:
    int maxProduct(TreeNode* root) {
        int sum = subtreesum(root);
        long long int val = 0;
        splitsumproduct(root, val, sum);
        
        return val%1000000007;
    }
    
    int subtreesum(TreeNode* root) {
        if(root == NULL) return 0;
        
        root->val += subtreesum(root->left);
        root->val += subtreesum(root->right);
        
        return root->val;
    }
    
    void splitsumproduct(TreeNode* root, long long int& val, int& sum) {
        if(root == NULL) return;
        
        if(root->left) {
            long long int lf = root->left->val;
            val = max(val, (lf*(sum - lf)));
        } 
            
        if(root->right) {
            long long int rt = root->right->val;
            val = max(val, (rt*(sum - rt)));
        } 
            
        splitsumproduct(root->left, val, sum);
        splitsumproduct(root->right, val, sum);

    }
};
