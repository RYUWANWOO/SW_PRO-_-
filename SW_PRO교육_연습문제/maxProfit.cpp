#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;



int ans, change;
string s;

void dfs(int index, int current)
{
    if (current == change)
    {
        ans = max(ans, stoi(s));
        return;
    }
    for (int i = index; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            dfs(i, current + 1);
            swap(s[i], s[j]);
        }
    }
}

int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> s >> change;
        ans = 0;

        if (change > s.size())
            change = s.size();
        dfs(0, 0);
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}