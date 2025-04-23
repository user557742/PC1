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
int a[maxn];
int n;
struct IT{
    vector<ll> lz,s;
    void inIT(){
        lz.resize(4*n+1,0);
        s.resize(4*n+1,0);
    }
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=a[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=max(s[2*r+1],s[2*r]);
    }
    void fix(int r,int lo,int hi){
        s[r]+=lz[r];
        if(lo!=hi){
            lz[2*r]+=lz[r];
            lz[2*r+1]+=lz[r];
        }
        lz[r]=0;
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=n){
        fix(r,lo,hi);
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            lz[r]+=x;
            fix(r,lo,hi);
            return ;
        }
        int mid=(lo+hi)/2;
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        s[r]=max(s[2*r],s[2*r+1]);
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=n){
        fix(r,lo,hi);
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return max(getans(u,v,2*r,lo,mid),getans(u,v,2*r+1,mid+1,hi));
    }
} t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i];
    t.inIT();
    t.build();
    int m;cin>>m;
    while(m--){
        int l;
        cin>>l;
        if(l==1){
            int u,v,l;cin>>u>>v>>l;
            t.upd(u,v,l);
        }
        else{
            int u,v;cin>>u>>v;
            cout<<t.getans(u,v)<<"\n";
        }
    }
    return 0;
}