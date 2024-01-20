class Solution
{
    public:
    int help(Node* root,int& ans)
    {
        //base case
        if(!root)
        return 0;
        
        //recursive callls
        //and small calculation
        int left=help(root->left,ans);
        int right=help(root->right,ans);
        
        ans+=abs(left)+abs(right);
        
        return root->key+left+right-1;
    }
    int distributeCandy(Node* root)
    {
        int ans=0;
        int call=help(root,ans);
        return ans;
    }
};
