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
void insertattail(node* &head,int n)
{
	node*temp=new node(n);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	node*temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	temp->next=NULL;
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
	insertathead(head,5);
	insertathead(head,3);
	insertathead(head,2);
	insertathead(head,1);
	insertattail(head,7);
	insertattail(head,8);
	insertattail(head,9);
	print(head);
return 0;
}