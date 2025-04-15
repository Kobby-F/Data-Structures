
// 144.Binary Tree Prorder Transversal
#include <stdio.h>
#include <stdlib.h>

// Helper function for the preorder traversal
void preorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }

    result[*index] = root->val;
    (*index)++;

    preorderHelper(root->left, result, index);
    preorderHelper(root->right, result, index);
}

// Function to return the preorder traversal of the binary tree
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    int index = 0;

    preorderHelper(root, result, &index);

    *returnSize = index;

    return result;
}



//94. Binary Tree Inorder Transversal
#include <stdlib.h>

// Helper function for the inorder traversal
void inorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }

    inorderHelper(root->left, result, index);    // Traverse left subtree
    result[*index] = root->val;                  // Visit root
    (*index)++;
    inorderHelper(root->right, result, index);   // Traverse right subtree
}

// Main function to return the inorder traversal of the binary tree
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));  // Allocate space for result
    int index = 0;

    if (root == NULL) {
        *returnSize = 0;
        return result;  // Return empty array if tree is empty
    }

    inorderHelper(root, result, &index);             // Fill result array
    *returnSize = index;                             // Set the size of the result

    return result;
}



