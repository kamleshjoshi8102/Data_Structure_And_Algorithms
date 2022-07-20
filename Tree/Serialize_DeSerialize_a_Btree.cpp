/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==nullptr)
        {
            return s;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            if(x==NULL)
            {
                s.append("#,");
            }
            else
            {
               s.append(to_string(x->val)+','); 
            }
            if(x!=nullptr)
            {
                q.push(x->left);
                q.push(x->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        {
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s,str,','); // used to divide string into objects which can be accesed individually
        
        TreeNode*root = new TreeNode(stoi(str));
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            
            auto x=q.front();
            q.pop();
                
            getline(s,str,','); // going to it's next , element
            
            if(str=="#")
            {
                x->left=nullptr;
            }
            else
            {
                TreeNode * leftNode=new TreeNode(stoi(str));
                x->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            
            if(str=="#")
            {
                x->right=nullptr;
            }
            else
            {
                TreeNode*rightNode=new TreeNode(stoi(str));
                x->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;        
    
    }
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
