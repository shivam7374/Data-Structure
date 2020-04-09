#include <iostream>
using namespace std;
class Queue{
    int*arr;
    int front;
    int rear;
    int ms;
    int cs;

public:
    Queue(int ds=4){
        front = 0;
        ms = ds;
        rear = ms-1;
        arr = new int[ms];
        cs = 0;
    }
    //Enqueue at rear+1
    bool isFull(){
        return cs==ms;
    }
    bool isEmpty(){
        return cs==0;
    }
    void push(int data){
        if(!isFull()){
            rear = (rear+1)%ms;
            arr[rear] = data;
            cs++;
        }
    }
    void pop(){
        if(!isEmpty()){
        	cout<<"Element poped out is "<<arr[front]<<endl;
            front = (front+1)%ms;
            cs--;
        }
    }
    int intFront(){
        return arr[front];
    }
};




int main() {
   Queue q(10);

   for(int i=1;i<=6;i++){
       q.push(i);
   }
   q.pop();
   q.push(8);

   while(!q.isEmpty()){
       cout<<"Element on the front of Queue is "<<q.intFront()<<endl;
       q.pop();
   }

    return 0;
}
