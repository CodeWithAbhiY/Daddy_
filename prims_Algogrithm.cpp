#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;

//prims algorithm
const int N=1e5+10;

vector<pair<int,int>> g[N];
vector<pair<int,int>> mst;
int vis[N];

vector<pair<int,int>> prims_algo(int source){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;     //{weight,{u,v}}
    
    pq.push({0,{source,-1}});
    // vis[source]=true;
    fill(vis,vis+N,false);
    // set<int> s;
    int sum=0;
    while (!pq.empty())
    {
        int u=pq.top().second.first;
        int v_=pq.top().second.second;
        int wt=pq.top().first;
        pq.pop();
        if(vis[u]==true){
            continue;
        }
        // if(s.count(u)>0) continue;
        vis[u]=true;
        // s.insert(u);
        sum+=wt;
        if(v_!=-1){
            mst.push_back({v_,u});
        }
        for(auto v:g[u])
        {
            int c_v=v.first;
            int c_wt=v.second;
            if(!vis[c_v]) pq.push({c_wt,{c_v,u}});
            // if(s.count(c_v)==0) pq.push({c_wt,{c_v,u}});
        }
    }
    cout<<"Total Cost for the Maximum Spanning Tree : "<<sum<<"\n";  
    // for(auto ele:mst){
    //     cout<<ele.first<<" "<<ele.second<<"\n";
    // }
    return mst;


}




int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    
    mst=prims_algo(0);
     for(auto ele:mst){
         cout<<ele.first<<" "<<ele.second<<"\n";
     }   
    

    return 0;
}