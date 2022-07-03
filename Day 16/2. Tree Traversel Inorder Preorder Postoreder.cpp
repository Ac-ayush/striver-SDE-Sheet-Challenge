/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &in)
{
    if(root == NULL)return ; 
    
    inorder(root->left, in) ;
    in.push_back(root->data) ; 
    inorder(root->right, in) ;    
}

void preorder(BinaryTreeNode<int> *root ,vector<int> &pre)
{
    if(root == NULL)return ; 
    
    pre.push_back(root->data) ; 
    preorder(root->left , pre) ; 
    preorder(root->right , pre) ; 
}

void postorder(BinaryTreeNode<int> *root ,vector<int> &post)
{
    if(root == NULL)return ; 
    
    postorder(root->left ,post) ; 
    postorder(root->right ,post) ; 
    post.push_back(root->data) ; 
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans ; 
    
    vector<int> temp ; 
    inorder(root , temp) ; 
    ans.push_back(temp) ; 
    
    temp.clear() ; 
    preorder(root , temp) ; 
    ans.push_back(temp) ; 
    
    temp.clear() ; 
    postorder(root , temp) ; 
    ans.push_back(temp) ; 
    
    return ans ; 
}
