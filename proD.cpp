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
#define maxn 300005
#define MOD
#define Task "proD"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
int par[maxn];
int res[maxn];
int nxt[maxn];
int get_next(int x)
{
    if(nxt[x] == x) return x;
    nxt[x] = get_next(nxt[x]);
    return nxt[x];
}
void sol(int l, int r, int x)
{
    int des = get_next(r + 1);
    while (l <= r)
    {
        int u = get_next(l);
        if (u > r) break;
        if (u != x) res[u] = x;
        if (u <= x) nxt[u] = x;
        else nxt[u] = des;
        l = u + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        nxt[i] = i;
    while(m --)
    {
        int l, r, x;
        cin >> l >> r >> x;
        sol(l, r, x);
    }
    for (int i = 1; i <= n; i ++)
        cout << res[i] << " ";
}
