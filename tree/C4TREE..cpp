//đặt dp[u][x] là cách gán các đỉnh trong cây con gốc u là nhỏ nhất với màu của u là x
// xét v1,v2,v3,.....vr là các con của u mà kề vói u
// dp[u][x]+=min(dp[v][h])+x [h!=x]
#include <iostream>
#include <vector>
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
const int maxn= 1e+5+1;
vector<int> adj[maxn];
int n;
int dp[maxn][5];int ans[maxn];
void dfs(int u,int dad){
    rei(i,1,4) dp[u][i]=i;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        rei(x,1,4){
            int tmp=1e9;
            rei(h,1,4) if(x!=h){
                tmp=min(tmp,dp[v][h]);
            }
            dp[u][x]+=tmp;
        }
    }

}
void tim(int u,int c,int dad){
    for(int v:adj[u]) if(v!=dad){
        int tmp=1e9;
        int nc;
        rei(h,1,4) if(h!=c){
            if(dp[v][h]<tmp){
                nc=h;
                tmp=dp[v][h];
            }
        }
        ans[v]=nc;
        tim(v,nc,u);
    }
}
int main(){
    cin>>n;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);adj[v].pb(u);
    }
    dfs(1,0);
    int ds=1e9;
    int bd=0;
    rei(i,1,4){
        if(ds>dp[1][i]){
            ds=dp[1][i];
            bd=i;
        }
    }
    cout<<ds<<"\n";
    ans[1]=bd;
    tim(1,bd,0);
    rei(i,1,n) cout<<ans[i]<<"\n";
}