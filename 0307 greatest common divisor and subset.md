```c
#include <stdio.h>

int gcm(int a, int b)
{
    if(!(b % a)) return a;
    gcm(b, a % b);
}

int cf(int *arr, int a)
{
    int order = 0;
    for(int i = 1; i <= a; i++)
    {
        if(!(a % i))
        {
            arr[order++] = i;
        }
    }
    return order;
}

int main()
{
    int a = gcd(24, 18), arr[10] = {0, }, n;
    n = cf(arr, a);
    for(int i = 0; i < n; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i&(1 << j))
            {
                printf("%d ", arr[j]);
            }
        }
        printf("\n");
    }
}
```

비트 마스킹으로 부분 집합 표현하는 방법이다. 비트마스킹에 대해 공부해봐야겠다.