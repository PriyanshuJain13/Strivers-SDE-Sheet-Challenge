int findCeil(BinaryTreeNode<int> *node, int x){
    if(!node)
    {
        return -1;
    }
    if(node->data == x)
    {
        return node->data;
    }else if(node->data < x)
    {
        return findCeil(node->right,x);
    }

    int ceil = findCeil(node->left,x);

    return ceil >= x ? ceil : node->data;
}
