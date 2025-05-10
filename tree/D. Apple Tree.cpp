/*
5
1 2
3 4
5 3
3 2
4
3 4
5 1
4 4
1 3
*/
// tư tưởng : dp[u] số lá trong cây con gốc u 
#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define TASK "TASK"
#define gcd __gcd
#define X first
#define Y second
#define ub upper_bound
#define lb lower_bound
const int mod= 1e9+7;
const int maxn=1e6+1;
const int base=293;
typedef long long ll;
const int ooi=1e9+9;
const ll ool=1e18+9;

int d[maxn];
int n,q;
vector<int> adj[maxn];
void dfs(int u,int dad){
    if(adj[u].size()==1&&u!=1){
        d[u]=1;
    }
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        d[u]+=d[v];
    }
}
void solve(){
        
        cin>>n;
        rei(i,1,n) adj[i].clear();
        rei(i,1,n-1){
            int u,v;cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        rei(i,1,n) d[i]=0;
        dfs(1,0);
        cin>>q;
        while(q--){
            int u,v;
            cin>>u>>v;
            cout<<1ll*d[u]*d[v]<<"\n";
        }
}
int main(){
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}