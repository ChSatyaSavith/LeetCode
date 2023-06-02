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
    144. Binary Tree Preorder Traversal
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        TreeNode* cur = root;
        vector<int> toreturn;

        while(cur!=nullptr)
        {
            if(cur->left == nullptr)
            {
                toreturn.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode* prev = cur->left;
                while (prev -> right != NULL && prev -> right != cur)
                {
                    prev = prev -> right;
                }
                if (prev -> right == NULL) 
                {
                    prev -> right = cur;
                    toreturn.push_back(cur -> val);
                    cur = cur -> left;
                } 
                else 
                {
                    prev -> right = NULL;
                    cur = cur -> right;
                }
            }
            
        }

        return toreturn;
    }

};




    // Initialize current as root
    // While current is not null:
    //     If current does not have a left child:
    //     (i) Print current's data.
    //     (ii) Go to the right, i.e., current = current.right
    //     Else:
    //     (i)Make current as the right child of the rightmost node in current's left subtree.
    //     (ii)Go to this left child, i.e., current = current.left.
