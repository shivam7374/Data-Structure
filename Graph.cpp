#include<iostream> 
#include <list> 
using namespace std; 

class Graph 
{ 
	int Vertices; 
	list<int> *adj; 
public: 
	Graph(int Vertices){ 
	this->Vertices = Vertices; 
	adj = new list<int>[Vertices]; 
}  
	void AddEdge(int v, int w){ 
	adj[v].push_back(w); 
} 
 

	void BFS(int s){ 
	bool *visited = new bool[Vertices]; 
	for(int i = 0; i < Vertices; i++) 
		{
			visited[i] = false;
		}

	list<int> q; 

	visited[s] = true; 
	q.push_back(s); 
	
	list<int>::iterator i; 

	while(!q.empty()) 
	{ 
		s = q.front(); 
		cout << s << " "; 
		q.pop_front(); 

		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{ 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				q.push_back(*i); 
			} 
		} 
	} 
} 
 
}; 

int main() 
{ 
	int n;
	cout<<"Enter the number of vertices : ";
	cin>>n;
	Graph gr(n);
	int a;
	cout<<endl<<"Enter the Number of edges to be entered : "; 
	cin>>a;
	for(int i=0;i<a;i++)
	{
		int x,y;
		cin>>x>>y;
		gr.AddEdge(x,y);
	}

	cout << "BFS Traversal of the Graph\n"; 
	gr.BFS(0); 
	cout<<endl;
	return 0; 
} 
