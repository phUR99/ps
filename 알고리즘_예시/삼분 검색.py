'''
삼분 검색이 가능한 조건 3
1. unimodal한 함수일 때(단 한 개의 극점을 가지고 있을 때)
2. 최대점 왼쪽에서는 함수가 순증가할 때
3. 최대점 오른쪽에서는 함수가 순감소할 때
단, 최대점의 구간이 같은 볼록함수 형태는 가능하다.(순증가, 순감소가 아닐 때)

전제) 함수가 unimodal한 볼록함수 혹은 오목함수 형태임을 찾기
1. 최대치를 포함하는 후보 구간 (l, r)을 구성
2. 구간을 삼등분 -> (2l+r)/3, (l+2r)/3
3. 왼쪽 구간과 오른쪽 구간을 비교한다
왼쪽 구간이 클 경우 -> 오른쪽 구간을 버린다(r -> mr)
오른쪽 구간이 클 경우 -> 왼쪽 구간을 버린다(l -> ml)

종료 조건
1. 특정 오차 이하까지 반복하기
2. 특정 횟수만큼 반복하기(100, 1000, ...)
3. 조건 파악하고 반복하기
'''


import math
n = int(input())
arr = [*map(int, input().split())]

def solve(x):    
    ret = 0
    for i in range(n):
        ret += abs(arr[i] - i * x)
    return ret

l ,r = 1, int(1e9)
'''
왜 종료조건을 r - l >= 3으로 설정?

이번 반복 이후부터는 r - l < 3이 되는데 ml, 
mr이 1 이내의 차이가 되기 때문에 mr - ml의 차이가 1일 때까지만 삼분 검색을 수행(int이므로 1 이내는 표현하지 않는다)
'''
while r - l >= 3:
    ml = int((l*2+r)/3)
    mr = int((l+2*r)/3)
    if(solve(ml) > solve(mr)):
        l = ml
    else:
        r = mr
ret = float('inf')
for i in range(l, r+1):
    ret = min(ret, solve(i))
print(ret)


        