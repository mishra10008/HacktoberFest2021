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
class Solution
{
public:
   TreeNode *bst(TreeNode *&root, int value)
   {
      if (root == NULL)
      {
         return root = new TreeNode(value);
         cout << "yes ";
      }

      if (root->val > value)
      {
         root->left = bst(root->left, value);
      }
      else
      {
         root->right = bst(root->right, value);
      }
      return root;
   }

   TreeNode *bstFromPreorder(vector<int> &preorder)
   {
      TreeNode *root = NULL;
      int n = preorder.size();
      for (auto x : preorder)
      {
         bst(root, x);
      }
      return root;
   }
};