#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 5;
string a[MAXN];
int n, m;
int h[MAXN];
int lft[MAXN], rgt[MAXN];

void buildlr() {
    h[0] = 0;
    h[n+1] = 0;
    for(int i = 1; i <= n; i++) {
        lft[i] = rgt[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        int j = i - 1;
        while(j > 0 && h[j] >= h[i])
            j = lft[j];
        lft[i] = j;
    }
    for(int i = n; i >= 1; i--) {
        int j = i + 1;
        while(j <= n && h[j] > h[i])
            j = rgt[j];
        rgt[i] = j;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] = " " + a[i]; 
    }

    long long ds = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            h[j] = (a[i][j] == '.' ? h[j] + 1 : 0);
        }
        buildlr();
        for(int j = 1; j <= n; j++) {
            long long A = j - lft[j];
            long long B = rgt[j] - j;
            long long H = h[j];
            ds += A * B * (A + B) * H * (H + 1) / 4;
        }
    }

    cout << ds ;
    return 0;
}
