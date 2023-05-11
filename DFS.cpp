#include<iostream>
#include<stack>
#include<vector>
using namespace std;

const int N=1e5;

vector<int> g[N];
bool vis[N]={false};

void dfs(int vertex){
    vis[vertex]=true;
    cout<<vertex<<endl;
    for(auto child:g[vertex]){
        cout<<"parent : "<<vertex<<"child : "<<child<<endl;
        if (vis[child])
        {
            continue;
        }
        dfs(child);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    // dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cout<<"\n";
        }
        
    }
        


    return 0;
}

