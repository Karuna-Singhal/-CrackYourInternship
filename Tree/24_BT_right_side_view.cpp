#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rightView(TreeNode *root, vector<int> &ans, int level)
{
  if (root == NULL)
    return;
  if (ans.size() == level)
    ans.push_back(root->val);

  rightView(root->right, ans, level + 1);
  rightView(root->left, ans, level + 1);
}

vector<int> rightSideView(TreeNode *root)
{
  vector<int> ans;
  rightView(root, ans, 0);
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  vector<int> ans = rightSideView(root);

  for (auto x : ans)
    cout << x << " ";

  return 0;
}