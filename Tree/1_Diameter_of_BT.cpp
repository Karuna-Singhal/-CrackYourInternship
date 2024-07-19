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

pair<int, int> check(TreeNode *root)
{
  pair<int, int> p, left, right;
  if (root == NULL)
  {
    p.first = p.second = 0;
    return p;
  }
  left = check(root->left);
  right = check(root->right);
  p.first = max(left.first, right.first) + 1;
  int d1 = left.second;
  int d2 = right.second;
  int d3 = left.first + right.first;
  p.second = max(d1, max(d2, d3));
  return p;
}

int diameterOfBinaryTree(TreeNode *root)
{
  if (root == NULL)
    return 0;

  pair<int, int> p = check(root);

  return p.second;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  int diameter = diameterOfBinaryTree(root);
  cout << "Diameter of the binary tree is: " << diameter << endl;

  return 0;
}