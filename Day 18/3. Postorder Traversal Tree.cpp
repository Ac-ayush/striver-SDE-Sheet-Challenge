void postorder(TreeNode* root , vector<int> &in)
{
    if(root == NULL)return ;
    
    postorder(root->left,in);
    postorder(root->right,in);
    in.push_back(root->data);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans ; 
    postorder(root,ans);
    return ans ;
}
