
//dp[u][x] la so cach de to mau cay con goc u khi goc u co mau x
// xet vj la con ke cua u
// th1 u ,v deu duoc to mau roi
// + u,v cung mau : dp[u][a[u]] =0
// + u,v khac nhau : dp[u]a[a[u]] *= dp[v][a[v]]
// th2 u duoc to mau roi ma v chua duoc to mau
// + dp[u][a[u]]*=dp[v][x1]+dp[v][x2] (x1!=x2!=a[u])
// th3 u chua duoc to mau ma v da to mau
// + dp[u][x] *= dp[v][a[v]] (x!=a[v])
// th4 u chua duoc to mau , v chua duoc to mau
// dp[u][x] *=dp[v][y1]+dp[v][y2] (y1!=y2!=x) voi moi x tu 1 den 3

#include <iostream>
#include<vector>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
typedef long long ll;
const int maxn = 1e5+1;
const int mod=1e9+7;
int n,k;
int a[maxn];
vector<int> adj[maxn];
ll dp[maxn][4];
void dfs(int u,int dad){
    if(a[u]!=0) dp[u][a[u]]=1;
    else{
        rei(i,1,3) dp[u][i]=1;
    }
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        if(a[u]!=0){
            if(a[v]!=0){
                dp[u][a[u]]=(dp[u][a[u]]*dp[v][a[v]])%mod;
            }
            else{
                ll ans=0;
                rei(i,1,3) if(i!=a[u]) ans=(ans+dp[v][i])%mod;
                dp[u][a[u]]=(dp[u][a[u]]*ans)%mod;
            }
        }
        else{
            if(a[v]!=0){
                rei(i,1,3){
                    if(i!=a[v]) dp[u][i]=(dp[u][i]*dp[v][a[v]])%mod;
                    else dp[u][i]=0;
                }
            }
            else {
                rei(x,1,3){
                    ll ans=0;
                    rei(y,1,3) if(x!=y){
                        ans+=dp[v][y];
                        ans%=mod;
                    }
                    dp[u][x]=(dp[u][x]*ans)%mod;
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
    while(k--){
        int x,c;cin>>x>>c;
        a[x]=c;
    }
    dfs(1,0);
    if(a[1]!=0) cout<<dp[1][a[1]];
    else cout<<(dp[1][1]+dp[1][2]+dp[1][3])%mod;
}
