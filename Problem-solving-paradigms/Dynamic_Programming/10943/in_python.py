#!/bin/python3
import math

while (1):
	words = input().split()
	n = int (words[0])
	k = int (words[1])

	#print (n  , k)
	if (n ==0 and k ==0 ):
		break

	x1 = math.factorial(n+k-1)
	x2 = math.factorial(k-1)
	x3 = math.factorial (n)

	ans = x1 // (x2 * x3)
	ans = ans % 1000000

	print(ans)

