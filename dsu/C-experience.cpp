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
struct DSU{
    vector<int> pre,sz,p,ex;
    int n;
    void init(int _n) {
        n=_n;
        sz.resize(n+1,0);
        pre.resize(n+1,0);
        p.resize(n+1,0);
        ex.resize(n+1,0);
    }
    void ms(int v){
        sz[v]=1;
        pre[v]=v;
        p[v]=0;
        ex[v]=0;
    }
    int find(int u){
        if(u==pre[u]) return u;
        int p=pre[u];
        int r=find(p);
        ex[u]+=ex[p];
        return pre[u]=r;
    }
    void kn(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            ex[v]=p[v]-p[u];
            pre[v]=u;
        }
    }
    void upo(int u,int x){
        u=find(u);
        p[u]+=x;
    }
    int getans(int u){
        int r=find(u);
        return p[r]+ex[u];
    }
}dsu;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    dsu.init(n);
    rei(i,1,n) dsu.ms(i);
    while(m--){
        string ct;
        cin>>ct;
        if(ct=="add"){
            int u,x;cin>>u>>x;
            dsu.upo(u,x);
        }
        if(ct=="join"){
            int u ,v;cin>>u>>v;
            dsu.kn(u,v);
        }
        if(ct=="get"){
            int u;cin>>u;
            cout<<dsu.getans(u)<<"\n";
        }
    }
    return 0;
}