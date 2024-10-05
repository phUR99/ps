#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
부분 배열을 직접 세는 것은 어렵다 -> 전체 배열 - 독립  배열
O(c)
*/

long long countSubarrays(const vector<int> &A, int N)
{
    unordered_map<int, vector<int>> positions;

    for (int i = 0; i < A.size(); ++i)
    {
        positions[A[i]].push_back(i);
    }

    long long totalSubarrays = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (positions.find(i) == positions.end())
            continue;

        const vector<int> &pos = positions[i];
        int C_i = pos.size();

        vector<int> extendedPos = {-1};
        extendedPos.insert(extendedPos.end(), pos.begin(), pos.end());
        extendedPos.push_back(A.size());
        long long notContaining_i = 0;
        for (int j = 1; j <= C_i + 1; ++j)
        {
            int left = extendedPos[j - 1] + 1;
            int right = extendedPos[j] - 1;
            int length = right - left + 1;
            // nC2(n == 구간의 길이)
            if (length > 0)
            {
                notContaining_i += (long long)length * (length + 1) / 2;
            }
        }
        // 전체 배열에서 빼기
        long long total = (long long)A.size() * (A.size() + 1) / 2;
        totalSubarrays += total - notContaining_i;
    }

    return totalSubarrays;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    cout << countSubarrays(A, N) << endl;

    return 0;
}
