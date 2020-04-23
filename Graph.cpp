/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#include<queue>
#include<vector>
void print(int** edges,int n,bool* visited,vector<vector<int>*>* ans)
{
  queue<int> q ;
  vector<int>* v ;
  for(int i=0;i<n;i++)
  {
     if(!visited[i])
     {
       q.push(i) ;
       visited[i]=true ;
       v=new vector<int>() ;
     }
     else
        continue ;
     while(q.size()!=0)
    {
    int f=q.front() ;
    q.pop() ;
    v->push_back(f) ;
    for(int i=0;i<n;i++)
    {
      if(i==f)
          continue ;
      if(edges[f][i]==1 && visited[i]==false)
      {
         visited[i]=true ;
         q.push(i) ;
      }
    }
   }
   ans->push_back(v) ;
  }
}
int main() {
 int v,e ;
 cout << "Enter no of vertices in the graph : " ;
 cin >> v ;
 cout << "Enter no of edges in the graph : " ;
 cin >> e ;
 int** edges=new int*[v] ;
 for(int i=0;i<v;i++)
 {
  edges[i]=new int[v] ;
  for(int j=0;j<v;j++)
     edges[i][j]=0 ;
 }
 for(int i=0;i<e;i++)
 {
  int f,s ;
  cout << "Enter first and second vertex of the edge : " << endl ;
  cin >> f >> s ;
  edges[f][s]=1 ;
  edges[s][f]=1 ;
 }
 bool* visited=new bool[v] ;
 for(int i=0;i<v;i++)
 {
  visited[i]=false ;
 }
 vector<vector<int>*>* ans=new vector<vector<int>*>() ;
 print(edges,v,visited,ans) ;
 cout << endl << "Printing the graph by BFS transversal : " << endl ;
 for(int i=0;i<ans->size();i++)
 {  sort(ans->at(i)->begin(),ans->at(i)->end()) ;
    for(int j=0;j<ans->at(i)->size();j++)
    {
      cout << ans->at(i)->at(j) << " " ;
    }
    cout << endl ;
 }
 return 0;
}
