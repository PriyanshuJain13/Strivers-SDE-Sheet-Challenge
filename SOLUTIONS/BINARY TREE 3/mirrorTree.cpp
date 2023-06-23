class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL) return;
        
        mirror(node->left);
        mirror(node->right);
        
        if(node->left == NULL && node->right == NULL) 
        {
           return;
        }
        swap(node->left, node->right);
        return;
    }
};
