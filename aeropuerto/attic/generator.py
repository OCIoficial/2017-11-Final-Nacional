import sys
from random import seed, random, randint, shuffle


seed(hash(sys.argv[1]))

max_n = int(sys.argv[2])
max_m = int(sys.argv[3])
max_p = int(sys.argv[4])
max_t = int(sys.argv[5])

n = max_n
m = max_m
p = max_p

nodes = list(range(n)) # Shuffle node labels
shuffle(nodes)
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
shuffle(edges)

for edge in edges:
  if randint(0, 1) > 0:
    print("%s %s %s" % (nodes[edge[0]] + 1, nodes[edge[1]] + 1, randint(1, 1000)))
  else:
    print("%s %s %s" % (nodes[edge[1]] + 1, nodes[edge[0]] + 1, randint(1, 1000)))

print(p)

trains = []
for i in range(p):
  while True:
    u = randint(0, n - 1)
    v = randint(0, n - 1)
    if u != v:
      print("%s %s %s %s" % (nodes[u] + 1, nodes[v] + 1, randint(0, max_t), int(1 + (1000**0.5 * random())**2)))
      break
