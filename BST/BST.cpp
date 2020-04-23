#include<iostream>
using namespace std ;
#include<queue>
class Node
{
  public :
  int data ;
  Node* left ;
  Node* right ;
  Node(int data)
  {
    this->data=data ;
    left=NULL ;
    right=NULL ;
  }
};
class BinarySearchTree {
    Node* root ;
    public :
    BinarySearchTree()
    {
      root=NULL ;
    }
    ~BinarySearchTree()
    {
      delete root ;
    }
    private :
    Node* insert(Node* root,int data)
    {
       if(root==NULL)
       {   Node* newroot=new Node(data) ;
           return newroot ;
       }
       if(data<root->data)
       {
           root->left=insert(root->left,data) ;
           return root ;
       }
        else
        {
            root->right=insert(root->right,data) ;
             return root ;
        }
    }
     

    Node* deleteData(Node* node,int data)
    {
        if(node==NULL)
            return NULL ;
        if(data>node->data)
        { node->right=deleteData(node->right,data) ;
          return node ;
        }
        else if(data<node->data)
        {   node->left=deleteData(node->left,data) ;
            return node ;
        }
        else
        {
          if(node->left==NULL && node->right==NULL)
          {
              delete node ;
              return NULL ;
          }
          else if(node->left==NULL)
          {
             Node* temp=node->right ;
              node->right=NULL ;
              delete node ;
              return temp ;
          }
          else if(node->right==NULL)
          {
            Node* temp=node->left ;
              node->left=NULL ;
              delete node ;
              return temp ;
          }
          else
          {
             Node* minNode=node->right ;
             while(minNode->left!=NULL)
             {
                 minNode=minNode->left ;
             }
             int rightmin=minNode->data ;
              node->data=rightmin ;
              node->right=deleteData(node->right,rightmin) ;
              return node ;
          }

        }

    }
void printTree(Node* root) {
     if(root==NULL)
     {  
         return ;
    }
     if(root->left==NULL && root->right==NULL)
     {
      cout<<root->data<< " : End node"<<endl;
     } 
     else{
     cout << root->data << ":"<<endl ;
     }
     if(root->left!=NULL && root->right!=NULL)
    {
         cout << " Left Node=" << root->left->data<<endl << "Right Node=" << root->right->data << endl ;
    }
     else if(root->left!=NULL)
     {
         cout << " Left Node=" << root->left->data << endl ;
     }
     else if(root->right!=NULL)
      {
         cout << " Right Node=" << root->right->data << endl ;
     }
     printTree(root->left) ;
     printTree(root->right) ;

}
bool search(Node* root,int input)
    {
       if(root==NULL)
           return false ;
       if(root->data==input)
            return true ;
       else if(root->data>input)
           return search(root->left,input) ;
       else
           return search(root->right,input) ;

    }
    public :
    void insert(int data)
    {
      this->root=insert(this->root,data) ;
    }
    void deleteData(int data)
    {
      this->root=deleteData(this->root,data) ;
    }
     bool checkdata(int input)
    {
       return search(root,input) ;
    }
    void printTree()
    {
        printTree(root) ;
    }

};

int main()
{
  BinarySearchTree bst ;
  bst.insert(2) ;
  bst.insert(0) ;
  bst.insert(1) ;
  bst.insert(9) ;
  bst.insert(1) ;
  bst.insert(5) ;
  bst.insert(2) ;
  bst.insert(6) ;
  bst.printTree() ;
  bst.deleteData(2) ;
  bst.deleteData(1) ;
  bst.deleteData(0) ;
  bst.deleteData(9) ;
  cout <<endl<< endl ;
  bst.printTree() ;
  cout<<endl<<endl;
  if(bst.checkdata(1))
  {
    cout<<"1 is present in the BST"<<endl;
  }
  else
  {
   cout<<"1 is not present in the BST"<<endl; 
  }
if(bst.checkdata(5))
  {
    cout<<"5 is present in the BST"<<endl;
  }
  else
  {
   cout<<"5 is not present in the BST"<<endl; 
  }
if(bst.checkdata(2))
  {
    cout<<"2 is present in the BST"<<endl;
  }
  else
  {
   cout<<"2 is not present in the BST"<<endl; 
  }
if(bst.checkdata(6))
  {
    cout<<"6 is present in the BST"<<endl;
  }
  else
  {
   cout<<"6 is not present in the BST"<<endl; 
  }
return 0;

}