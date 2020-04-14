#include<bits/stdc++.h>
using namespace std;
class node{

public:
	int data;
	node *next;

	node(int n)
	{
		data=n;
		next=NULL;
	}
};
void insertathead(node *&head,int n)
{
	node *temp=new node(n);
	temp->next=head;
	head=temp;
	return;
}
void print(node *head )
{
	while( (head->next)!=NULL )
	{
		cout<<head->data<<",";
		head=head->next;
	}
	cout<<head->data<<endl;
	return;
}
int main()
{

	node *head=NULL;
	build(head);
	print(head);
return 0;
}