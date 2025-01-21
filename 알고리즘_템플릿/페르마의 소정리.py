'''
모듈러 정리는 곱셈, 덧셈, 뺄셈에는 성립하지만 나눗셈에서는 성립하지 않음
단, MOD가 소수일 경우에는 역원을 이용하여 계산할 수 있음

(a/b)%MOD = a * (b^(MOD-2)) %MOD

페르마의 소정리
소수 p와 정수 a에 대하여 a^p = a mod p;
만약 a와 p가 서로소이면 a^(p-1) = 1 mod p를 만족한다

'''
# O(nlgP)
def solve(v, p):
    if p == 0 :
        return 1
    if (p & 1) :
        return solve(v, p-1) * v
    half = solve(v, p/2)
    return half * half

MOD = int(1e9+7)
a = 1e3
b = 666
ret = a % MOD * solve(b, MOD-2) % MOD
print(ret)

'''
O(n + lgP)
팩토리얼의 역원의 점화식
n!의 역원을 안다면 n*n!^-1 = (n-1)!^-1이므로
n!부터 역으로 계산산
'''
'''
p = (p/k)*k + p%k
0 = (p/k)*k  + p % k mod p
-p/k *k = p %k mod p
(p%k)^-1 = (-p/k*k)^-1 mod p
k^-1 = (p%k)^-1 *(-p/k)
'''
