// đề bài : cho một số n đếm cách chia các số từ 1 đến n thành 2 tập con có tổng bằng nhau
//-------------> bài toán con: cho các 1 tập hợp các số từ 1 đến n đếm số cách tạo thành x mà mỗi phần tử chỉ con một lần
// dp[i][x] là tổng từ 1 đến i sao cho tổng đúng bằng x
// chưa ko chọn i thì dp[i][x]=dp[i-1][x]
// chọn i thì dp[i][x]=dp[i-1][x-i]
// dp[y] : so cach de tao ra tong y
// xet tu 1 den n
// neu 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =501;
const int mod = 1e9+7;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
int n;
ll dp[501*502/4+1];
ll bpow(ll a,ll b){
    ll ds=1;
    while(b>0){
        if(b%2) ds=(ds*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ds;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    ll x=n*(n+1)/2;
    if(x%2!=0){
        cout<<"0";
        return 0;
    }
    x/=2;
    dp[0]=1;
    rei(i,1,n){
        red(j,x,0){
            if(j>=i) dp[j]=(dp[j]+dp[j-i])%mod;
        }
    }
    cout<<(dp[x]*bpow(2,mod-2))%mod;
    return 0;
}