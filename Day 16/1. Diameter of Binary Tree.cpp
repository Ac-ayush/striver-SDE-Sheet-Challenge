                                //DP/Rec on Tree//
//Av47 >> Diameter of Binary Tree 
#include<bits/stdc++.h> 
using namespace std ;

class Solution {
    int solve(TreeNode* root , int &res)
    {
        //1.Base Case
        if(root == NULL)
            return 0 ; 
    
        //2.Hypothesis 
        int l = solve(root->left , res) ; 
        int r = solve(root->right , res) ; 
        
        //3.insuction
        int temp = max(l,r) + 1 ;   //case2
        int ans = max(temp , l+r+1) ; //case1
        
        res = max(res , ans) ; 
        return temp ;   //return temp for Senior Nodes 
    }
    
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN ; 
        
        solve(root, res) ; 
        return res-1 ; 
    }
};


int main(){
    
}


/*
leetcode : https://leetcode.com/problems/diameter-of-binary-tree/submissions/
code studio : https://www.codingninjas.com/codestudio/problems/diameter-of-the-binary-tree_920552?topList=striver-sde-sheet-problems&leftPanelTab=0
*/
