#include <bits/stdc++.h>
#define ll                  long long
#define en                  '\n'
#define rep(a,b)            for(ll i=a;i<b;i++)
#define pb                  push_back

const ll                    mod = 1e9 + 7;
 

using namespace std;

	


template<typename T>// map<T>mp => map<int>mp || map<char>mp || map<string>mp ---> T can be any data type
class Graph{

		map<T,list<T>> l;// adjacency list

	public:
		void addEdge(int x,int y)
		{
			l[x].push_back(y);
		}

		int bfs(T source,T dest)
		{
			// map for marking true and false and a queue for traversal
			map<T,int>dist;
			map<T,T>parent; // for shortest path
			queue<T>q;	

			for(auto node_pair:l)
			{
				T node=node_pair.first;
				dist[node]=INT_MAX;
			}
			
			q.push(source);
			dist[source]=0;
			parent[source]=source;

			while(!q.empty())
			{
				T node=q.front();
				q.pop();
				
				// cout<<node<<" ";

				for(auto nbr:l[node])
				{
					if(dist[nbr]==INT_MAX)
					{
						q.push(nbr);
						dist[nbr]=dist[node]+1;
						parent[nbr]=node;
					}
				}

			}
			// print distance to destination node node
			 
			 T temp=dest;
			 while(parent[temp]!=source)
			 {
			 	cout<<temp<<"<--";
			 	temp=parent[temp];
			 }
			 cout<<source<<en;

			 			
			 return dist[dest];


		}

};
 


int main(void)
{

        	
        int board[50]={0};
// snakes //ladders
        board[2]=13;	
        // if we are standing in 1 then 1(where we are standing)+ 1(dice throws)+ 13 => 15 (end where we'll reach)

        board[5]=2;
        board[9]=18; 
        board[18]=11;
        board[17]=-13;
        board[20]=-14;
        board[24]=-8;
        board[25]=10;
        board[32]=-2;
        board[34]=-22;
        
// 	add edges to the Graph
        Graph<int> g;
        for(int i=0;i<=36;i++)
        {
        	for(int dice=1;dice<=6;dice++)
        	{
        		int j=i+dice;
        		j+=board[j];

	        	if(j<=36)
	        	{
	        		g.addEdge(i,j);
	        	}
        	}
        }
        g.addEdge(36,36);

        cout<<g.bfs(0,36)<<en;

  return 0;

}
