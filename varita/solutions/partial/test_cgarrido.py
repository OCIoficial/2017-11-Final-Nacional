import os
import subprocess

#asumo que los casos estan en carpetas 0/ 1/ 2/ etc...
#ademas que el ejecutable es a.out

count = 0
success = 0

for i in range(10):
    mypath = str(i)
    onlyfiles = [f for f in os.listdir(mypath) if os.path.isfile(os.path.join(mypath, f))]
    for f in onlyfiles:
        path = os.path.join(str(i),f)
        with open(path, "r") as fp:
            out = int(subprocess.check_output("./a.out", stdin=fp))
        if out == i:
            success +=1
        count +=1
accuracy = 1.0*success/count

print("Number of cases: {}".format(count))
print("Number of correct cases: {}".format(success))
print("Acurracy: {}".format(accuracy))
