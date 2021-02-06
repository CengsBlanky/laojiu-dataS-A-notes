#include "BinaryTree.h"

void testBinaryTree();

int main(int argc, char const *argv[])
{
    testBinaryTree();
    return 0;
}

void testBinaryTree() {
    BinaryTree * tree = malloc(sizeof(BinaryTree));
    InitBinaryTree(tree);
    tree->root = malloc(sizeof(BinaryTreeNode));
    CreateBinaryTree(tree->root);

    PreOrderPrint(tree->root);
    puts("");

    InOrderPrint(tree->root);
    puts("");

    puts("no recursive print:");

    InOrderPrint_Stack(tree->root);
    puts("");
    
    free(tree->root);
}