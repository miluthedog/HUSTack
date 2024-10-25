#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int main(){
    int n; // node
    int m; // arc
    cin >> n >> m;
    vector<vector<pair<int, int>>> input(n + 1);

    for (int i = 0; i < m; ++i){
        int start;
        int end;
        int weight;
        cin >> start >> end >> weight;
        input[start].emplace_back(end, weight);
    }
    int s; // start
    int t; // target
    cin >> s >> t;

    vector<int> path(n + 1, inf);
    path[s] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqueue;
    pqueue.push({0, s});

    // Dijkstra
    while (!pqueue.empty()){
        int curPath= pqueue.top().first;
        int curNode = pqueue.top().second;
        pqueue.pop();

        if (curPath > path[curNode])
            continue;

        for (auto &[nextNode, weight] : input[curNode]){
            int distance = curPath + weight;

            if (distance < path[nextNode]){
                path[nextNode] = distance;
                pqueue.push({distance, nextNode});
            }
        }
    }

    if (path[t] == inf)
        cout << -1 << endl;
    else
        cout << path[t] << endl;
    return 0;
}
