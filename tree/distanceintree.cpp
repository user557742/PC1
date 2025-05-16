// dp[u][j] so cap co do dai j trong con goc u
// cnt[u][j] so dinh cach u dung j dv
// gia su co cac con v1,v2,v3,...,vk
// dp[u][j]+=dp[v][j];
// dp[u][t]+=xx;
// cnt[u][j]+=cnt[v][k-1];
#include <iostream>
#include <vector>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
const int maxn=5e4+1;
int n,k;
vector<int> adj[maxn];
int dp[maxn][501];
int cnt[maxn][501];
void dfs(int u,int dad){
    cnt[u][0]=1;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        rei(x,1,k){
            dp[u][x]+=dp[v][x];
            cnt[u][x]+=cnt[v][x-1];
        }
    }
    int lim=adj[u].size()-1;
    rei(i,0,lim){
        rei(j,i+1,lim){
            int v1=adj[u][i];
            int v2=adj[u][j];
            if(v1==dad) continue;
            if(v2==dad) continue;
            rei(x,1,k){
                rei(y,1,k-x){
                    dp[u][x+y]+=cnt[v1][x]*cnt[v2][y];
                }
            }
        }
    }
}
int main(){
    cin>>n>>k;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    rei(i,1,k) cout<<dp[1][i]<<" ";
}