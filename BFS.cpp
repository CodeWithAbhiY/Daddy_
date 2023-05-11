#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
//Breadth first search or level order traversal
const int N =1e5+10;

vector<int> g[N];  //(adjacenecy list)  g of i will tell which nodes are connected with node i
int visited[N]; 
int level[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    visited[source]=1;
    while (!q.empty())
    {
        int cur_v=q.front();
        q.pop();
        cout<<cur_v<<"  ";
        for(int child:g[cur_v]){      //traversing the every connected nodes to cur_v 
            if (!visited[child])
            {
                q.push(child);           
                visited[child]=1;
                level[child]=level[cur_v]+1;    //level of vertex
            }
        }
    }
    cout<<endl;
}

//O(V+E)


int main(){
    int m;
    cout<<"number  of  edges: ";
    cin>>m;
    int n;
    cout<<"number of vertices : ";
    cin>>n;

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    bfs(0);    //breadth first search calling

    for (int i = 0; i < n; i++)      //printing levels of each vertex
    {
        cout<<i<<"  "<<level[i]<< "\n";
    }
    return 0;
}

