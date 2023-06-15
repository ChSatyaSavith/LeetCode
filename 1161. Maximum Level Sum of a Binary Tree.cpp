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
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int sum = INT_MIN;
        int level = 0;
        int final = 0;
        while(!q.empty())
        {
            level++;
            int temp_sum = 0;
            int loop = q.size();
            for(int i = 0;i<loop;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
                temp_sum += temp->val;
            }
            if(temp_sum>sum)
            {
                final = level;
                sum = temp_sum;
            }
            
            
        }

        return final;
    }
};