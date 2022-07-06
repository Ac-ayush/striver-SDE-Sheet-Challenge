void postorder(TreeNode* root , vector<int> &in)
{
    if(root == NULL)return ;
    
    inorder(root->left,in);
    inorder(root->right,in);
    in.push_back(root->data);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans ; 
    postorder(root,ans);
    return ans ;
}
