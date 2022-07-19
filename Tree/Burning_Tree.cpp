// problem link : https://practice.geeksforgeeks.org/problems/burning-tree/1


class Solution {

    void mark_parent(Node*root,unordered_map<Node*,Node*>&parent)
    {
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto x=q.front(); q.pop();
                if(x->left!=nullptr)
                {
                    q.push(x->left);
                    parent[x->left]=x;
                }
                if(x->right!=nullptr)
                {
                    q.push(x->right);
                    parent[x->right]=x;
                }
            }
        }
        
    }


  public:
     Node*target;
     
     bool check=false;
     
     void mark_target(Node*root, int t)
     {
         if(root==nullptr or check==true ){return;}
         if(t==root->data)
         {
             target=root;
             check=true;
             return;
         }
         mark_target(root->left,t);
         mark_target(root->right,t);
     }
     
    int minTime(Node* root, int t) 
    {
        int last_level=0;
        check=false;  // to remove error of global cache
        
        unordered_map<Node*,Node*> parent;
        unordered_map<Node*,bool>visited;

        mark_target(root,t);
        
        mark_parent(root,parent);
        
        queue<Node*>q;
        
        q.push(target);
        visited[target]=true;
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto x=q.front();
                q.pop();
                if(x->left!=nullptr and visited[x->left]!=true)
                {
                    q.push(x->left);
                    visited[x->left]=true;
                }
                if(x->right!=nullptr and visited[x->right]!=true)
                {
                    q.push(x->right);
                    visited[x->right]=true;
                }
                if(parent[x]!=nullptr and visited[parent[x]]!=true)
                {
                    q.push(parent[x]);
                    visited[parent[x]]=true;
                }
            }
            last_level++;
        }

        
        return last_level-1;
    
        
    }
};
