void preorder(TreeNode* root , vector<int> &in)
{
    if(root == NULL)return ;
    
    in.push_back(root->data);
    preorder(root->left,in);
    preorder(root->right,in); 
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans ; 
    preorder(root,ans);
    return ans ;
}
