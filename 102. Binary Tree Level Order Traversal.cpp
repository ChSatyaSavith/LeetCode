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
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<TreeNode*> q;
        vector<vector<int>> toreturn;
        if(root==NULL)
        {
            return toreturn;
        }
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0;i<size;i++)
            {
                level.push_back(q.front()->val);
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            toreturn.push_back(level);
        }

        return toreturn;
    }
};