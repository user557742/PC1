#include <bits/stdc++.h>
#define maxn 1000001
#define ll long long
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n;
ll a[maxn];
int m;

struct SegmentTree {
    vector<ll> s, lazy, nho;

    SegmentTree(int size) {
        s.resize(4 * size, LLONG_MIN);
        lazy.resize(4 * size, LLONG_MIN);
        nho.resize(4 * size, LLONG_MIN);
    }

    void replace(int u, int val, int r = 1, int lo = 1, int hi = n) {
        if (lo == hi) {
            s[r] = val;
            nho[r] = 0;
            return;
        }
        if (nho[r]) {
            lazy[2 * r] = lazy[2 * r + 1] = lazy[r];
            nho[r] = 0;
        }
        int mid = (lo + hi) / 2;
        if (u <= mid) replace(u, val, 2 * r, lo, mid);
        else replace(u, val, 2 * r + 1, mid + 1, hi);
        s[r] = max(s[2 * r], s[2 * r + 1]);
    }

    void update(int u, int v, int val, int r = 1, int lo = 1, int hi = n) {
        if (v < lo || u > hi) return;
        if (u <= lo && hi <= v) {
            nho[r] = 1;
            lazy[r] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if (nho[r]) {
            lazy[2 * r] = lazy[2 * r + 1] = lazy[r];
            nho[2 * r] = nho[2 * r + 1] = 1;
            nho[r] = 0;
        }
        update(u, v, val, 2 * r, lo, mid);
        update(u, v, val, 2 * r + 1, mid + 1, hi);
        ll tl = (nho[2 * r]) ? 1LL * lazy[2 * r] : s[2 * r];
        ll tr = (nho[2 * r + 1]) ? 1LL * lazy[2 * r + 1] : s[2 * r + 1];
        s[r] = max(tl, tr);
    }

    ll get(int u, int v, int r = 1, int lo = 1, int hi = n) {
        if (v < lo || u > hi) return LLONG_MIN;
        if (u <= lo && hi <= v) return (nho[r]) ? lazy[r] : s[r];
        int mid = (lo + hi) / 2;
        if (nho[r]) {
            lazy[2 * r] = lazy[2 * r + 1] = lazy[r];
            nho[2 * r] = nho[2 * r + 1] = 1;
            nho[r] = 0;
        }
        ll t1 = get(u, v, 2 * r, lo, mid);
        ll t2 = get(u, v, 2 * r + 1, mid + 1, hi);
        ll tl = (nho[2 * r]) ? 1LL * lazy[2 * r] : s[2 * r];
        ll tr = (nho[2 * r + 1]) ? 1LL * lazy[2 * r + 1] : s[2 * r + 1];
        s[r] = max(tl, tr);
        return max(t1, t2);
    }
};

int main() {
    faster;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree st(n);
    for (int i = 1; i <= n; i++) {
        st.replace(i, a[i]);
    }

    cin >> m;
    while (m--) {
        int y, u, v, d;
        cin >> y;
        if (y == 1) {
            cin >>u >> v >> d;
            st.update(u, v, d);
        } else if (y == 2) {
            cin >> u >> v;
            cout << st.get(u, v) << endl;
        }
    }
    return 0;
}