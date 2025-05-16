#include <iostream>
#include <algorithm>
using namespace std;
const int maxn =2e5+1;
int n;
typedef long long ll;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
struct prj{
    int u,v;ll l;
    prj(int _u=0,int _v=0,ll _l=0) : u(_u) , v(_v), l(_l) {}
};
bool cmp(prj a,prj b){
    if(a.v==b.v) return mp(a.l,a.u)<mp(b.l,b.u);
    return a.v<b.v;
}
prj a[maxn];
ll b[maxn];
ll dp[maxn];
struct maxst{
    ll s[4*maxn+1];
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=0;
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=max(s[2*r],s[2*r+1]);
    }
    void upd(int k,ll x,int r=1,int lo=1,int hi=n ){
        if(lo==hi){
            s[r]=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=max(s[2*r],s[2*r+1]);
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return -1e18;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return max(getans(u,v,2*r,lo,mid),getans(u,v,2*r+1,mid+1,hi));
    }
}t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i].u>>a[i].v>>a[i].l;
    sort(a+1,a+n+1,cmp);
    rei(i,1,n) b[i]=a[i].v;
    t.build();
    rei(i,1,n){
        dp[i]=a[i].l;
        int j=lower_bound(b+1,b+n+1,a[i].u)-b-1;
        dp[i]=max(dp[i],t.getans(1,j)+a[i].l);
        t.upd(i,dp[i]);
    }
    long long ds=0;
    rei(i,1,n) ds=max(ds,dp[i]);
    cout<<ds;
    return 0;
}
