import sys
input = sys.stdin.readline

def solve():
  a, b, c = map(int, input().split())
  if(a == b):
    if(c != b or c != a):
      print("Yes")
    else:
      print("No")
  elif(a == c):
    if(b != a or b != c):
      print("Yes")
    else:
      print("No")
  elif(b == c):
    if(a != b or a != c):
      print("Yes")
    else:
      print("No")
  else:
    print("No")
solve()