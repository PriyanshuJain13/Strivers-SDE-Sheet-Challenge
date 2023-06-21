

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   queue<Node*> q;
   if(root == NULL) return res;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       res.push_back(q.front()->data);
       for(int i=0; i<n; i++){
           if(q.front()->left != NULL) q.push(q.front()->left);
           if(q.front()->right != NULL) q.push(q.front()->right);
           q.pop();
       }
   }
   return res;
}
