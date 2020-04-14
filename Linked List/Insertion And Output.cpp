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
	insertathead(head,5);
	insertathead(head,3);
	insertathead(head,2);
	insertathead(head,1);
	print(head);
return 0;
}