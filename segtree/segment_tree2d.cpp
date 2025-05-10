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

struct segtree(){
    int n;
    vector<ll> s;
    vector<ll> lz;
    void init(int _n){
        n=_n;
        s.resize(4*_n+1,0);
        lz.resize(4*_n+1,0);
    }
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=a[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    void fix(int r){
        lz[2*r]+=lz[r];
        lz[2*r+1]+=lz[r];
        lz[r]=0;
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=n){
        if(u>hi||lo>v) return ;
        if(u<=lo&&hi<=v){
            lz[r]+=x;
            return ;
        }
        int mid=(lo+hi)/2;
        fix(r);
        upd(u,v,2*r,lo,mid);
        upd(u,v,2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r]
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    return 0;
}