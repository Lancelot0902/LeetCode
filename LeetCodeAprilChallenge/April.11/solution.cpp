struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max = 0;

int search(TreeNode *root)
{
    if (root == nullptr)
        return;
    int l = search(root->left);
    int r = search(root->right);
    max = std::max(l + r, max);
    return std::max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    search(root);
    return max;
}
