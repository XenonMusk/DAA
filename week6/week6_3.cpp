#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);
    public:
    Graph(int V);
    bool isCyclic();
    void addEdge(int u, int v);
};
Graph::Graph(int V){
    this->V=V;
    adj=new list <int>[V];
}
bool Graph:: isCyclicUtil(int v,bool visited[], bool *rs){
    if(visited[v]==false){
        visited[v]=true;
        rs[v]=true;
        list<int>:: iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, rs) )
                return true;
            else if (rs[*i])
                return true;
        }
}
rs[v]=false;
return false;
}
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
int main(){

    // int n,m;
    // cin>>n>>m;
    // Graph g(n);
    // list<int> *adj;
    // for(int i=0;i<m; i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u].push_back(v);
    // }
    //   if(g.isCyclic())
    //     cout << "Graph contains cycle";
    // else
    //     cout << "Graph doesn't contain cycle";
    // return 0;
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(3, 4);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;

}