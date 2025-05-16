#include <iostream>
#include <vector>
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
const int maxn=1e5+1;
int n,k;
int dp[maxn][21];
int ans[maxn];
vector<int> adj[maxn];int c[maxn];
int main(){
    cin>>n>>k;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rei(i,1,n){
        cin>>c[i];
        dp[i][0]=c[i];
    }
    rei(u,1,n){
        dp[u][1]=dp[u][0];
        for(int v:adj[u]) dp[u][1]+=dp[v][0];
    }
    rei(i,2,k){
        rei(u,1,n){
            dp[u][i]=dp[u][i-2];
            for(int v:adj[u]) dp[u][i]+=dp[v][i-1]-dp[u][i-2];
        }
    }
    rei(i,1,n) cout<<dp[i][k]<<"\n";
}