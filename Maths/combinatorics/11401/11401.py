#!/usr/bin/env python3
while(1):
    n = int(input())
    if (n < 3):
        break
    n = n-2    
    ans = (4 * n**3 + 6*n**2 -4*n -3 + 3*(-1)**n)//48
    print(ans)