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
    int minDepth(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0;i<size;i++)
            {
                TreeNode* rem = q.front();
                q.pop();

                if(rem==NULL)
                {
                    continue;
                }
                if(rem->left==NULL && rem->right==NULL)
                {
                    return depth;
                }

                q.push(rem->left);
                q.push(rem->right);
            }
            depth += 1;
        }

        return 0;
    }
};