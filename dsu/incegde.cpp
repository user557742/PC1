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
typedef pair<int,ll> ii;
struct egde{
    int u,v;ll l;
    egde(int _u=0,int _v=0,int _l=0) : u(_u),v(_v),l(_l) {}
};
egde e[maxn];
int n,m;
vector<int> adj[maxn];
ll d[maxn];a    
int cnt[maxn];
int pre[maxn];
void dijkstra(int u){
    rei(i,1,n) {
        pre[i]=0;
        d[i]=1e9;
        cnt[i]=0;
    }
    d[u]=0;
    cnt[u]=1;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push({0,u});
    while(!q.empty()){
        int u=q.top().se;
        q.pop();
        for(int i:adj[u]){
            int v=e[i].v;
            ll l=e[i].l;
            if(d[v]==d[u]+l){
                cnt[v]+=cnt[u];
            }
            else if(d[v]>d[u]+l){
                d[v]=d[u]+l;
                pre[v]=u;
                cnt[v]=cnt[u];
                q.push({d[v],v});
            }
        }
    }
}
void sub1(){
    dijkstra(1);
    int cd=d[n];
    vector<int> ds;
    rei(i,1,m){
        e[i].l+=2;
        dijkstra(1);
        if(d[n]-cd==1) ds.push_back(i);
        e[i].l-=2;
    }
    cout<<ds.size()<<"\n";
    for(int x:ds) cout<<x<<" ";
    cout<<"\n";
}
void sub2(){
    dijkstra(1);
    
}
void solve(){
    //adj.clear();
    cin>>n>>m;
    rei(i,1,n) adj[i].clear();
    rei(i,1,m) cin>>e[i].u>>e[i].v>>e[i].l;
    rei(i,1,m){
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    sub1();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}