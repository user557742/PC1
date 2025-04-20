#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e6+1;
int n;
int a[maxn];
struct node{
    ll s,lz;
    bool nho;
    node(ll _s=0,ll _lz=0,bool _nho=0) : s(_s) , lz(_lz),nho(_nho) { }
}
int sz=0;
struct segtree{
    vector<node> g;
    void init(int n){
        g.resize(4*n+1,node(0,0,0));
        sz=n;
    }
    void build(int r=1,int lo=1,int hi=sz){
        if(lo==hi){
            g[r].s=a[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        g[r].s=g[2*r].s+g[2*r+1].s;
    }
    void down(int r){
        if(g[r].nho){
            g[2*r].nho=g[2*r+1].nho=1;
            g[r].nho=0;
            g[2*r].lz=g[2*r+1].lz=g[r].lz;
        }
    }
    void 
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    return 0;
}