import subprocess
import os
# 生成目录

path = '/Users/ljh/Tohoku/ParallelProgramming/L'
for i in range(9,27):
    temp = path + str(i)
    print(temp)
    folder = os.path.exists(temp)
    if not folder:
        os.mkdir(temp) 

# subprocess.run(["you-get", "-o", d, "-O", "L23D", "http://ocw.nthu.edu.tw/videosite/index.php?op=watch&id=7721&filename=854_480_768.MP4&type=download&cid=231&chid=2644"])
