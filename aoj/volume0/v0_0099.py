#-*- coding: utf_8 -*-

# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0099
# TLE

n, q = [int(x) for x in input().split(' ')]
memo = [0] * n
idx = 0

for i in range(q):
    a, v = [int(x) for x in input().split(' ')]
    a -= 1
    memo[a] += v
    if v > 0:
        if memo[idx] < memo[a]:
            idx = a
        elif memo[idx] == memo[a]:
            idx = memo.index(memo[idx])
    elif v < 0:
        idx = memo.index(max(memo))

    print(idx + 1, memo[idx])

