#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;
const int N=1e5+10;

int parent[N];
int sz[N];

void make(int v){
    parent[v]=v;
    sz[v]=1;
}

int find(int u){
    if(parent[u]==u){
        return parent[u];
    }
    return parent[u]=find(parent[u]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(sz[a]!=sz[b]){

        swap(a,b);
    }
    parent[b]=a;
    sz[a]+=sz[b];
}

int main(){
 int n,m;
 cin>>n>>m;

 vector<pair<int,pair<int,int>>> edges;//pair consist of weight and pair that consist of edge between two vertices, since sorting is done on the basis of first value in pair 
 for (int i = 0; i < m; i++)
 {
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back({wt,{u,v}});
 } 
 for (int i = 0; i < n; i++)
 {
    make(i);
 }

 int total_cost=0;
 sort(edges.begin(),edges.end());          //sort as per the weights of the edges
    for(auto& edge:edges){
        int wt=edge.first;
        int u,v;
        u=edge.second.first;
        v=edge.second.second;
        if(find(u)==find(v)){ //if cycle is there, continue
            continue;
        }
        Union(u,v);   //insert edge between them
        total_cost+=wt; //update the total cost for the minimum spanning tree
        cout<<u<<"  "<<v;
    }
 

    return 0;
} 