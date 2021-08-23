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
#define maxn 100005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
int pr[maxn];
struct data{
    int pos, val;
};
bool cmp(data a, data b)
{
    return a.val < b.val;
}
data a[maxn];
vi ke[maxn];
int sz[maxn];
int d[maxn];
int res[maxn];
int find_pr(int x)
{
    if (!pr[x]) return x;
    else return (pr[x] = find_pr(pr[x]));
}
void noi(int x, int y)
{
    if (find_pr(x) == find_pr(y))
        return ;
    x = find_pr(x);
    y = find_pr(y);
    pr[x] = y;
    sz[y] += sz[x];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i].val;
        a[i].pos = i;
        sz[i] = 1;
        res[i] = -1;
    }
    while (m --)
    {
        int x, y;
        cin >> x >> y;
        ke[x].PB(y);
        ke[y].PB(x);
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = n; i; i --)
    {
        int u = a[i].pos;
        d[u] = 1;
        for (int j = 0; j < sz(ke[u]); j ++)
            if(d[ke[u][j]]) noi(u, ke[u][j]);
        int pz = sz[find_pr(u)];
        if (res[pz] == -1) res[pz] = a[i].val;
    }
    for (int i = n - 1; i; i --)
        res[i] = max(res[i], res[i + 1]);
    for (int i = 1; i <= n; i ++)
        cout << res[i] << " ";
}
