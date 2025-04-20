
#include<bits/stdc++.h>
#define For(i,n) for(int i=1;i<=n;++i)
#define maxn 100
#define ll long long

using namespace std;

int a[maxn];
ll gt[maxn];
ll gtmau[maxn];
int n;
int m;
int k;
const int p=1000000007;
int pp[1<<5];

ll PowMod(ll a, ll b){
	if(b==0) return 1ll*1;
	ll t=PowMod(a,b/2);
	t=(t*t)%p;
	if(b%2) t=(t*a)%p;
	return t;
}

void inp(){
	cin >> m >> n >> k;
}

void outp(){
	gt[0]=1;
	for(int i=1;i<maxn;++i) gt[i]=(gt[i-1]*i)%p;
	gtmau[maxn-1]=PowMod(gt[maxn-1],p-2);
	for(int i=maxn-2;i>=0;--i) gtmau[i]=(gtmau[i+1]*(i+1))%p;
	ll ds=0;

	for(int i1=0;i1<=n;++i1)
	for(int i2=0;i2<=n-i1;++i2)
	for(int i3=0;i3<=n-i1-i2;++i3){
		int cc=0;
		int i4=n-i2-i1-i3;
		if(i1!=0) ++cc;
		if(i2!=0) ++cc;
		if(i3!=0) ++cc;
		if(i4!=0) ++cc;
		if(cc>=k){
			ll q=(gtmau[i1]*gtmau[i2])%p;
			q=(q*gtmau[i3])%p;
			q=(q*gtmau[i4])%p;
			q=(q*gt[n])%p;
			ds=(ds+q)%p;
		}
	}
	cout << PowMod(ds,m);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	inp();
	outp();
}
