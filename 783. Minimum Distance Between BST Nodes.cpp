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
    int minDiffInBST(TreeNode* root)
    {
        TreeNode* curr = root;
        vector<int> nodes;

        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr)
                {
                    pred = pred->right;
                }

                if(pred->right==NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    nodes.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else
            {
                nodes.push_back(curr->val);
                curr = curr->right;
            }
        }

        int min = INT_MAX;
        for(int i = 1;i<nodes.size();i++)
        {
            if(nodes[i]-nodes[i-1]<min)
            {
                min = nodes[i]-nodes[i-1];
            }
        }

        return min;
    }
};