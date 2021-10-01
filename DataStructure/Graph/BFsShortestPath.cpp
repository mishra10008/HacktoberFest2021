// this shortest path algorithm is also called single source shortest path algorithm for undiected graph
#include <iostream>
#include <list>
#include <queue>
using namespace std;
class graph
{
    public:
    int V;
    list<int> *l;
    graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int i,int j,bool directedd)
    {
        l[i].push_back(j);
        if(directedd==false)
        l[j].push_back(i);
    }
    void bfs(int source,int destinationn) //destination to find path
    {
        queue<int>q;
        bool *visited=new bool[V]{0};
        int *distancee=new int[V]{0};
        int *parentss=new int[V]{-1};
        distancee[source]=0;
        parentss[source]=source;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int f=q.front();
            cout<<f<<" "<<endl;
            q.pop();
            for(auto it=l[f].begin();it!=l[f].end();it++)
            {
                if(!visited[*it])
                {
                    q.push(*it);
                    parentss[*it]=f;
                    distancee[*it]=distancee[f]+1;
                }
                visited[*it]=true;
            }
        }
        for(int i=0;i<V;i++)
        {
            cout<<"Shortest distance of "<<i<<" from "<<source<<" is "<<distancee[i]<<endl;
        }
        if(destinationn!=-1)
        {
            int temp=destinationn;
            while(temp!=source)
            {
                cout<<temp<<" ";
                temp=parentss[temp];
            }
            cout<<temp;
        }
    }
};
int main()
{
    int i;
    cin>>i;
    graph g(i);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(3, 5, false);
    g.addEdge(5, 6, false);
    g.addEdge(4, 5, false);
    g.addEdge(4, 0, false);
    g.addEdge(0, 1, false);
    g.bfs(1,6); //find path from 1 to 6

}
