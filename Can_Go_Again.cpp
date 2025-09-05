#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long dis[1005];

int main()
{

    int n, e;
    cin >> n >> e;
    vector<Edge> egdeL;
    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        egdeL.push_back(Edge(a, b, c));
    }

    long long inf = 1e18;

    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
    }
    int s;
    cin >> s;
    dis[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool cheek = false;
        for (auto ed : egdeL)
        {

            if (dis[ed.a] != inf && dis[ed.a] + ed.c < dis[ed.b])
            {
                dis[ed.b] = dis[ed.a] + ed.c;
                cheek = true;
            }
        }
        if (!cheek)
            break;
    }

    for (auto ep : egdeL)
    {

        if (dis[ep.a] != inf && dis[ep.a] + ep.c < dis[ep.b])
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    int z;
    cin >> z;
    while (z--)
    {
        int k;
        cin >> k;

        if (dis[k] == inf)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[k] << endl;
        }
    }

    return 0;
}
