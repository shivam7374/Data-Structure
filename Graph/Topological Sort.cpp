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
void addedge(int x,int y)
{
    l[x].push_back(y);
}
void topological_sort()
{
    int *indegree=new int[v];
    for(int i=0;i<v;i++)
    {
        indegree[i]=0;
    }
    for(int i=0;i<v;i++)
    {
        list<int> temp=l[i];
        for(auto t:temp)
        {
            indegree[t]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto nbr:l[node])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
}
};
int main() {
    graph g(6);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(2,5);
    g.addedge(4,5);
    g.topological_sort();
}
