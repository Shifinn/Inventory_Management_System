#ifndef CODE202_TREE_H
#define CODE202_TREE_H

#include <iostream>
using namespace std;

// Define a structure to be used as the tree node
struct TreeNode
{
    int      Key;
    float    fValue;
    int      iValue;
    char     cArray[7];
    TreeNode *left;
    TreeNode *right;
};

class Tree
{
    private:
        TreeNode *root;

    public:
        Tree();
        ~Tree();
        bool isEmpty();
        TreeNode *SearchTree(int Key);
        bool Insert(TreeNode *newNode);
        bool Insert(int Key, float f, int i, char *cA);
        bool Delete(int Key);
        void PrintOne(TreeNode *T);
        void PrintTree();
    private:
        void ClearTree(TreeNode *T);
        TreeNode *DupNode(TreeNode * T);
        void PrintAll(TreeNode *T);
};

#endif