/*
유클리드 호제법의 성질 활용
베주 항등식에 따라서 gcd(a, b) = d일 때
ax + by = d를 만족하는 x, y가 존재한다
유클리드 호제법에 따라서
a = b * q0 + r1
b = r1 *q1 +r2
r1 = r2 * q2 + r3...
ri+1 = 0일 때 알고리즘 종료.
*/
void EEA(int a, int b)
{
    int r0 = a, r1 = b;
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;
    int tmp = 0, q = 0;
    while (r1)
    {
        q = r0 / r1;
        tmp = r0;
        r0 = r1;
        // ti+1 = ri-1 % ri(유클리드 호제법)
        r1 = tmp - r1 * q;
        tmp = s0;
        s0 = s1;
        // si+1 = si-1 - si*q;
        s1 = tmp - s1 * q;        
        tmp = t0;
        t0 = t1;
        // ti+1 = ti-1 - ti*q;
        t1 = tmp - t1 * q;
    }
}