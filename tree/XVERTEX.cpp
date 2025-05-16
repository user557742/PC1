#include <iostream>
#include <vector>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
const int maxn=1e3+1;
const int inf=1e9;
typedef long long ll;
int m;
ll dp[maxn][maxn];
int a[maxn];
int b[maxn];
int n;int P;
vector<int> adj[maxn];
bool vis[maxn];
void dfs(int u,int dad){
    vis[u]=1;
    rei(s,1,P) dp[u][s]=0;
    dp[u][a[u]]=b[u];
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        vector<ll> odp(P+1,0);
        rei(s,1,P) odp[s]=dp[u][s];
        rei(s,1,P) dp[u][s]=0;
        rei(s,1,P){
            dp[u][s]=max(dp[u][s],odp[s]);
            rei(t,1,P-s){
                dp[u][s+t]=max(dp[u][s+t],odp[s]+dp[v][t]);
            }
        }
    }
}
int S[maxn];
int main(){
    cin>>n>>m;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n) b[i]=1;
    rei(i,1,m){
        int u,v;cin>>u>>v;
        adj[u].pb(v);adj[v].pb(u);
    }
    int q;cin>>q;
    rei(i,1,q) cin>>S[i];
    rei(i,1,q){
        P=max(P,S[i]);
    }
    vector<int> r;
    rei(i,1,n) if(!vis[i]){
        dfs(i,0);
        r.pb(i);
    }
    rei(i,1,q){
        ll tm=0;
        rei(j,1,S[i]) tm=max(tm,dp[1][j]);
        if(tm<2) cout<<"0\n";
        else cout<<tm<<"\n";
        //if(dp[1][S[i]]<2) cout<<"0\n";
        //else cout<<dp[1][S[i]]<<"\n";
    }
    
}