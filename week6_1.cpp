
#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;  //
    vector<list<int>>adj;  //pointer to an array containing adjacency list
    public:
    Graph(int V);
    void addEdge(int V, int W);
    bool isReach(int s, int d);

     
       
};
void Graph::addEdge(int V,int W){
    adj[V].push_back(W);
}
Graph:: Graph(int V){
    this-> V=V;
    adj.resize(V); //Resize adjacency list to number of vertices

}
bool Graph::isReach(int s, int d){
    if(s==d )
     return true;
    
    vector<bool> visited;
    visited.resize(V,false);
    list<int> queue; // created a queue with list;
    visited[s]= true; //mark the current node as visited
    queue.push_back(s); //Then add it to the queue;
    while(!queue.empty()){
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
    
    for(auto adjacent: adj[s]){ //loop till adjacency list ends
          if(adjacent ==d)
             { return true;}
        if(!visited[adjacent]){
            visited[adjacent]=true; //if the vertex is unmarked, then mark visited and
            queue.push_back(adjacent);//push to the queue
        }
    }
    }
    return false;

}
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout<<"";

    if( g.isReach(0,3))
    cout<<"Yes path available";
   


    return 0;
}