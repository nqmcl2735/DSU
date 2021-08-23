//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <ll,ll>
#define vi vector <ll>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 200005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll n, m, q;
ll pr[maxn];
ll sum[maxn];
pii canh[maxn];
ll res[maxn];

bool tt[maxn];
vi val[maxn];

class query{
    public :
    char type;
    ll x, y;
    void nhap()
    {
        cin >> type;
        if (type == 'D')
        {
            cin >> x;
            tt[x] = 1;
        }
        else {
            cin >> x >> y;
            val[x].PB(y);
        }
    }
};
query que[maxn];

priority_queue<pii> pq;

ll find_pr(ll x){
    if (pr[x] == x) return x;
    return (pr[x] = find_pr(pr[x]));
}
pii get(ll i)
{
    ll x = find_pr(i);
    return {sum[x], x};
}
void noi(ll x, ll y)
{
    if (find_pr(x) == find_pr(y)) return ;
    x = find_pr(x);
    y = find_pr(y);
    sum[x] += sum[y];
    pr[y] = x;
}
ll find_res()
{
    while(pq.top().F != sum[find_pr(pq.top().S)]) pq.pop();
    return pq.top().F;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++)
    {
        pr[i] = i;
        ll x; cin >> x;
        val[i].PB(x);
        pq.push({x, i});
    }
    for (int i = 1; i <= m; i ++)
    {
        ll x, y;
        cin >> x >> y;
        canh[i] = mp(x, y);
    }
    for(int i = 1; i <= q; i ++)
        que[i].nhap();
    for(int i = 1; i <= n; i ++)
    {
        sum[i] = val[i].back();
        pq.push(get(i));
        val[i].pop_back();
    }
    for(int i = 1; i <= m; i ++)
        if(!tt[i]){
            noi(canh[i].F, canh[i].S);
            pq.push(get(canh[i].F));
        }
    for (int i = q; i >= 1; i --)
    {
        res[i] = find_res();
        if(que[i].type == 'D')
        {
            noi(canh[que[i].x].F, canh[que[i].x].S);
            pq.push(get(canh[que[i].x].F));
        }
        else
        {
            sum[find_pr(que[i].x)] += val[que[i].x].back() - que[i].y;
            val[que[i].x].pop_back();
            pq.push(get(que[i].x));
        }
    }
    for(int i = 1; i <= q; i ++) cout << res[i] << "\n";
}
