/** 101. Symmetric Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Function prototype
bool isMirror(struct TreeNode* t1, struct TreeNode* t2);

// Helper function to check if two trees are mirror images
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}



/* 200. Number of Islands */
void dfs(char** grid, int i, int j, int rows, int cols) {
    // Boundary check
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == '0') {
        return;
    }

    // Mark current cell as visited
    grid[i][j] = '0';

    // Visit all four directions
    dfs(grid, i + 1, j, rows, cols);
    dfs(grid, i - 1, j, rows, cols);
    dfs(grid, i, j + 1, rows, cols);
    dfs(grid, i, j - 1, rows, cols);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0) return 0;

    int count = 0;
    int rows = gridSize;
    int cols = gridColSize[0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, rows, cols);
            }
        }
    }

    return count;
}

