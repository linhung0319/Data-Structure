#include <cstddef>
#include <iostream>
#include "BinaryExpressionTree.h"
#include "Trans2Postfix.h"
#include "Stack.h"
#include "Token.h"
using namespace std;

void BinaryExpressionTree::traverse(TreeNode *n, Mode mode)
{
  switch (mode)
  {
    case DLR:
      traverseDLR(n);
      break;
    case LDR:
      traverseLDR(n);
      break;
    case LRD:
      traverseLRD(n);
      break;
  }
}

void BinaryExpressionTree::traverseDLR(TreeNode* n)
{
  if(n == NULL) return;
  else
  {
    _traverseResult.push_back(n->data);
    traverseDLR(n->left);
    traverseDLR(n->right);
  }
  return;
}

void BinaryExpressionTree::traverseLDR(TreeNode* n)
{
  if(n == NULL) return;
  else
  {
    if ( (n->data == '+' || n->data == '-') && n != _root ) _traverseResult.push_back('(');
    traverseLDR(n->left);
    _traverseResult.push_back(n->data);
    traverseLDR(n->right);
    if ( (n->data == '+' || n->data == '-') && n != _root) _traverseResult.push_back(')');
  }
  return;
}

void BinaryExpressionTree::traverseLRD(TreeNode* n)
{
  if(n == NULL) return;
  else
  {
    traverseLRD(n->left);
    traverseLRD(n->right);
    _traverseResult.push_back(n->data);
  }
  return;
}

BinaryExpressionTree::BinaryExpressionTree(string inorder_s)
:_traverseResult("")
{
  string postfix = "";
  trans2Postfix(inorder_s, postfix);
  createBTree(postfix);
}

TreeNode *BinaryExpressionTree::root()
{
  return _root;
}

string BinaryExpressionTree::traverseResult()
{
  return _traverseResult;
}

BinaryExpressionTree::createBTree(string &s)
{
  TokenType t;
  Stack<TreeNode *> stack(s.length());
  for (size_t i = 0 ; i < s.length() ; ++i)
  {
    t = getOneToken(s, i);
    if (t == OPERAND) stack.push( new TreeNode(s[i]) );
    else
    {
      TreeNode *node = new TreeNode(s[i]);
      node->right = stack.pop();
      node->left = stack.pop();
      stack.push(node);
    }
  }
  _root = stack.pop();
}
