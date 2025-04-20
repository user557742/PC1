#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;


typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int a[maxn],n;
// toan tu khong co tinh chat giao hoan
struct node{
    ll s,lz;bool nho;
    node(ll s=0,ll lz=0,bool nho=0):s(s),lz(lz),nho(nho){}
};
struct it{
    node g[4*maxn];
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            g[r]=node(a[lo]);
            return;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        g[r]=node(g[2*r].s+g[2*r+1].s);
    }
    void down(int r){
        if(g[r].nho){
            g[2*r].nho=g[2*r+1].nho=1;
            g[r].nho=0;
            g[2*r].lz=g[2*r+1].lz=g[r].lz;
        }
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=n){
        if(lo>v||u>hi) return ;
        if(u<=lo&&hi<=v){
            g[r].lz=x;
            g[r].nho=1;
            return;
        }
        int mid=(lo+hi)/2;
        down(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        ll trai=(g[2*r].nho) ? g[2*r].lz*(mid-lo+1) : g[2*r].s;
        ll phai=(g[2*r+1].nho) ? g[2*r+1].lz*(hi-mid) : g[2*r+1].s;
        g[r].s=trai+phai;
    } 
    ll get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u<=lo&&hi<=v) return (g[r].nho) ? g[r].lz*(hi-lo+1) : g[r].s;
        if(u>hi||v<lo) return 0;
        int mid=(lo+hi)/2;
        down(r);
        ll trai=(g[2*r].nho) ? g[2*r].lz*(mid-lo+1) : g[2*r].s;
        ll phai=(g[2*r+1].nho) ? g[2*r+1].lz*(hi-mid) : g[2*r+1].s;
        g[r].s=trai+phai;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
}t;
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i];
    t.build();
    int q;cin>>q;
    while(q--){
        int l;cin>>l;
        if(l==1){
            int u,v,l;cin>>u>>v>>l;
            t.upd(u,v,l);
        }
        else {
            int u,v;cin>>u>>v;
            cout<<t.get(u,v)<<"\n";
        }
    } 


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}