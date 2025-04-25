#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e6+1;
const int mod = 1e9+7;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
int pre[maxn];
int depth[maxn];
int n;
int a[maxn];
bool vis[maxn];
vector<int> adj[maxn];
void dfs(int u,int dad){
    vis[u]=1;
    for(int v:adj[u]) if(v!=dad){
        if(!vis[v]){
            pre[v]=u;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
}
ll solve(int u,int v){
    map<int,int> cnt;
    while(depth[u]!=depth[v]){

    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);

    return 0;
}