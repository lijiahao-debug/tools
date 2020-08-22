import subprocess
file_name = 'temp'

my_open = open(file_name, 'r')

path = '/Users/ljh/Tohoku/Algorithm/videos'

for eachline in my_open:
    print(eachline.strip())
    subprocess.run(["you-get", "-o", path, eachline.strip()])