#include <iostream>
#include <queue>
#include <list>
#include <cstring>
using namespace std;
class graph{
list <int>*l;
int v;
public:
graph(int v)
{
    this->v=v;
    l=new list<int> [v];
}
void add_edge(int x,int y)
{
    l[x].push_back(y);
}
bool cycle_helper(int node,bool*visited,bool*stack)
{
    visited[node]=true;
    stack[node]=true;
    for(int nbr:l[node])
    {
        if(stack[nbr]==true)
        {
            return true;
        }
        else if(visited[nbr]==false)
        {
            bool cyclemila=cycle_helper(nbr,visited,stack);
            if(cyclemila==true)
            {
                return true;
            }
        }
    }


    stack[node]=false;
    return false;
    
}
bool contain_cycle(){
    bool* visited=new bool[v];
    bool *stack=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
        stack[i]=false;
    }
    return cycle_helper(0,visited,stack);
}
};
int main() {
 graph g(7);
 g.add_edge(0,1);
 g.add_edge(1,2);
 g.add_edge(2,3);
 g.add_edge(3,4);
 g.add_edge(4,5);
 g.add_edge(1,5);
 g.add_edge(5,6);
//  g.add_edge(4,2); // backedge
 if(g.contain_cycle())
 {
     cout<<"Yes there is a cycle";
 }
 else{
     cout<<"No cycle present";
 }
}
