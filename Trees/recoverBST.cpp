// O(1) space

void inorder(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &prev){
    if(!root) return;
    
    inorder(root->left,first,second,prev);
    if(prev && prev->val>root->val){
        if(!first){
            first=prev;
        }
        second=root;
    }
    prev=root;
    inorder(root->right,first,second,prev);
}
 
vector<int> Solution::recoverTree(TreeNode* root) {
    TreeNode *first,*second,*prev;
    first=second=prev=NULL;
    
    inorder(root,first,second,prev);
    swap(first->val,second->val);
    return {first->val,second->val};
}

// O(n) space

class Solution {
public:
    vector<TreeNode*> arr;
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        //if(!root) return;
        arr.clear();
        inorder(root);
        int n=arr.size();
        int i,j;
        for(i=0;i<n-1;i++){
            if(arr[i]->val>arr[i+1]->val){
                break;
            }
        }
        for(j=i+1;j<n-1;j++){
            if(arr[j]->val>arr[j+1]->val){
                break;
            }
        }
        j++;
        
        if(j==n){
            j=i+1;
        }
        swap(arr[i]->val,arr[j]->val);
    }
};
