#include <stdio.h>

typedef struct node Node;
struct node{
    Node *left;
    Node *right;
    int val; 
};

int height(Node *root){
    if(root == NULL)
        return 0;
    
    return height(root->left) + height(root->right) + 1;
}

void levelOrder(Node *root, int **levelOrderArray, int numLevels, int currentLevel){
    if(root == NULL)
        return;
    
}

int main()
{
    Node *root; // assuming it points to root of tree
    int numLevels = height(root);
    int* levelOrderArray[numLevels]; //  each element will be an array containing
    levelOrder(root, levelOrderArray, numLevels, 0);
}