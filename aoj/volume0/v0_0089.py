#-*- coding: utf_8 -*-

data = []
data.append([int(input())])
length = 2
counter = 0
while length != 1:
    r = [int(x) for x in input().split(",")]
    data.append(r)
    length = len(r)
    counter += 1

N = int((counter + 1 )/ 2) + 1
dp = [[0 for i in range(N)] for j in range(N)]
data_arr = [[0 for i in range(N)] for j in range(N)]

left = data[:N]
right = data[N:]

i = 0
for v in left:
    for idx, r in enumerate(v):
        data_arr[i - idx][idx] = r
    i += 1
right.reverse()
for i, v in enumerate(right):
    for idx, r in enumerate(v):
        data_arr[N - 1 - idx][N - 1 - i + idx] = r


dp[0][0] = data_arr[0][0]

for i in range(1, N):
    dp[0][i] = dp[0][i - 1] + data_arr[0][i]
    dp[i][0] = dp[i - 1][0] + data_arr[i][0]

for i in range(1, N):
    for j in range(1, N):
        dp[i][j] += data_arr[i][j] + max(dp[i - 1][j], dp[i][j - 1])

print(dp[N - 1][N - 1])
# 
# def dfs(n, i, mx):
#     if n == len(first) - 1:
#         s = mx * 2 + data[n][i]
#         mx_arr[i] = max(s, mx_arr[i])
#         return
# 
#     mx += data[n][i]
#     dfs(n + 1, i, mx)
#     dfs(n + 1, i + 1, mx)
# 
# dfs(0, 0, 0)
# 
# print(max(mx_arr))
