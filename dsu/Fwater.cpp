#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =3e2+1;
const int mod = 1e9+7;
const int lll=1e6+1;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
int n;
int w[maxn];
int p[maxn][maxn];
int nho[lll];
struct canh{
    int u,v,l;
    canh(int _u=0,int _v=0,int _l=0) : u(_u),v(_v),l(_l) {}
};
struct DSU{
    int sz[lll],pre[lll];
    void ms(int u){
        sz[u]=1;
        pre[u]=u;
    }
    int getroot(int x){
        return (x==pre[x]) ? x : pre[x]=getroot(pre[x]);
    }
    void kh(int u,int v){
        u=getroot(u);
        v=getroot(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
}dsu;
vector<int> adj[maxn];
canh e[lll];
bool cmp(canh a,canh b){
    if(a.l==b.l) return make_pair(a.u,a.v) < make_pair(b.u,b.v);
    return a.l<b.l;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>w[i];
    rei(i,1,n) rei(j,1,n) cin>>p[i][j];
    ll cnt=0;
    rei(i,1,n) rei(j,i+1,n){
        cnt++;
        e[cnt]=canh(i,j,p[i][j]);
        
    }
    rei(i,1,n){
        cnt++;
        e[cnt]=canh(0,i,w[i]);
    }
    rei(i,0,n) dsu.ms(i);
    sort(e+1,e+cnt+1,cmp);
    rei(i,1,cnt){
        if(dsu.getroot(e[i].u)!=dsu.getroot(e[i].v)){
            dsu.kh(e[i].u,e[i].v);
            nho[i]=1;
        }
    }
    ll ds=0;
    rei(i,1,cnt) if(nho[i]){
        ds+=e[i].l;
    }
    cout<<ds;
    return 0;  
}