#include <iostream>
#include<vector>
using namespace std;
const int maxn =2e5+1;
int n;
vector<int> adj[maxn];
int dp[maxn][2];
void dfs(int u,int dad){
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
    }
    int ans = 0;
    for(int v : adj[u]) if(v != dad) {
        dp[u][0] += max(dp[v][0], dp[v][1]);
        ans += max(dp[v][0], dp[v][1]);
    }
    for(int v : adj[u]) if(v != dad) {
        dp[u][1] = max(dp[u][1], ans - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1]);
}
