// problem link : https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

class BSTIterator
{
    stack<Node*>st;
    bool reverse=false;
    
    void pushall(Node*root)
    {
        while(root)
        {
            st.push(root);
            if(reverse==true)
            {
                root=root->right;
            }
            else
            {
                root=root->left;
            }
        }
    }
    
    public:
       BSTIterator(Node*root,bool isReverse)
        {   
            reverse=isReverse;
            pushall(root);
        }
    bool hasnext(Node*root)
    {
        return st.size()>0;
    }
    
    int next(){
        Node*get=st.top();
        st.pop();
        if(!reverse)
        {
            pushall(get->right);
        }
        else
        {
            pushall(get->left);
        }
        return get->data;
    }
    
};


class Solution{
  public:
    int isPairPresent(struct Node *root, int target)
    {
        if(root==nullptr)
        {
            return false;
        }
        BSTIterator l (root,false);
        BSTIterator r (root,true);
        
        
        int i=l.next();
        int j=r.next();
        
        while(i<j)
        {
            if(i+j==target)
            {
                return true;
            }
            else if(i+j<target)
            {
                i=l.next();
            }
            else
            {
                j=r.next();
            }
        }
    
    
    
        return false;
        
        
    }
    

    
    
    
};
