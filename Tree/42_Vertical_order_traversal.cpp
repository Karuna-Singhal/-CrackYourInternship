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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;

  map<int, map<int, vector<int>>> mp;
  queue<pair<pair<TreeNode *, int>, int>> q;
  q.push({{root, 0}, 0});

  while (!q.empty())
  {
    TreeNode *node = q.front().first.first;
    int dist = q.front().first.second;
    int level = q.front().second;
    q.pop();
    mp[dist][level].push_back(node->val);

    if (node->left)
      q.push({{node->left, dist - 1}, level + 1});
    if (node->right)
      q.push({{node->right, dist + 1}, level + 1});
  }

  for (auto p : mp)
  {
    vector<int> col;
    for (auto q : p.second)
    {
      sort(q.second.begin(), q.second.end());
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
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
  vector<vector<int>> ans = verticalTraversal(root);

  for (int i = 0; i < ans.size(); i++)
  {
    for (auto x : ans[i])
      cout << x << " ";
    cout << endl;
  }

  return 0;
}