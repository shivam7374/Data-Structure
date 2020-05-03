#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node*next;
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
int search(node *head,int n,node *end)
{
	node *temp=head;
	while(temp!=end)
	{
		if(temp->data==n)
		{
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}
void removeduplicate(node *&head)
{	
	node *temp1=head;
	node *prev=NULL;
	while( temp1!=NULL)
	{
					if(search(head,temp1->data,temp1))
					{	
						prev->next=temp1->next;
				}
				
		else
			{
				prev=temp1;
			}
		temp1=temp1->next;
	}
	return;
}

// void removeduplicate(node *&head)
// {	
// 	node *temp1=head;
// 	node *prev=NULL;
// 	while( temp1!=NULL)
// 	{	int flag=0;	
// 		node *temp=head;
// 		while(temp!=temp1)
// 			{
// 				if(temp->data==temp1->data)
// 					{	
// 						flag=1;
// 						prev->next=temp1->next;
// 						break;
// 					}
// 				temp=temp->next;
// 			}
// 		if(flag==0)
// 			{
// 				prev=temp1;
// 			}
// 		temp1=temp1->next;
// 	}
// 	return;
// }
int main()
{
	// cout<<"Hello";
	node* head=NULL;
	insertathead(head,1);
	insertathead(head,1);
	insertathead(head,2);
	insertathead(head,1);
	insertathead(head,1);
	insertathead(head,2);
	insertathead(head,2);
	insertathead(head,2);
	insertathead(head,3);
	insertathead(head,3);
	insertathead(head,3);
	insertathead(head,3);
	insertathead(head,2);
	print(head);
	removeduplicate(head);
	print(head);
	return 0;
}