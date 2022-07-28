// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<int> adj[], int s, int d)
{
    adj[s - 1].push_back(d);
    adj[d - 1].push_back(s);
}

int main()
{
    int n, v, s, d;
    cout << "\nEnter number of vertices: ";
    cin >> v;
    cout << "\nEnter number of edges: ";
    cin >> n;
    vector<int> adj[v];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter source: ";
        cin >> s;
        cout << "\nEnter destination: ";
        cin >> d;
        addEdges(adj, s, d);
    }

    for (int i = 0; i < v; i++)
    {
        cout << "Vertices " << i + 1;
        for (auto x : adj[i])
            cout << "-> " << x;
        cout << endl;
    }
}