#include <bits/stdc++.h>
using namespace std;
bool dfs_isCycle(int i,int par,vector<vector<int>>& g,vector<int>& vis){
     vis[i]=1;
     for(auto nbr:g[i]){
         if(vis[nbr]==0) { 
             if(dfs_isCycle(nbr,i,g,vis)) return true;
         }
         else if(par != nbr) return true;
     }
     return false;
}

bool bfs_cycle(vector<vector<int>> &g, int v)
{
    int src = 1; 

    vector<bool> visited(v+1, false);
    queue<pair<int, int>> q; 
    visited[src] = true;
    q.push({src, -1});
    while(!q.empty()){
        auto node = q.front();
        int parent = node.second;
        int val = node.first;
        q.pop();
        for(auto nbr : g[val])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                q.push({nbr, val});
            }
            else if (parent != nbr)
            {
                cout<<"Checking: "<< val<<' '<<nbr<<endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> g(n+1);
    while (m--)
    {
        int a;
        int b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    // Detect cycle using bfs
    if(bfs_cycle(g,n))
    {
        cout<<"Cycle found"<<endl;
    }
    else{
        cout<<"No Cycle"<<endl;
    }

    // vector<int> vis(n+1, 0);
    // for (int i=1;i<=n;i++)
    // {
    //     if(vis[i]==0){
    //         if(dfs_isCycle(i,-1,g,vis)){
    //             cout<<"Cycle"<<endl;
    //             break;
    //         }else{
    //             cout<<"NO Cycle"<<endl;
    //         }
    //     }
    // }

    return 0;
}