//Av48 >> Maximum Path from any Node To any Node
#include<bits/stdc++.h> 
using namespace std ; 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 
class Solution {
private:
    int solve(TreeNode* root, int &res)
    {   //1.Base Case 
        if(root==NULL)
            return 0; 
        
        //2.Hypothesis
        int l = solve(root->left , res) ; 
        int r = solve(root->right, res) ; 
        
        //3.Induction 
        int temp = max( max(l,r)+root->val , root->val) ; 
        int ans = max(temp , l+r+root->val) ; 
        
        res = max(ans,res) ; 
        
        return temp ; 
    }
    
    
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN ; 
        solve(root, res) ; 
        
        return res ; 
    }
};

int main(){
    
}

/*
leetcode : https://leetcode.com/problems/binary-tree-maximum-path-sum/
gfg : https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/#
*/
