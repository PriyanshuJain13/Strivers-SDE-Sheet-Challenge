
class Codec {
public:

    string serialize(TreeNode* root) {
        if(root == NULL)
        {
            return "";
        }

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {

           TreeNode* temp = q.front();
           q.pop();
           if(temp==NULL) 
           {
             ans += "#,";
           }else {
               ans += to_string(temp->val);
               ans += ",";
           }

           if(temp != NULL){
               q.push(temp->left);
               q.push(temp->right);            
           }
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) 
        {
            return NULL; 
        }

        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};
