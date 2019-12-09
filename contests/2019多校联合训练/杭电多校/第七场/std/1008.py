def solve(a, b, x, y):
  def get(a, b, left, stra):
    # print(a, b, left, stra)
    return a * left + b * stra
  if y < 0:
    return solve(a, b, x, -1 - y)
  if x >= 0:
    pos = [0, y, max(x - 1, 0)]
    if y < x:
      func = lambda i: x - 1 - i + max(y - i, 0)
    else:
      func = lambda i: y - i + max(x - i - 1, 0)
  else:
    x_ = abs(x)
    pos = [0, x_, y]
    if y < x_:
      func = lambda i: x_ - i + max(y - i, 0)
    else:
      func = lambda i: y - i + max(x_ - i, 0)
  return min([get(a, b, i, func(i)) for i in pos])


def retrieve_space(x, y):
  if y < 0:
    return retrieve_space(x, -1 - y)
  if x >= 0:
    if y < x:
      space = [(i, x - 1 - i + max(y - i, 0)) for i in range(x)]
    else:
      space = [(i, y - i + max(x - i - 1, 0)) for i in range(y + 1)]
  else:
    x_ = abs(x)
    if y < x_:
      space = [(i, x_ - i + max(y - i, 0)) for i in range(x_ + 1)]
    else:
      space = [(i, y - i + max(x_ - i, 0)) for i in range(y + 1)]
  return space


# for x in range(-6, 6):
#   for y in range(5):
#     print(x, y, retrieve_space(x, y))


T = int(input())
for _ in range(T):
  a, b, x, y = map(int, input().split())
  print(solve(a, b, x, y))