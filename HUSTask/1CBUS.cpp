// not mine
#pragma GCC optimize ("O3", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define ar array
// #define db double
#define sz(x) (int)x.size()
// const db pi = acos(-1);
const int mxn = 23;
int n, k;
int a[mxn][mxn];
map<pair<int, vector<int>>, int> dp;
/*
dp[u][msk] = min cost to visit u and msk represents the set of passengers where
bit i = 0 if passenger i is not picked up
bit i = 1 if passenger i is on the bus
bit i = 2 if passenger i is dropped off
-> complexity O(2*n*3^n)
*/
void test(int u, vector<int> msk, int capacity)
{
    cout << u << ' ' << capacity << "\n";
    if (capacity < k)
    for (int v = n + 1; v <= 2 * n; v++)
        if (msk[v - n - 1] == 1) // drop off passenger v - n
        {
            vector<int> nmsk = msk;
            nmsk[v - n - 1] = 2;
            if (!dp.count({v, nmsk})) dp[{v, nmsk}] = dp[{u, {msk}}] + a[u][v];
            else dp[{v, nmsk}] = min(dp[{v, {nmsk}}], dp[{u, {msk}}] + a[u][v]);
            test(v, nmsk, capacity + 1);
        }
    if (capacity)
    {
        for (int v = 1; v <= n; v++)
        if (msk[v - 1] == 0) // pick up passenger v
        {
            vector<int> nmsk = msk;
            nmsk[v - 1] = 1;
            if (!dp.count({v, nmsk})) dp[{v, nmsk}] = dp[{u, {msk}}] + a[u][v];
            else dp[{v, nmsk}] = min(dp[{v, {nmsk}}], dp[{u, {msk}}] + a[u][v]);
            test(v, nmsk, capacity - 1);
        }
    }
    dp[{0, msk}] = min(dp[{0, {msk}}], dp[{u, {msk}}] + a[u][0]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
3 2
0 8 5 1 10 5 9 
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
    */
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++) cin >> a[i][j];

    for (int l = 0; l <= 2 * n; l++)
        for (int i = 0; i <= 2 * n; i++)
            for (int j = 0; j <= 2 * n; j++) a[i][j] = min(a[i][j], a[i][l] + a[l][j]);

    priority_queue<pair<int, pair<int, vector<int>>>, vector<pair<int, pair<int, vector<int>>>>, greater<pair<int, pair<int, vector<int>>>>> pq;
    pq.push({0, {0, vector<int>(n, 0)}});
    dp[{0, vector<int>(n, 0)}] = 0;
    while(!pq.empty())
    {
        auto top = pq.top();
        int cost = top.first;
        int u = top.second.first;

        // cout << u << ' ' << cost << '\n';

        vector<int> msk = top.second.second;
        pq.pop();

        // if finall state calculate go to 0
        if (msk == vector<int>(n, 2)) 
        {
            if (!dp.count({0, msk})) dp[{0, msk}] = dp[{u, msk}] + a[u][0];
            else dp[{0, msk}] = min(dp[{0, msk}], dp[{u, msk}] + a[u][0]);
            // cout << "OK";
            continue;
        }
        // cout << u << ' ' << dp[{u, {msk}}] << '\n';
        int capacity = k;
        for (int i = 0; i < n; i++) if (msk[i] == 1) capacity--;

        if (capacity < k)
        for (int v = n + 1; v <= 2 * n; v++)
            if (msk[v - n - 1] == 1) // drop off passenger v - n
            {
                vector<int> nmsk = msk;
                nmsk[v - n - 1] = 2;
                if (!dp.count({v, nmsk})) 
                {
                    dp[{v, nmsk}] = dp[{u, msk}] + a[u][v];
                    pq.push({dp[{v, nmsk}], {v, nmsk}});
                }
                else if (dp[{v, nmsk}] > dp[{u, msk}] + a[u][v])
                {
                    dp[{v, nmsk}] = dp[{u, msk}] + a[u][v];
                    pq.push({dp[{v, nmsk}], {v, nmsk}});
                }
            }
        if (capacity)
        {
            for (int v = 1; v <= n; v++)
            if (msk[v - 1] == 0) // pick up passenger v
            {
                vector<int> nmsk = msk;
                nmsk[v - 1] = 1;
                if (!dp.count({v, nmsk})) 
                {
                    dp[{v, nmsk}] = dp[{u, msk}] + a[u][v];
                    pq.push({dp[{v, nmsk}], {v, nmsk}});
                }
                else if (dp[{v, nmsk}] > dp[{u, msk}] + a[u][v])
                {
                    dp[{v, nmsk}] = dp[{u, msk}] + a[u][v];
                    pq.push({dp[{v, nmsk}], {v, nmsk}});
                }
            }
        }
    }

    cout << dp[{0, vector<int>(n, 2)}] << '\n';
    return 0;
}