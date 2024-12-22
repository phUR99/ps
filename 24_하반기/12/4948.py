import sys
data = sys.stdin.read()
MAX = 300000
prefix = [1 for _ in range(MAX+1)]
# 공백 대신 \n을 기준으로 스플릿 할 경우 마지막 입력에 공백이 들어가서 제대로 분리가 안 되는 경우가 있음
arr = [*map(int, data.split())]
prefix[0] = prefix[1] = 0
i = 2
while i * i <= MAX:
    if(prefix[i] == 1) :
        for j in range(i*i, MAX+1, i):
            prefix[j] = 0
    i+=1
for i in range(2, MAX+1):
    prefix[i] = prefix[i-1] + prefix[i]


for ar in arr:
    if(ar == 0): break
    print(prefix[2*ar] - prefix[ar])
