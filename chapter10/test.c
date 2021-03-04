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

    // puts("pre order:");
    // PreOrderPrint(tree->root);
    // puts("");

    // puts("in order:");
    // InOrderPrint(tree->root);
    // puts("");

    // puts("no recursive print:");

    // InOrderPrint_Stack(tree->root);
    // puts("");

    // puts("post order:");
    // PostOrderPrint(tree->root);
    // puts("");

    puts("Z order:");
    ZOrderPrint_Queue(tree->root);
    puts("");

    
    free(tree->root);
}