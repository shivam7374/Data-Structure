#include<iostream>
#include<map>
#include<list>
#include<climits>
using namespace std;
template<typename T>
class graph
{
	public:
		map<T , list<pair<T,int> > >m;
	void add_edge(T x,T y,int w)
	{
		m[x].push_back(make_pair(y,w));
		//  m[y].push_back(make_pair(x,-w));
		// m[y].push_back(x);
	}
	void print()
	{
		for(pair<T,list<pair<T,int > > > p:m)
		{
			T data=p.first;
			cout<<data<<"---->  ";
			list<pair<T ,int> > li=p.second;
			for(pair<T,int> a:li)
			{
				cout<<a.first<<" ( "<<a.second<<" )  ";
			}
			cout<<endl;
		}
	}
       list<T> queue;
    map<T , int > visited;
    map<T , int > dist;
    map<T,T> parent;
    int bfsdist(T src, T dest)
    {
        for(pair<T,list<pair<T,int > > > a:m)
    {
        // cout<<a.first<<"ccc";
        for(pair<T,int >  r:m[a.first])
        {
            dist[r.first]=INT_MAX;
        }
        

    }
    
        queue.push_back(src);
        dist[src]=0;
        parent[src]=src;
        while(!queue.empty())
        {
            T temp=queue.front();
            // cout<<temp<<"   ,   ";
            queue.pop_front();
            for(pair<T,int>  data :m[temp])
            {   
                if(dist[data.first]==INT_MAX){
                    // cout<<data.first<<"ccc";
                
                    queue.push_back(data.first);
                    parent[data.first]=temp;

                    dist[data.first]=data.second+dist[temp];
                    // cout<<data.second<<"tt";
                    // cout<<dist[data.first]<<"  ....";
                }
            }
           
        }
         for(pair<T,list<pair<T,int > > > dis:m)
            {
                cout<<endl<<dis.first<<" "<<dist[dis.first]<<" , ";
            }
        T finalpoint=dest;
        cout<<endl;
        while(finalpoint!=src)
        {
            cout<<finalpoint<<" <--- ";
            finalpoint=parent[finalpoint];
        }
        cout<<src<<endl;
        return dist[dest];
    }
    void bfs(T src)
    {
        for(pair<T,list<pair<T,int > > > a:m)
    {
        visited[a.first]=0;
    }
    
        queue.push_back(src);
        visited[src]=1;
        while(!queue.empty())
        {
            T temp=queue.front();
            cout<<temp<<"   ,   ";
            queue.pop_front();
            for(pair<T,int>  data :m[temp])
            {
                if(!visited[data.first]){
                    queue.push_back(data.first);
                    visited[data.first]=1;
                }
            }
        }
        return ;
    }


};
int main()
{
	// graph<char> g;
	// g.add_edge('A','B',1);
	// g.add_edge('A','C',2);
	// g.add_edge('B','D',3);
	// g.add_edge('A','E',4);
	// g.add_edge('C','B',-1);
	// g.add_edge('D','B',-2);
	// g.add_edge('E','B',-3);
	// g.add_edge('F','B',-4);
	// g.print();
    // // g.bfs('F');
    // g.bfsdist('A');


    //Snakes and ladder
    int board[50]={0};

    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;


    graph<int > Snakes;
    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j=i+dice;
            j+=board[j];
            if(j<=36)
            {
                Snakes.add_edge(i,j,1);// i,j,1 because assuming every edges is st cost of 1 dice throw 
            }
        }
    }
    Snakes.add_edge(36,36,1);
    cout<<endl<<Snakes.bfsdist(0,36);

    
	return 0;
}