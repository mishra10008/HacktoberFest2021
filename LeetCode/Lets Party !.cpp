#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int t, i, j, N, X, x, y, ans;
    vector< set<int> > tables;
   // map<int, set<int> > mapped;
    bool allottedTable[105];

    cin >> t;

    while (t--)
    {
        cin >> N >> X;

       // mapped.clear();
        tables.clear();
        tables.resize(N+1);
        memset(allottedTable, sizeof(allottedTable), false);

        while (true)
        {
            cin >> x;
            if (x == -1)
                break;
            cin >> y;
            tables[x].insert(y);
            //mapped[y].insert(x);
        }

        ans = 0;
        while (true)
        {
            int lowest = -1;
            for (i = 1; i <= N; i++)
            {
                if (tables[i].size() > 0)
                {
                    if (lowest == -1)
                        lowest = i;
                    else if (tables[i].size() < tables[lowest].size())
                        lowest = i;
                }
            }

            if (lowest == -1)
                break;

            allottedTable[lowest] = true;
            int deleteTable = *tables[lowest].begin();

            for (i = 1; i <= N; i++)
            {
                tables[i].erase(deleteTable);
                if (i == lowest)
                {
                    tables[i].clear();
                }
            }

            ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}
