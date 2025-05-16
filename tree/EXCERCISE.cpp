// dp[u] tong binh phuong khoang cach tu no den cay con goc u 
// xet v1,v2,...,vk la cac con cua u ma ke voi u
// dp[u] lk voi dp[vj] kieu gi 
// gia su duong di tu vj den x la d 
// cach u,vj dai l;
// x^2 ---> x^2+2*l*x+l^2
// dp[u]+=dp[vj]+2*l*s[vj]+sz[vj]*l^2
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5+1;
vector<int> adj[maxn];
typedef long long ll;
struct E{
    ll u,v,l;
};
E e[maxn];
int n;
#define rei(i,a,b) for(int i=a;i<=b;i++)
ll sz[maxn];
ll s[maxn];
ll dp[maxn];
void dfs(int u,int dad){
    sz[u]=1;
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v : e[i].u;
        ll l=e[i].l;
        if(v!=dad){
            dfs(v,u);
            sz[u]+=sz[v];
            s[u]+=sz[v]*l+s[v];
            dp[u]+=dp[v]+2*l*s[v]+sz[v]*l*l;
        }
    }
}
ll ans[maxn];
void calc(int u,int dad){
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v : e[i].u;
        ll l=e[i].l;
        if(v!=dad){
            ll dpu=dp[u];
            ll dpv=dp[v];
            ll szu=sz[u];
            ll szv=sz[v];
            ll sv=s[v];
            ll su=s[u];
            dp[u]-=dp[v]+2*l*s[v]+sz[v]*l*l;
            s[u]-=sz[v]*l+s[v];
            sz[u]-=sz[v];
            dp[v]+=dp[u]+2*l*s[u]+sz[u]*l*l;
            s[v]+=sz[u]*l+s[u];
            sz[v]+=sz[u];
            ans[v]=dp[v];
            calc(v,u);
            dp[u]=dpu;dp[v]=dpv;
            s[u]=su;s[v]=sv;
            sz[u]=szu;sz[v]=szv;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n-1){
        cin>>e[i].u>>e[i].v>>e[i].l;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    dfs(1,0);
    ans[1]=dp[1];
    calc(1,0);
    ll ds=1e18;
    rei(i,1,n) ds=min(ds,ans[i]);
    int cnt=0;
    rei(i,1,n) if(ans[i]==ds) cnt++;
    cout<<cnt<<"\n";
    rei(i,1,n) if(ans[i]==ds) cout<<i<<" ";
}