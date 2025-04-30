
// số đẹp chính là các số mà số chữ số lẻ là lẻ và số các chữ số chẵn là chẵn . đề bài : đếm số chữ số đẹp có n chữ số 
//solve :
// đặt dp[i] số chữ số đẹp có đúng i chữ số 
// đk số số chẵn phải chẵn và số số lẻ phải lẻ 
// nên i không thể chẵn
// nếu trong số đó có x số lẻ thì sẽ có i-x số chẵn trong đó 
/*
    xét t là các số lẻ nhỏ hơn x
    th t nếu có t số là sẻ : ds(t) = C(t,i) * (5^t) * 5^(i-t) - C(t,i-1)*(5^t)*(5^(i-1-t))
    ds= 2^(n-1)*5^n-2^(n-2)*5^(n-1)=9*2^(n-2)*5^(n-1)
    Định lý  :  2^(n-1) = tổng các t lẻ C(t,n) = tổng các t chẵn C(t,n)
    ds là tổng ds(t) với t là số lẻ nhỏ hơn i 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e6+1;
const int mod = 1000000123;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
ll bpow(ll a,ll b){
    ll ds=1;
    while(b>0){
        if(b%2==1) ds=(ds*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ds;
}ll cntsodep(ll n){
    if(n%2==0) return 0;
    if(n==1) return 5;
    ll p2=bpow(2,n-2);
    ll p5=bpow(5,n-1);
    ll ds=(p2*p5)%mod;
    return (9*ds)%mod;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    while(cin>>n){
        
    }
    return 0;
}