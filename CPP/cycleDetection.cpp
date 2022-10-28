#include <bits/stdc++.h>
using namespace std;

bool isCheckCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(isCheckCycle(it,adj,vis,dfsVis))
            {
                return true;
            }
        }
        else if(dfsVis[it])
        {
            return true;
        }
    }

    dfsVis[node] = 0;
    return false;
}

bool isCyclic(vector<int> adj[],int v)
{
    vector<int> vis(v+1,0);
    vector<int> dfsVis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            if(isCheckCycle(i,adj,vis,dfsVis))
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int m,n;
    cin>>m>>n;
    vector<int> adj[m+1];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    if(isCyclic(adj,m))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

}

int main() {

    solve();

    return 0;
}
