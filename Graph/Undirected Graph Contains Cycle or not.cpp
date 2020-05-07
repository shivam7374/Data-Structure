#include <iostream>
#include <queue>
#include <list>
#include <cstring>
using namespace std;
// if a tree consist of a cycle then the tree is not a tree 
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
            l[y].push_back(x);
        }
        bool is_tree()
        {
            bool *visited=new bool[v];
            int parent[v];
            queue<int> q;
            for(int i=0;i<v;i++)
            {

                visited[i]=0;
                parent[i]=i;
            }
            int src=0;
            q.push(src);
            visited[src]=true;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(auto nbr:l[node])
                {
                    if(visited[nbr]==true && parent[node]!=nbr)
                    {
                        return false; // here we are checking for tree and not for cycle
                    }
                    else if(!visited[nbr])
                    {
                        visited[nbr]=true;
                        parent[nbr]=node;
                        q.push(nbr);
                    }
                }
            }
            return true;
        }
};


int main() 
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    // g.addedge(0,3);
    if(g.is_tree()){
        cout<<"This is a tree ";
    }
    else{
        cout<<" Not a tree";
    }
    

    return 0;    
}
