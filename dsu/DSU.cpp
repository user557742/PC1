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
int n,k,p,m;
struct canh{
    int l,u,v;
    canh(int _l=0,int _u=0,int _v=0) : l(_l) , u(_u) ,v(_v) {}
};
struct DSU{
    int sz[maxn],pre[maxn];
    void makeset(int u){
        sz[u]=1;
        pre[u]=u;
    }
    int find(int u){
        return (u==pre[u]) ? u : pre[u]=find(pre[u]);
    }
    void kh(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
}dsu;
bool cmp(canh a,canh b){
    if(a.l==b.l) return make_pair(a.u,a.v)<make_pair(b.u,b.v);
    return a.l<b.l;
}
canh e[maxn];
bool nho[maxn];
ll ct[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>m>>p;
    rei(i,1,k) cin>>e[i].u>>e[i].v>>e[i].l;
    sort(e+1,e+k+1,cmp);
    rei(i,1,n) dsu.makeset(i);
    //vector<canh> ST;
    rei(i,1,k){
        if(dsu.find(e[i].u)!=dsu.find(e[i].v)){
            dsu.kh(e[i].u,e[i].v);
            nho[i]=1;
        }
    }
    ll t=0;
    rei(i,1,k) t+=nho[i]*e[i].l;
    if(m-t<=0){
        cout<<"-1";
        return 0;
    }
    rei(i,1,k) ct[i]=(nho[i]) ? (p-1)*e[i].l : p*e[i].l;
    sort(ct+1,ct+k+1);
    ll ds=0;
    ll ss=m-t;

    rei(i,1,k){
        if(ss-ct[i]>=0){
            ds++;
            ss-=ct[i];
        }
    } 
    cout<<ds;
    return 0;
}