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
int n;
int a[maxn];
struct ST{
    ll s[4*maxn],lz[4*maxn];
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
    void down(int r){
        lz[2*r]+=lz[r];
        lz[2*r+1]+=lz[r];
        lz[r]=0;
    }
    void upd(int u,int v,int d,int r=1,int lo=1,int hi=n){
        if(u>hi||lo>v) return ;
        if(u<=lo&&hi<=v){
            lz[r]+=d;
            return; 
        }
        int mid=(lo+hi)/2;
        down(r);

        upd(u,v,d,2*r,lo,mid);
        upd(u,v,d,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r]+(hi-lo+1)*lz[r];
        int mid=(lo+hi)/2;
        down(r);
        ll L=getans(u,v,2*r,lo,mid);
        ll R=getans(u,v,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
        return R+L;
    }
}t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i];
    t.build();
    int q;cin>>q;
    while(q--){
        int l;
        cin>>l;
        if(l==1){
            int u,v,d;cin>>u>>v>>d;
            t.upd(u,v,d);
        }
        else{
            int u,v;cin>>u>>v;
            cout<<t.getans(u,v)<<"\n";
        }
    }
    return 0;
}