
#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

void check(TreeNode* r)
{

}

int main()
{
  TreeNode* root = new TreeNode(20);




  check(root);
}
