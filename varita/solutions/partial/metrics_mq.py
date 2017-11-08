# lee el nombre de archivo de la stdin e imprime el accuracy por clase y total

from collections import defaultdict
import sys

predicciones = defaultdict(list)

with open(sys.argv[1]) as f:
    for line in f:
        true, pred = map(int, line.split())
        predicciones[true].append(pred)

total_correct = 0
total = 0
print("label\taccuracy")
for true, preds in predicciones.items():
    print(true, f"{sum(1 for p in preds if p == true) / len(preds)}", sep="\t")
    total += len(preds)
    total_correct += sum(1 for p in preds if p == true)

print("total accuracy:", total_correct / total)
