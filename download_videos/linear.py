from bs4 import BeautifulSoup
import requests
from you_get import common
import subprocess
import os

file_name = 'linear'

my_open = open(file_name, 'r')

main_path = '/Users/ljh/Tohoku/LinearAlgebra/L'

index = 1
for eachline in my_open:
    path = main_path + str(index)
    index = index + 1
    folder = os.path.exists(path)
    if not folder:
        os.mkdir(path) 

    url = eachline.strip()
    print(url)
    r = requests.get(url)
    text = r.text

    soup = BeautifulSoup(text, 'lxml')

    h4 = soup.findAll("h4")

    names = list()
    for h in h4:
        label = h.get_text()
        if 'L' in label:
            names.append(label)

    videoFrame = soup.findAll("iframe", {"name": "videoFrame"})
    links = list()
    for i in videoFrame:
        links.append(i.get('src'))


    videos = dict(zip(names, links))

    for key in videos:
        # print(key)
        # print(videos[key])
        subprocess.run(["you-get", "-o", path, "-O", key, videos[key]])

my_open.close()



