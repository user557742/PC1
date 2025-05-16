#include <iostream>
#include <vector>
#include <unordered_map>
#define rei(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+1;
int n,m,r;
vector<int> adj[maxn];
int c[maxn];              
int ds[maxn];
unordered_map<int,int> dp[maxn];
void dfs(int u,int dad){
    dp[u][c[u]]=1;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        if(dp[v].size()>dp[u].size()) swap(dp[u],dp[v]);
        for(pair<int,int> x:dp[v]) dp[u][x.first]+=x.second;
    }
    ds[u]=dp[u].size();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>r;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    rei(i,1,n) cin>>c[i];
    dfs(r,0);
    while(m--){
        int u;cin>>u;
        cout<<ds[u]<<"\n";
    }
}