#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
        int data;
        node *lchild;
        node *rchild;
        node(int d)
        {
            data=d;
            lchild=NULL;
            rchild=NULL;
        }
};

int height(node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    int l=height(root->lchild);
    int r=height(root->rchild);
    return max(l,r)+1;
}


int main()
{
    node *root=buildtree();
    levelorder(root);





    return 0;
}
