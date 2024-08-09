#include <cstdio>
int ix, iy;
int ia, ib;
long long x, y;
long long a, b;
int main()
{
    scanf("%lld%lld", &x, &y);
    scanf("%lld%lld", &a, &b);
    ix = x;
    iy = y;
    ia = a;
    ib = b;
    if (x * a != ix * ia || x * b != ix * ib || y * a != iy * ia || y * b != iy * ib)
    {
        printf("long long int\n");
    }
    else
    {
        printf("int\n");
    }
    return 0;
}