
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>  ans  ; 
    queue<BinaryTreeNode<int>* > q ; 
    if(root == NULL)return ans ; 
    
    q.push(root) ; 
    while(!q.empty()){
        auto temp = q.front() ;            //auto -> BinaryTreeNode<int> *
        q.pop() ; 
        ans.push_back(temp->val) ; 
        
        if(temp->left)
            q.push(temp->left) ; 
        if(temp->right)
            q.push(temp->right) ; 
    }
    return ans ; 
}
