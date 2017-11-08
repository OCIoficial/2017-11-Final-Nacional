import sys
from random import seed, random, randint


def shuffled(n):
  s = [0] * n
  for i in range(n):
    c = randint(0, i)
    if c != i:
      s[c], s[i] = i, s[c]
    else:
      s[i] = i
  return s


seed(hash(sys.argv[1]))

max_n = int(sys.argv[2])
max_m = int(sys.argv[3])
max_p = int(sys.argv[4])
max_t = int(sys.argv[5])

n = max_n
m = max_m
p = max_p

nodes = shuffled(n) # Shuffle node labels
s = randint(0, n - 1)
t = randint(0, n - 1)

print("%s %s %s %s" % (n, m, nodes[s] + 1, nodes[t] + 1))

# Random tree
edges = [(randint(0, i - 1), i) for i in range(1, n)]
# Fill with edges
for i in range(n - 1, m):
  while True:
    u = randint(0, n - 1)
    v = randint(0, n - 1)
    if u > v:
      u, v = v, u
    if u != v and (u, v) not in edges:
      edges.append((u, v))
      break

for i in range(m):
  if randint(0, 1) > 0:
    print("%s %s %s" % (nodes[edges[i][0]] + 1, nodes[edges[i][1]] + 1, randint(1, 1000)))
  else:
    print("%s %s %s" % (nodes[edges[i][1]] + 1, nodes[edges[i][0]] + 1, randint(1, 1000)))

print(p)

trains = []
for i in range(p):
  while True:
    u = randint(0, n - 1)
    v = randint(0, n - 1)
    if u != v:
      print("%s %s %s %s" % (nodes[u] + 1, nodes[v] + 1, randint(0, max_t), int(1 + (1000**0.5 * random())**2)))
      break
