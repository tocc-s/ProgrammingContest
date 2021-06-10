import sys
input = sys.stdin.readline

h, w = map(int, input().split())
a = []
for i in range(h):
  a.append(list(map(int, input().split())))

hori = [0] * w
ver = [0] * h
for i in range(h):
  for j in range(w):
    ver[i] += a[i][j]  
    hori[j] += a[i][j]

ans = [[0] * w for i in range(h)]
for i in range(h):
  for j in range(w):
    ans[i][j] = ver[i] + hori[j] - a[i][j]

for i in range(h):
  for j in range(w):
    if(j != w - 1):
      print(ans[i][j], end=" ")
    else :
      print(ans[i][j])