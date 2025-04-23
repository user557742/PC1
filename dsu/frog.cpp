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
typedef pair<double,double> p;
p cw(p x){
    return {-x.se,x.fi};
} 
p ccw(p x){
    return {x.se,-x.fi};
}
p xflip(p x,int k){
    return {2*k-x.fi,x.se};
}
p yflip(p x,int k){
    return {x.fi,2*k-x.se};
}
int n,m,q;
p a[maxn];
pair<string,int> thaotac[maxn];
pair<int,int> truyvan[maxn];
void sub1(){
    rei(i,1,q){
        p bd=a[truyvan[i].fi];
        rei(j,1,truyvan[i].se){
            if(thaotac[j].fi=="cw") cw(bd);
            if(thaotac[j].fi=="ccw") ccw(bd);
            if(thaotac[j].fi=="xflip") xflip(bd,thaotac[j]);
            
            if(thaotac[j].fi=="yflip") yflip(bd,thaotac[j]);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    rei(i,1,n) cin>>a[i].fi>>a[i].se;
    rei(i,1,m){
        cin>>thaotac.fi;
        if(thaotac.fi=="cw"||thaotac.fi="ccw"){
            continue;
        }
        cin>>thaotac.se;
    }
    rei(i,1,q) cin>>truyvan[i].fi>>truyvan[i].se;
    return 0;
}