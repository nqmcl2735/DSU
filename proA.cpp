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
#define maxn 1000005
#define Task "proA"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
int pr[maxn];
int q, x, y;
int find_pr(int x)
{
    if (pr[x] < 0) return x;
    else return (pr[x] = find_pr(pr[x]));
}
void noi(int x, int y)
{
    if (find_pr(x) == find_pr(y))
        return ;
    x = find_pr(x);
    y = find_pr(y);
    if (pr[y] < pr[x])swap(x, y);
    pr[x] += pr[y];
    pr[y] = x;
}
void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        pr[i] = -1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    nhap();
    while (m --)
    {
        cin >> q >> x >> y;
        if (q == 1) noi(x, y);
        else cout << (find_pr(x) == find_pr(y)) << "\n";
    }
}
