import re
import sys
import subprocess

outcome = subprocess.run(['convert', sys.argv[1], 'txt:-'], stdout=subprocess.PIPE, universal_newlines=True)

regex = re.compile('(\d+),(\d+): \(\d+,\d+,\d+,(\d+)\) ')

matrix = [[0 for x in range(64)] for y in range(64)]
for line in outcome.stdout.split('\n'):
    m = regex.match(line)
    if m:
        x = int(m.group(1))
        y = int(m.group(2))
        opacity = int(m.group(3))
        if opacity > 0:
            matrix[y][x] = 1

for row in matrix:
    for i, col in enumerate(row):
        if i > 0:
            print(' ', end='')
        print(col, end='')
    print()
