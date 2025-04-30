#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e3+1;
const int mod = 1e9+7;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
int n,m,q;
ll a[maxn][maxn];
ll s[maxn][maxn];
struct DATA{
    ll x,y,u,v,val;
    DATA(int _x=0,int _y=0,int _u=0,int _v=0,int _val=0) : x(_x),y(_y),u(_u),v(_v),val(_val) {}
};
vector<DATA> ds;
void laptt(){
    rei(i,1,n) rei(j,1,m) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
}
ll xylydanhsach(int x,int y,int u,int v){
    ll kq=0;
    rei(i,0,(int)ds.size()-1){
        int xx=ds[i].x,yy=ds[i].y,uu=ds[i].u,vv=ds[i].v,val=ds[i].val;
        int i1=max(x,xx);
        int j1=max(y,yy);
        int i2=min(u,uu);
        int j2=min(v,vv);
        if(i1<=i2&&j1<=j2) kq+=val*(i2-i1+1)*(j2-j1+1);
    }
    return kq;
}
ll d[maxn][maxn];
void lamlai(){
    rei(i,0,(int)ds.size()-1){
        int x   = ds[i].x;
        int y   = ds[i].y;
        int u   = ds[i].u;
        int v   = ds[i].v;
        int val = ds[i].val % mod;
        d[x][y]=(d[x][y] + val) ;
        d[x][v+1]=(d[x][v+1] - val ) ;
        d[u+1][y]= (d[u+1][y] - val ) ;
        d[u+1][v+1]   = (d[u+1][v+1] + val) ;
    }
    ds.clear();
    rei(i,1,n){
        rei(j,1,m){
            d[i][j] = (ll)d[i-1][j] + d[i][j-1]- d[i-1][j-1] + d[i][j];
            a[i][j] = a[i][j] + d[i][j];
        }
    }
    rei(i,1,n) rei(j,1,m) d[i][j] = 0;
    laptt();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    rei(i,1,n) rei(j,1,m) cin>>a[i][j];
    laptt();
    int T=sqrt(q);
    rei(i,1,q){
        int loai;cin>>loai;
        if(loai==1){
            ll x,y,u,v,val;cin>>x>>y>>u>>v>>val;
            ds.push_back(DATA(x,y,u,v,val));
        }
        else {
            int x,y,u,v;cin>>x>>y>>u>>v;
            int kq=s[u][v]-s[u][y-1]-s[x-1][v]+s[x-1][y-1];
            kq+=xylydanhsach(x,y,u,v);
            cout<<kq<<"\n";
        }
        if(i%T==0) lamlai();
    }
    return 0;
}