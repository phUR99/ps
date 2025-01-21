#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int inorder[100005];
int idx[100005];
int postorder[100005];
int n;
/*
재귀적 구성
1.postorder는 루트 노드가 제일 뒤에 출력되므로
서브트리의 순회 순서에서 맨 뒤에 있는게 루트 노드임
2.inorder에서 루트 노드의 위치를 찾은 후에
루트노드 왼쪽의 숫자
루트노드 오른쪽의 개수를 세어줌
이후 왼쪽의 숫자로 서브트리를 구성(postorder)
오른쪽의 숫자로 서브트리를 구성
*/

void preorder(int inLeft, int inRight, int postLeft, int postRight)
{
    if (postLeft > postRight || inLeft > inRight)
        return;
    int root = postorder[postRight];
    int rootIdx = idx[root];
    int left = rootIdx - inLeft;
    cout << root << ' ';
    // 왼쪽 서브트리의 개수는 rootidx - inleft;
    preorder(inLeft, rootIdx - 1, postLeft, postLeft + left - 1);
    // 오른쪽 서브트리의 개수는 N-1-left;
    preorder(rootIdx + 1, inRight, postLeft + left, postRight - 1);
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    preorder(0, n - 1, 0, n - 1);
    return 0;
}