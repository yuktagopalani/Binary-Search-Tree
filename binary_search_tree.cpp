//Implementation of BST

#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node  *l=NULL, *r=NULL;		// l->left and r->right
    int data;					//The nos. you want to store in the tree
};
struct node *createnode (int x)						//function to generate a new node
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));	//dynamic memory allocation
    temp->data=x;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}
struct node *insert(struct node* root, int x)		//function to insert the data into the tree
{
    if(root==NULL)
    {
        root=createnode(x);
        
    }
    else
    {
        if(x<=root->data)
        root->l=insert(root->l,x);
        else
        {
            root->r=insert(root->r,x);
        }
    }
    return root;
}
int height(struct node* root)				//function that returns the height of the tree
{
    if(root==NULL)
    return -1;
    
    else
    {
        int hl=height(root->l);
        int hr=height(root->r);
        return (max(hl,hr) + 1);
    }
}
void inorder(struct node* root)				//The inorder traversal
{
    if(root==NULL)
    return;
    
    inorder(root->l);
    cout<<root->data<<endl;
    inorder(root->r);
    
    
}
int main()						//main function
{
    
    struct node *root=NULL;
    int n;
    // no. of nodes=n.
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        root=insert(root,x);
        
    }
    
    cout<<height(root)<<endl;
    
    inorder(root);

}