#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e5+1;
typedef long long ll;
int n,m;int id=0;
int a[maxn];
int bd[maxn],kt[maxn],pos[maxn];
vector<int> adj[maxn];
void dfs(int u,int dad){
    id++;
    bd[u]=id;
    pos[id]=u;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
    }
    kt[u]=id;
}
struct ST{
    ll s[4*maxn];
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=a[pos[lo] ];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    void upd(int k,int x,int r=1,int lo=1,int hi=id){
        if(lo==hi) {
            s[r]=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    ll get(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
} st;
void truyvanq(){
    int u;cin>>u;
    cout<<st.get(bd[u],kt[u])<< "\n";
}
void truyvanu(){
    int u,x;cin>>u>>x;
    st.upd(bd[u],x);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);adj[v].pb(u);
    }
    dfs(1,0);
    st.build();
    while(m--){
        char loai;cin>>loai;
        if(loai=='Q') truyvanq();
        else truyvanu();
    }
    return 0;
}
