import math
n = int(input())
isPrime = [True for _ in range(n)]

def solve():
    isPrime[0] = isPrime[1] = False
    i =2
    while i * i <= n:
        if(isPrime[i]):
            for j in range(i*i, n+1, i):
                isPrime[j] = False
        i += 1
solve()

'''
에라토스테네스의 체를 이용한 빠른 소인수분해
'''
minFactor = [i for i in range(n+1)]
minFactor[0] = minFactor[1] = -1
i = 2
while i* i <= n:
    if(minFactor[i] == i) :
        for j in range(i*i, n+1, i):
            if(minFactor[j] == j):
                minFactor[j] = i
    i += 1
