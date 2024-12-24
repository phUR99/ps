'''
모듈러 정리는 곱셈, 덧셈, 뺄셈에는 성립하지만 나눗셈에서는 성립하지 않음
단, MOD가 소수일 경우에는 역원을 이용하여 계산할 수 있음

(a/b)%MOD = a * (b^(MOD-2)) %MOD
'''

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


