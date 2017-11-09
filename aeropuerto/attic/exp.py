import sys
from random import seed, random, randint, shuffle


seed(hash(sys.argv[1]))

n = int(sys.argv[2])
h = int(sys.argv[3]) # Must divide n - 1
m = (n - 1) // h * ((h - 1) + (h - 1) // 2 * (h - (h + 1) // 2))
p = 0

nodes = list(range(n)) # Shuffle node labels
shuffle(nodes)
s = 0
t = n - 1

print("%s %s %s %s" % (n, m, nodes[s] + 1, nodes[t] + 1))

edges = [(h * i, h * i + j, randint(1, 1000)) for i in range((n - 1) // h) for j in range(1, (h + 1) // 2)]
edges.extend([(h * i + j, h * i + k, randint(1, 1000)) for i in range((n - 1) // h) for j in range(1, (h + 1) // 2) for k in range((h + 1) // 2, h)])
edges.extend([(h * i + j, h * (i + 1), randint(1, 1000)) for i in range((n - 1) // h) for j in range((h + 1) // 2, h)])

shuffle(edges)
for edge in edges:
  if randint(0, 1) > 0:
    print("%s %s %s" % (nodes[edge[0]] + 1, nodes[edge[1]] + 1, edge[2]))
  else:
    print("%s %s %s" % (nodes[edge[1]] + 1, nodes[edge[0]] + 1, edge[2]))

print(p)
