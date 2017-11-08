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
train_case = int(sys.argv[3])
allow_s_eq_t = int(sys.argv[4])

n = max_n
m = n - 1
p = 0 if train_case == 0 else 1

nodes = shuffled(n) # Shuffle node labels
s = randint(0, n - 1)
while True:
  t = randint(0, n - 1)
  if allow_s_eq_t or s != t:
    break
if s > t:
  s, t = t, s

print("%d %d %d %d" % (n, m, nodes[s] + 1, nodes[t] + 1))

edge_map = shuffled(n - 1) # Shuffle print order of edges
weights = [randint(2, 1000) for i in range(n - 1)]
for i in range(n - 1):
  if randint(0, 1) > 0:
    print("%d %d %d" % (nodes[edge_map[i]] + 1, nodes[edge_map[i] + 1] + 1, weights[edge_map[i]]))
  else:
    print("%d %d %d" % (nodes[edge_map[i] + 1] + 1, nodes[edge_map[i]] + 1, weights[edge_map[i]]))

print(p)

train_edge = randint(s, t - 1) if s != t else randint(0, m - 1)
t = sum(weights[s:train_edge]) if s < train_edge else sum(weights[train_edge:s])
w = weights[train_edge]
u = nodes[train_edge] + 1
v = nodes[train_edge + 1] + 1
if train_case == 1:
  print("%d %d %d %d" % (u, v, t, w + 1))
elif train_case == 2:
  if randint(0, 1) > 0: # Wait is not worth it
    print("%d %d %d %d" % (u, v, t + randint(2, 1000), w - 1))
  else: # Cannot pick train on time
    print("%d %d %d %d" % (u, v, int(t * random()), w - 1))
elif train_case == 3:
  print("%d %d %d %d" % (u, v, t, w - 1))
elif train_case == 4: # Edge is not in the direction we need
  print("%d %d %d %d" % (v, u, t, w - 1))
