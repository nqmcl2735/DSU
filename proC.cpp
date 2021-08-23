//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 1000000
#define MOD
#define Task "proC"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int nxt[maxn];
pii a[maxn];
int n, m, res = 0;
int get_next(int x)
{
    if(nxt[x] == x) return x;
    return (nxt[x] = get_next(nxt[x]));
}
void sol (int l, int r)
{
    bool flg = 1;
    int des = get_next(r + 1);
    while (l <= r)
    {
        int u = get_next(l);
        if(u != l) flg = 0;
        nxt[l] = des;
        l = u + 1;
    }
    if (flg) res ++;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    vi v;
    for (int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        a[i] = mp(l,r);
        v.PB(l);
        v.PB(r);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())- v.begin());
    for (int i = 1; i <= sz(v) + 1; i ++) nxt[i] = i;
    for (int i = m; i >= 1; i --)
    {
        a[i].F = lower_bound(v.begin(), v.end(),a[i].F) - v.begin() + 1;
        a[i].S = lower_bound(v.begin(), v.end(),a[i].S) - v.begin() + 1;
        sol(a[i].F, a[i].S);
    }
    cout << res;
}
