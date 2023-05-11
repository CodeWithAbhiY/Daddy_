#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
using namespace std;
const int N=1e5;
const int INF=1e9+10;

vector<pair<int,int>> g[N];


vector<int> dijkstra(int source,int dest){
    vector<int> vis(N,0);   //visited array
    vector<int> dist(N,INF);  //distance array
    set<pair<int,int>> s; //set with weight and vertex respectively
    vector<int> parent(N,-1);


    s.insert({0,source}); //insert source vertex with weight 0 in set
    dist[source]=0;    //distance of the source vertex from itself is 0
    
    while (!s.empty())   //traverse and process every vertex in the set
    {
        auto node=*s.begin();   //since elements are in sorted order in set so we will get smallest
        int wt_=node.first;
        int v=node.second;
        s.erase(s.begin());

        if (vis[v]==1)    //if already visited vertex is encountered then continue
        {
            continue;
        }
        
        vis[v]=1;

        for(auto child:g[v]){       //now we will see the child of v 
            
            int child_v=child.first;      //child of v
            int wt_v=child.second;     //weight of child of v

            if ((dist[v]+wt_v)<dist[child_v])     //distance of child_v through v is dist[v]+wt_v , here we are minimizing the distance 
            {
                dist[child_v]=dist[v]+wt_v;
                parent[child_v]=v;
                s.insert({dist[child_v],child_v});
            }
        }
    }
    cout<<"Shortest Distance : ";
    cout<<dist[dest]<<endl;

    vector<int> path;
    while (source!=dest){
        path.push_back(dest);
        dest=parent[dest];
    }
    path.push_back(source);

    reverse(path.begin(),path.end());
    
    return path;
}

int main(){
    int n,m;
    cin>>n>>m;

    for (int i = 0; i < m; i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    
    vector<int> p=dijkstra(1,6);
    cout<<"\nShortest path : ";
    for (int i = 0; i < p.size(); i++)
    {
        cout<<p[i]<<"->";
    }
       

    return 0;
}