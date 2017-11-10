import os
import glob
import random
import sys
import shutil

random.seed()

for category in range(10):
    txts = random.sample(glob.glob(f"{sys.argv[1]}/txt/{category}/*.txt"), 5)

    directory = f"{sys.argv[2]}/hechizo-{category}"
    if not os.path.exists(directory):
        os.makedirs(directory)

    for i, txt in enumerate(txts):
        img = txt.replace('.txt', '').replace('txt', 'img')
        shutil.copyfile(txt, f"{directory}/{i+1}.txt")
        shutil.copyfile(img, f"{directory}/{i+1}.png")
