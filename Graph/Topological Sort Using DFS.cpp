#include <iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class graph{
    map<T,list<T> > m;
    public:
    void add_edge(T x,T y)
    {
        m[x].push_back(y);
    }
    void dfshelper(T src, map<T, int> &visited,list<T>&ordering)
    {
        cout<<src<<" , ";
        visited[src]=1;
        for(auto p:m[src])
        {
            if(!visited[p])
            {
                dfshelper(p,visited,ordering);
            }
        }
        ordering.push_front(src);// push the node to the front of the list 
    }
    void dfs()
    {
        map<T, int> visited;
        list<T>ordering;
        for(auto p:m)
        {
            T temp=p.first;
            visited[temp]=0;
        }
        int count=0;
        for(auto p:m)
        {
            T tem=p.first;
            if(!visited[tem]){
            cout<<count<<"-->>";
            count++;
            dfshelper(tem,visited,ordering);
            cout<<endl;
            }
        }
        for(T order:ordering)
        {
            cout<<order<<endl;
        }
        
    }
};
int main() {
    graph<string> g;
    g.add_edge("Python","DataProcessing");
    g.add_edge("Python","Pytorch");
    g.add_edge("Python","ML");
    g.add_edge("DataProcessing","ML");
    g.add_edge("Pytorch","DL");
    g.add_edge("ML","DL");
    g.add_edge("DL","FaceRecognition");
    g.add_edge("Dataset","FaceRecognition");
    g.dfs();
 return 0;
}