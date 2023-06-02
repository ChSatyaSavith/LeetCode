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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> toreturn;
        TreeNode* cur = root;

        while(cur!=NULL)
        {
            if(cur->right==NULL)
            {
                toreturn.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                TreeNode* prev = cur->right;
                while(prev->left!=NULL && prev->left!=cur)
                {
                    prev = prev->left;
                }

                if(prev->left==NULL)
                {
                    prev->left = cur;
                    toreturn.push_back(cur->val);
                    cur = cur->right;
                }
                else
                {
                    prev->left = NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(toreturn.begin(),toreturn.end());
        return toreturn;
    }
};