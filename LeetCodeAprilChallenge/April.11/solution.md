### 543. Diameter of Binary Tree

这个题麻烦的地方在于直径不一定过根节点，所以要把每个点的左右两列都扫描一遍，开始我想的是从根节点开始每个节点都求一遍，但是感觉这样做了太多重复的工作，后来想的是用递归从底层进行，这样从下向上进行就进行一次遍历就可以了

```
int max = 0;

int search(TreeNode* root)
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
```
