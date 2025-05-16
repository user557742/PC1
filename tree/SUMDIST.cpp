// dp[u] la tong khoang cach toi cac nut con trong cay con goc u
// goi v1,v2,...,vk la cac con ma ke voi u
// dp[u]+=dp[vj]+sz[vj];
#include <iostream>
#include <vector>
using namespace std;
const int maxn  = 2e5+1;
int n;
typedef long long ll;
#define rei(i,a,b) for(int i=a;i<=b;i++)
ll dp[maxn];
ll sz[maxn];
vector<int> adj[maxn];
void dfs(int u,int dad){
    sz[u]=1;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        dp[u]+=dp[v]+sz[v];
        sz[u]+=sz[v];
    }
}
ll ans[maxn];
void calc(int u,int dad){
    for(int v:adj[u]) if(v!=dad){
        ll szu=sz[u];
        ll szv=sz[v];
        ll dpu=dp[u];
        ll dpv=dp[v];
        dp[u]-=dp[v]+sz[v];
        sz[u]-=sz[v];
        dp[v]+=dp[u]+sz[u];
        sz[v]+=sz[u];
        ans[v]=dp[v];
        //cout<<"! "<<v<<" "<<ans[v]<<"\n";
        calc(v,u);
        dp[v]=dpv;
        dp[u]=dpu;
        sz[u]=szu;
        sz[v]=szv;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    ans[1]=dp[1];
    calc(1,0);
    rei(i,1,n) cout<<ans[i]<<" ";
}