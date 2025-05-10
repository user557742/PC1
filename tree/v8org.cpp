//dề bài : cây n đỉnh . cho số nguyên k tìm cách xóa ít đỉnh nhất sao cho cây bị bẻ thành  các cây con có độ dài không quá k
// có sz nhỏ hơn k 
// dp[u] là số đỉnh it nhất cần loại bỏ để có sz nhỏ hơn k trong cây con gốc u 
// nếu sz[u]>k bỏ đỉnh u sz[u]=0;
// dp[u]+=1;
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
struct trip{
    int fi,se,th;
    trip(int _fi=0,int _se=0,int _th=0) : fi(_fi),se(_se),th(_th) {}
};
int getbit(int i,int x){return (x>>(i-1))&1;}
ll bpow(ll a,ll b,ll m){
    ll ds=1;
    while(b>0){
        if(b%2) ds=(ds*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return ds;
}
ll inv(ll a,ll m){
    return bpow(a,m-2,m)%m;
}
vector<int> adj[maxn];
int n,k;
int sz[maxn];
int dp[maxn];
void dfs(int u,int dad){
    sz[u]=1;
    ///cout<<u<<"";
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        sz[u]+=sz[v];
        //cout<<v<<" ";
    }
}
void dfs1(int u,int dad){
    for(int v:adj[u]) if(v!=dad){
        dfs1(v,u);
       // cout<<v<<"\n";
       
       dp[u]+=dp[v];
        if(sz[u]>k){
            dp[u]+=1;
            sz[u]=0;
        }
    }
}
int main(){
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>n;
    rei(i,2,n){
        int x;cin>>x;
        if(i==1) continue;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    dfs(1,0);
    //rei(i,1,n) cout<<sz[i]<<" ";
    dfs1(1,0);
    cout<<dp[1];
    return 0;
}