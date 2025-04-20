#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e6+1;
struct node{
    ll s,lz;
    bool nho;
    node(ll _s=0,ll _lz=0,bool _nho=0) : s(_s) , lz(_lz),nho(_nho) { }
};int sz=0;
struct IT{
    vector<node> g;
    void init(int n){
        g.resize(4*n+1,node(0,0,0));
        sz=n;
    }
    void build(int r=1,int lo=1,int hi=sz){
        if(lo==hi){
            g[r].s=0;
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        g[r].s=g[2*r].s+g[2*r+1].s;
    }
    void down(int r){
        if(g[r].nho){
            g[2*r].nho=1;g[2*r+1].nho=1;
            g[r].nho=0;
            g[2*r].lz=g[2*r+1].lz=g[r].lz;
        }
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=sz){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            g[r].lz=x;
            g[r].nho=1;
            return ;
        }
        int mid=(lo+hi)/2;
        down(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        ll L=(g[2*r].nho) ? g[2*r].lz*(mid-lo+1) : g[2*r].s;
        ll R=(g[2*r+1].nho) ? g[2*r+1].lz*(hi-mid) : g[2*r+1].s;
        g[r].s=L+R;
    }
    int getans(int u,int v,int r=1,int lo=1,int hi=sz){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return (g[r].nho) ? g[r].lz*(hi-lo+1) : g[r].s;
        int mid=(lo+hi)/2;
        down(r);
        ll T=getans(u,v,2*r,lo,mid);
        ll P=getans(u,v,2*r+1,mid+1,hi);
        ll L=(g[2*r].nho) ? g[2*r].lz*(mid-lo+1) : g[2*r].s;
        ll R=(g[2*r+1].nho) ? g[2*r+1].lz*(hi-mid) : g[2*r+1].s;
        g[r].s=L+R;
        return T+P;
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    IT t;
    t.init(n);
    t.build();
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        t.upd(a,b,c);
    }
    set<int> gt;
    for(int i=1;i<=n;i++){
        int x=t.getans(i,i);
        if(x!=0) gt.insert(x);
    } 
    cout<<gt.size();
    return 0;
}