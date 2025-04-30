//-----------------------------------A. Swap Columns and Find a Path
// có 1 bảng 2*N ô (i,j) có giá trị là a[i][j]
// ta có thể thực hiện thao tác sau một số lần tùy ý :
    // đổi hàng x với hàng y 
    // ta mong muốn tìm đường đi có tổng giá trị lớn nhất
    // không được đi ra ngoài bảng và từ (i,j) chỉ có thể sang (i+1,j) (i,j+1)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =5001;
const int mod = 1e9+7;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
int n;
pair<int,int> a[maxn];
pair<int,int> ver[maxn];
pair<int,int> s[maxn];
bool cmp1(pair<int,int> u,pair<int,int> v){
    return make_pair(u.se,u.fi)>make_pair(v.se,v.fi);
} 
bool cmp2(pair<int,int> u,pair<int,int> v){
    return make_pair(u.fi,u.se) > make_pair(v.fi,v.se);
}
void solve(){
    cin>>n;
    rei(i,1,n) cin>>a[i].fi;
    rei(i,1,n) cin>>a[i].se;
    vector<pair<int,int>> b,c;
    rei(i,1,n){
        if(a[i].fi>a[i].se) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    if(n==1){
        cout<<a[1].fi+a[1].se<<"\n";
        return ;
    }
    ll ds1=0;
    ll ds2=0;
    for(pair<int,int> x:b) ds1+=x.fi;
    for(pair<int,int> y:c) ds2+=y.se;
    ll ds=-1e18;
    rei(i,1,n){
        if(a[i].fi>a[i].se) ds=max(ds,ds1+ds2+a[i].se);
        else ds=max(ds,ds1+ds2+a[i].fi);
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