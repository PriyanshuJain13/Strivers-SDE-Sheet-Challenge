int floorInBST(TreeNode<int> * root, int key)
{
    if (!root)
        return INT_MAX;

    if (root->val == key)
        return root->val;

    if (root->val > key)
        return floorInBST(root->left, key);

    int floorValue = floorInBST(root->right, key);

    return (floorValue <= key) ? floorValue : root->val;
}
