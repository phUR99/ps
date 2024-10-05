#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    string S, T;
    cin >> S >> T;
    vector<string> X;
    int l = S.size();
    while (S != T)
    {
        stack<int> idx;
        for (int i = 0; i < l; i++)
        {
            if (S[i] == T[i])
                continue;
            if (S[i] > T[i])
            {
                S[i] = T[i];
                X.push_back(S);
                continue;
            }
            idx.push(i);
        }
        if (idx.empty())
            break;
        S[idx.top()] = T[idx.top()];
        X.push_back(S);
    }
    cout << X.size() << '\n';
    for (auto &s : X)
    {
        cout << s << '\n';
    }

    return 0;
}
