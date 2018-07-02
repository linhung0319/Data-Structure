#ifndef BINARYEXPRESSIONTREE_H
#define BINARYEXPRESSIONTREE_H

#include <string>

enum Mode{DLR, LDR, LRD};

struct TreeNode
{
  TreeNode(char c):data(c), left(NULL), right(NULL){};
  char data;
  TreeNode *left, *right;
};

class BinaryExpressionTree
{
public:
  BinaryExpressionTree(std::string);

  TreeNode *root();
  std::string traverseResult();

  void traverse(TreeNode *, Mode);
  void traverseDLR(TreeNode *);
  void traverseLDR(TreeNode *);
  void traverseLRD(TreeNode *);

private:
  createBTree(std::string &);

  TreeNode *_root;
  std::string _traverseResult;
};

#endif
