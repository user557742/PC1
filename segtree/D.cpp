#include <bits/stdc++.h>
using namespace std;

// --- General Lazy Segment Tree ---
// Usage: Define your own Node and Update structs (see examples at bottom)

template<typename Node, typename Update>
struct SegmentTree {
    int n;
    vector<Node> st;
    vector<Update> lz;

    SegmentTree(int _n) : n(_n) {
        st.assign(4*n, Node::identity());
        lz.assign(4*n, Update::identity());
    }

    // Build from array a[1..n]
    void build(const vector<Node>& a, int idx=1, int l=1, int r=-1) {
        if (r == -1) r = n;
        if (l == r) {
            st[idx] = a[l];
        } else {
            int m = (l + r) >> 1;
            build(a, idx*2,   l, m);
            build(a, idx*2+1, m+1, r);
            st[idx] = Node::merge(st[idx*2], st[idx*2+1]);
        }
    }

    // Internal: apply update u at idx covering [l..r]
    void apply(int idx, int l, int r, const Update &u) {
        u.apply(st[idx], l, r);
        lz[idx].combine(u);
    }

    // Push lazy from idx to children
    void push(int idx, int l, int r) {
        if (lz[idx] == Update::identity()) return;
        int m = (l + r) >> 1;
        apply(idx*2,   l,   m, lz[idx]);
        apply(idx*2+1, m+1, r, lz[idx]);
        lz[idx] = Update::identity();
    }

    // Update [ql..qr] with u
    void update(int ql, int qr, const Update &u,
                int idx=1, int l=1, int r=-1) {
        if (r == -1) r = n;
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(idx, l, r, u);
            return;
        }
        push(idx, l, r);
        int m = (l + r) >> 1;
        update(ql, qr, u, idx*2,   l,   m);
        update(ql, qr, u, idx*2+1, m+1, r);
        st[idx] = Node::merge(st[idx*2], st[idx*2+1]);
    }

    // Query on [ql..qr]
    Node query(int ql, int qr,
               int idx=1, int l=1, int r=-1) {
        if (r == -1) r = n;
        if (qr < l || r < ql) return Node::identity();
        if (ql <= l && r <= qr) return st[idx];
        push(idx, l, r);
        int m = (l + r) >> 1;
        Node L = query(ql, qr, idx*2,   l,   m);
        Node R = query(ql, qr, idx*2+1, m+1, r);
        return Node::merge(L, R);
    }
};

// --- Example: Range Add & Range Max ---
struct MaxNode {
    long long mx;
    static MaxNode identity() { return {LLONG_MIN}; }
    static MaxNode merge(const MaxNode &a, const MaxNode &b) {
        return { max(a.mx, b.mx) };
    }
};

struct AddUpdate {
    long long v;
    static AddUpdate identity() { return {0}; }
    void apply(MaxNode &node, int l, int r) const {
        node.mx += v;
    }
    void combine(const AddUpdate &other) {
        v += other.v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<MaxNode> a(n+1);
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        a[i] = {x};
    }

    SegmentTree<MaxNode, AddUpdate> seg(n);
    seg.build(a);

    int m; cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            long long v; cin >> v;
            seg.update(l, r, AddUpdate{v});
        } else {
            auto res = seg.query(l, r);
            cout << res.mx << '\n';
        }
    }
    return 0;
}
