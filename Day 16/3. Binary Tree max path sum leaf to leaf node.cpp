//Av49 >> Maximum Path from Leaf node to Leaf node 
#include<bits/stdc++.h>
using namespace std ;

/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
private:
    int solve(Node* root, int &res){
//1.Base Case
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
//2.Hypothesis
        int l=solve(root->left,res);
        int r=solve(root->right,res);

        if(root->left==NULL) return  (r+root->data);
        if(root->right==NULL) return (l+root->data);
//3.Induction         
        //code will come upto this only if root has both left and right child
        int temp = max(l,r)+root->data;
        int ans = l+r+root->data;
        res=max(res,ans);
        
        return temp;
    }
    
    
public:
    int maxPathSum(Node* root)
    {
        int res = INT_MIN ; 
        int x =solve(root , res) ; 
        
        if (root->left == NULL || root->right == NULL)
            return max(res,x);

        return res;
    }
};


int main(){
    
}


/*
gfg : https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#
leetcode : https://www.codingninjas.com/codestudio/problems/maximum-path-sum-between-two-leaves_794950?topList=striver-sde-sheet-problems&leftPanelTab=0
*/
