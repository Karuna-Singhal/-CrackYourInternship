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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;

  queue<TreeNode *> q;
  q.push(root);
  int level = -1;
  while (!q.empty())
  {
    int size = q.size();
    level++;
    vector<int> subans;
    while (size--)
    {
      TreeNode *node = q.front();
      q.pop();
      subans.push_back(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    if (level % 2 != 0)
      reverse(subans.begin(), subans.end());
    ans.push_back(subans);
    subans.clear();
  }
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(5);
  vector<vector<int>> ans = zigzagLevelOrder(root);

  for (int i = 0; i < ans.size(); i++)
  {
    for (auto x : ans[i])
      cout << x << " ";
    cout << endl;
  }

  return 0;
}