# Esta no es una solución al problema..
# Debido a las características de ocimatic debe haber certeza en que las soluciones
# dentro de la carpeta `correct` producen resultados correctos ya que el output esperado
# es generado a partir del output de una solución. Debido a las características de este
# problema este archivo es un *workaround* que garantiza que el output es correcto
# inspeccionando directamente las imágenes dentro la carpeta `attic`.

import os
import sys
import glob

solution = {}
os.chdir(os.path.dirname(__file__))
for path in glob.glob('../../attic/cases/txt/*/*.txt'):
    category = os.path.basename(os.path.dirname(path))
    abspath = os.path.abspath(path)

    with open(path, 'r') as f:
        solution[f.read()] = category

print(solution[sys.stdin.read()])
