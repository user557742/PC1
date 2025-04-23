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
    vector<int> sz,pre;
    void init(int n){
        sz.resize(n+1,0);
        pre.resize(n+1,0);
    }
    int find(int u){
        return (pre[u]==u) ? u:pre[u]=find(pre[u]);
    }
    void makeset(int u){
        sz[u]=1;
        pre[u]=u;
    }
    void kh(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            //if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
} dsu;
int p[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    rei(i,1,n) cin>>p[i];
    dsu.init(n+1);
    rei(i,1,n+1) dsu.makeset(i);
    rei(i,1,n){
        int u=p[i];
        u=dsu.find(u);
        bool ok=0;
        if(u==dsu.find(u)){
            cout<<u<<" ";
            ok=1;
        }
        int t=u+1;
        if(t>n) t=1;
        dsu.kh(t,u);
        if(!ok){
            cout<<t<<" ";
        }
    }
    return 0;
}