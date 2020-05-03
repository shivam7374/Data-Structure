#include<iostream>
using namespace std ;
class stack
{
    int* data ;
    int currentsize ;
    int maxsize ;

 public :
  stack()
  {
      data=new int[5] ;
      currentsize=0 ;
      maxsize=5 ;
  }
  int size()
  {
      return currentsize ;
  }
  bool isempty()
  {	
      return (currentsize==0) ;
  }
  void push(int element)
  {   if(currentsize==maxsize)
       {
           int* newdata=new int[2*maxsize] ;
           for(int i=0;i<maxsize;i++)
           {
               newdata[i]=data[i] ;
           }
           delete [] data ;
           data=newdata ;
           maxsize*=2 ;
       }
      data[currentsize]=element ;
      currentsize++ ;
  }
  void pop()
   {   if(isempty())
        {
            cout << "stack is Empty " << endl ;
            
        }
      currentsize-- ;
      cout<<"Element poped out of stack "<<data[currentsize]<<endl ;
  }
  void top()
  {
      if(isempty())
        {
            cout << "stack is Empty " << endl ;
        }
      cout<<"Element at top of stack "<<data[currentsize-1]<<endl ;
  }
};
int main()
{
 stack s ;
 s.push(6) ;
 s.push(2) ;
 s.push(5) ;
 s.push(1) ;
 cout <<"Current Size of stack is " <<s.size() << endl ;
 s.top();
 if(s.isempty())
 {
 	cout<<"Stack is Empty"<<endl;
 }
 else{
 	cout<<"Stack is not empty"<<endl;
 }
 s.pop();
 cout <<"Current Size of stack is " <<s.size() << endl ;
  s.top();
 if(s.isempty())
 {
 	cout<<"Stack is Empty"<<endl;
 }
 else{
 	cout<<"Stack is not empty"<<endl;
 }
 s.pop();
cout <<"Current Size of stack is " <<s.size() << endl ;
  s.top();
 if(s.isempty())
 {
 	cout<<"Stack is Empty"<<endl;
 }
 else{
 	cout<<"Stack is not empty"<<endl;
 }
 s.pop();
cout <<"Current Size of stack is " <<s.size() << endl ;
  s.top();
 if(s.isempty())
 {
 	cout<<"Stack is Empty"<<endl;
 }
 else{
 	cout<<"Stack is not empty"<<endl;
 }
 s.pop();

 return 0;
}