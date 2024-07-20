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

vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int size = q.size();
    vector<int> arr;
    while (size--)
    {
      TreeNode *temp = q.front();
      q.pop();
      arr.push_back(temp->val);
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
    ans.push_back(arr);
    arr.clear();
  }
  return ans;
}

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  vector<vector<int>> ans = levelOrder(root);

  for (int i = 0; i < ans.size(); i++)
  {
    for (auto x : ans[i])
      cout << x << " ";
    cout << endl;
  }

  return 0;
}