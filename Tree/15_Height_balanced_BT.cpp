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

pair<int, bool> check(TreeNode *root)
{
  pair<int, bool> p;
  if (root == NULL)
  {
    p.first = 0;
    p.second = true;
    return p;
  }

  pair<int, bool> left = check(root->left);
  pair<int, bool> right = check(root->right);

  p.first = max(left.first, right.first) + 1;
  p.second = false;
  if (abs(left.first - right.first) <= 1 && left.second && right.second)
  {
    p.second = true;
  }

  return p;
}

bool isBalanced(TreeNode *root)
{
  if (root == NULL)
    return true;

  pair<int, bool> ans = check(root);

  return ans.second;
}

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(5);
  bool ans = isBalanced(root);

  cout << ans;

  return 0;
}