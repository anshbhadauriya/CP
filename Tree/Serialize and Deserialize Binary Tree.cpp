class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root==NULL)
        return "";

        string temp="";

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){

            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL){
             temp+="#,"; 
             continue;
            }  
            temp+=to_string(curr->val)+",";

          
                q.push(curr->left);

                q.push(curr->right);
            
            
        }
        cout<<temp<<endl;

        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.empty()) return NULL;

        stringstream ss(data);

        string segment="";

        getline(ss,segment,',');

        TreeNode* dummy= new TreeNode(stoi(segment));

        queue<TreeNode*>q;

        q.push(dummy);

        while(!q.empty()){

            TreeNode* curr=q.front();
            q.pop();
            
            //left subtree ke lie
            getline(ss,segment,',');

            if(segment!="#"){
                curr->left=new TreeNode(stoi(segment));
                q.push(curr->left);
            }


            //right subtree ke lie
            getline(ss,segment,',');

            if(segment!="#"){
                curr->right=new TreeNode(stoi(segment));
                q.push(curr->right);
            }

        }

        return dummy; 
        
    }
};

/*
TC-> O(n)
SC-> O(n)
*/
