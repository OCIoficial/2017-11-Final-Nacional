"""66% de accuracy sobre todos los tests usando 1 ejemplo por clase (en 'hechizos/')"""

import os
import fileinput


def d(h1, h2):
    return sum(abs(e1 - e2) for v1, v2 in zip(h1, h2) for e1, e2 in zip(v1, v2))


process_line = lambda line: [int(x) for x in line.split()]
examples = [list(map(process_line, open('hechizos/' + f).readlines())) for f in os.listdir('hechizos/')]

test = [process_line(line) for line in fileinput.input()]
print(min([(class_, d(e, test)) for class_, e in enumerate(examples)], key=lambda x: x[1])[0])
