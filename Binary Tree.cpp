#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node* left;
node* right;
node(int data){
	this->data=data;
	left=NULL;
	right=NULL;
}
};
node* buildtree()
{
	cout<<"Enter : ";
	int a;
	cin>>a;
	if(a==-1)
	{
		return NULL;
	}
	node *root=new node(a);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
void printpretree(node* root)
{
	if(root==NULL)// do not use root->data==-1 as -1 is not stored anywhere it is just for identification of null
	{
		return;
	}
	cout<<root->data<<" ";
	printpretree(root->left);
	printpretree(root->right);
	return;
}
void printintree(node* root)
{
	if(root==NULL)
	{
		return;
	}
	printintree(root->left);
	cout<<root->data<<" ";
	printintree(root->right);
	return;
}
void printposttree(node* root)
{
	if(root==NULL)
	{
		return;
	}
	printposttree(root->left);
	printposttree(root->right);
	cout<<root->data<<" ";
	return;
}
int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	return(max(h1,h2)+1);
}
void printklevel(node *root,int k)
{
	if(root==NULL)
	{
		return;
	}
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printklevel(root->left,k-1);
	printklevel(root->right,k-1);
	return;
}

int main()
{	
	node*root=buildtree();
	printpretree(root);
	cout<<endl;
	printintree(root);
	cout<<endl;
	printposttree(root);
	cout<<endl;
	int h=height(root);
	cout<<"Height : "<<h<<endl;
	cout<<"Enter the kth level : ";
	int k;
	cin>>k;
	cout<<endl;
	printklevel(root,k);
	cout<<endl;
	// printalllevels(root);
	// cout<<endl;
	// cout<<count(root)<<endl;
	return 0;
}