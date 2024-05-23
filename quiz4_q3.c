// CODE: Library(s) you need
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// CODE: Write the function createNode()
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}


// Function to perform an in-order traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

// CODE: You need a recursive function to deallocate memory of the binary tree

void deallocate(struct Node* root){
    if (root != NULL) {
        deallocate(root->left);
        deallocate(root->right);
        free(root);
    }
}

int main() {

    struct Node *root1 = createNode(2,NULL,NULL);
    root1->left = createNode(5,NULL,NULL);
    root1->right = createNode(6,NULL,NULL);
    root1->right->right = createNode(3,NULL,NULL);

    // Perform in-order traversal to display the binary tree
    printf("In-order traversal of the binary tree: ");
    inorderTraversal(root1);
    printf("\n");

    // Cleanup: Free memory
    // CODE: deallocateTree(root1);
    return 0;
}
