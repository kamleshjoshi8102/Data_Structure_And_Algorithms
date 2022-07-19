/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    void mark_parent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent,TreeNode*target)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto x=q.front();q.pop();
            if(x->left)
            {
                parent[x->left]=x;
                q.push(x->left);
            }
            if(x->right)
            {
                parent[x->right]=x;
                q.push(x->right);
            }
        }
    }
    
    
    public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        
        
        mark_parent(root,parent,target);// function for marking parent and it's passed as address to this function
        
        unordered_map<TreeNode*,bool>visited; // since we have to traverse back to root sometime so to avoid multiple values of same node we need to have a visited map
        
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        
        
        // for(auto x:parent)
        // {
        //     cout<<x.first->val<<" "<<x.second->val<<endl;
        // }
        
        int curr_level=0;
        
        while(!q.empty()) // using BFS approach here
        {
            if(curr_level==k)
            {
                break;
            }
            curr_level++; // increasing level of every nodes that we traverse
            
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                auto x=q.front(); q.pop();

                if(x->left!=nullptr and visited[x->left]!=true) // checking it's left child
                {
                    q.push(x->left);
                    visited[x->left]=true;
                }

                if(x->right!=nullptr and visited[x->right]!=true) // checking it's right child
                {
                    q.push(x->right);
                    visited[x->right]=true;
                }

                if(parent[x]!=nullptr and visited[parent[x]]!=true) // checking it's parent with the help of that parent map
                {
                    q.push(parent[x]);
                    visited[parent[x]]=true;
                }
            }
        }
        
        vector<int>ans; // at last it's the answer array which we will return 
        
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            ans.push_back(x->val);
        }
        
        return ans;
    
    }
    
    
};







