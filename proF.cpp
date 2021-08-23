//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 1005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int m, n, q;
int x1, x2, yy1, y2;
int clr[maxn][maxn];
int pr[maxn * maxn];
vii ke[maxn * 10];
int res[maxn * 10];
int cnt = 0, cont = 0;
int get_pr(int x)
{
    if(!pr[x]) return x;
    return (pr[x] = get_pr(pr[x]));
}
void noi(int x, int y)
{
    if (x == 0 || y == 0) return;
    if (get_pr(x) == get_pr(y)) return ;
    pr[get_pr(x)] = y;
    cnt --;
}
Update(int x, int y)
{
    clr[x][y] = ++cont;
    cnt ++;
    noi(cont, clr[x][y + 1]);
    noi(cont, clr[x][y - 1]);
    noi(cont, clr[x + 1][y]);
    noi(cont, clr[x - 1][y]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    cin >> q;
    for (int i = 1; i <= q; i ++) {
        cin >> x1 >> yy1 >> x2 >> y2;
        for (int j = x1; j <= x2; j ++)
            for (int z = yy1; z <= y2; z ++)
                if (!clr[j][z])
                {
                    clr[j][z] = 1;
                    ke[i].PB({j, z});
                }
    }
    for (int j = 1; j <= m; j ++)
        for (int z = 1; z <= n; z ++)
            if (!clr[j][z]) ke[q + 1].PB({j, z});
    reset(clr);
    for(int i = q + 1; i > 1; i --) {
        for (int j = 0; j < sz(ke[i]); j ++)
            Update(ke[i][j].F, ke[i][j].S);
        res[i - 1] = cnt;
    }
    for (int i = 1; i <= q; i++)
        cout << res[i] << "\n";
}
