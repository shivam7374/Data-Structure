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

int main()
{	
	node*root=buildtree();
	printpretree(root);
	// cout<<endl;
	// printintree(root);
	// cout<<endl;
	// printposttree(root);
	// cout<<endl;
	// int h=height(root);
	// cout<<"Height : "<<h<<endl;
	// cout<<"Enter the kth level : ";
	// int k;
	// cin>>k;
	// cout<<endl;
	// printklevel(root,k);
	// cout<<endl;
	// printalllevels(root);
	// cout<<endl;
	// cout<<count(root)<<endl;
	return 0;
}