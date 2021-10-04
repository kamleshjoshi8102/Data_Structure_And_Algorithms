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
			l[y].push_back(x);
		}

		void bfs(T source)
		{
			// map for marking true and false and a queue for traversal
			map<T,bool>visited;
			queue<T>q;

			q.push(source);
			visited[source]=true;

			while(!q.empty())
			{
				T node=q.front();
				q.pop();
				cout<<node<<" ";
				for(auto nbr:l[node])
				{
					if(!visited[nbr])
					{
						q.push(nbr);
						// marking nbr visited or not
						visited[nbr]=true;
					}
				}

			}


		}

};
 


int main(void)
{

         
        Graph<int>g;
        g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(2,3);
        g.addEdge(3,4);
        g.addEdge(4,5);

        g.bfs(0);

  return 0;

}
