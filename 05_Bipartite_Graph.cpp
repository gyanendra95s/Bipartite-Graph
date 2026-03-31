#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    bool Bipartite(){// T.C=0(V+E)
        queue<int>q;
        vector<bool>vis(V,false);
        vector<bool>color(V,-1);
        q.push(0);
        vis[0]=true;
        color[0]=0;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            list<int>neighbour=l[curr];
            for(int v:neighbour){
                if(!vis[v]){
                    vis[v]=true;
                    // Curr agar blue color ka hai to uska neighbour white color ka hoga
                    color[v]=!color[curr];
                    q.push(v);
                }
                else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
int main(){
    Graph graph(4);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    // graph.addEdge(0,3);
    
    cout<<graph.Bipartite();
    return 0;
}