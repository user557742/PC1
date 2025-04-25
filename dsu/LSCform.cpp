#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;
const ll INF = 1e18;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i = (a); i <= (b); ++i)
#define red(i,a,b) for(int i = (a); i >= (b); --i)
#define fi first
#define se second

struct BIT {
    int n;
    vector<ll> t;
    BIT(int _n = 0) : n(_n), t(n + 1, 0) {}
    
    // cập nhật vị trí u với giá trị x (max)
    void upd(int u, ll x) {
        while (u <= n) {
            t[u] = max(t[u], x);
            u += u & -u;
        }
    }
    
    // lấy max trên prefix [1..x]
    ll get(int x) const {
        ll res = 0;
        while (x > 0) {
            res = max(res, t[x]);
            x -= x & -x;
        }
        return res;
    }
};

int n, m;
ll a[maxn], b[maxn], tmpA[maxn], tmpB[maxn];
int tmpa[maxn], tmpb[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rei(i,1,n) cin >> a[i];
    rei(j,1,m) cin >> b[j];
    rei(i,1,n) tmpA[i] = a[i];
    rei(j,1,m) tmpB[j] = b[j];
    sort(tmpA+1, tmpA+n+1);
    sort(tmpB+1, tmpB+m+1);
    rei(i,1,n) tmpa[i] = lower_bound(tmpA+1, tmpA+n+1, a[i]) - tmpA;
    rei(j,1,m) tmpb[j] = lower_bound(tmpB+1, tmpB+m+1, b[j]) - tmpB;
    BIT bit(m);
    rei(j,1,m) f[ tmpb[j] ] = j;
    ll ans = 0;
    rei(i,1,n) {
        int idx = f[tmpa[i]];
        if (idx > 0) {
            ll cur = bit.get(idx - 1) + 1;
            bit.upd(idx, cur);
            ans = max(ans, cur);
        }
    }
    cout << ans;
    return 0;
}
