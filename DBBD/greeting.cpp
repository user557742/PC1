#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e6+1;

#define X first
#define Y second
int sz;
struct IT{
    vector<int> s;
    void init(int n){
        s.resize(4*n+1,0);
        sz=n;
    }
    void upd(int k,int x,int r=1,int lo=1,int hi=sz){
        if(lo==hi){
            s[r]+=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r];
    }
    int get(int u,int v,int r=1,int lo=1,int hi=sz){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
};
pair<int,int> p[maxn];
int n;
bool cmp(pair<int,int> u,pair<int,int> v){
    return u.Y<v.Y;
}
void solve(){
    cin>>n;
    vector<int> tmp;
    for(int i=1;i<=n;i++) cin>>p[i].X>>p[i].Y;
    for(int i=1;i<=n;i++){
        tmp.push_back(p[i].X);
        tmp.push_back(p[i].Y);
    }
    sort(tmp.begin(),tmp.end());
    for(int i=1;i<=n;i++){
        p[i].X=lower_bound(tmp.begin(),tmp.end(),p[i].X)-tmp.begin()+1;
        p[i].Y=lower_bound(tmp.begin(),tmp.end(),p[i].Y)-tmp.begin()+1;
    }
    sort(p+1,p+n+1,cmp);
    ll ds=0;
    IT t;
    t.init(2*n);
    for(int i=1;i<=n;i++){
        ds+=t.get(p[i].X+1,2*n);
        t.upd(p[i].X,1);
    } 
    cout<<ds<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}