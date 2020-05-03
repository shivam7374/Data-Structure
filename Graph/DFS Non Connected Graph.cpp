#include <iostream>
#include<map>
#include<list>
using namespace std;
class graph{
    map<int,list<int> > m;
    public:
    void add_edge(int x,int y)
    {
        m[x].push_back(y);
    }
    void dfshelper(int src, map<int, int> &visited)
    {
        cout<<src<<" , ";
        visited[src]=1;
        for(auto p:m[src])
        {
            if(!visited[p])
            {
                dfshelper(p,visited);
            }
        }
    }
    void dfs(int src)
    {
        map<int, int> visited;
        for(auto p:m)
        {
            int temp=p.first;
            visited[temp]=0;
        }
        int count=0;
        for(auto p:m)
        {
            int tem=p.first;
            if(!visited[tem]){
            cout<<count<<"-->>";
            count++;
            dfshelper(tem,visited);
            cout<<endl;
            }
        }
        
    }
};
int main() {
    graph g;
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(0,3);
    g.add_edge(0,4);
    g.add_edge(5,6);
    g.add_edge(6,7);
    g.add_edge(8,8);
    g.dfs(0);
 return 0;
}