from bs4 import BeautifulSoup
import requests
from you_get import common
import subprocess
import os

file_name = 'calculus'

my_open = open(file_name, 'r')

main_path = '/Users/ljh/Tohoku/calculus/L'

index = 23

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

    l = soup.findAll("div", {"class": "col-md-4 singleItem"})

    d = {}
    for i in l:
        label = i.get_text().strip()
        if 'R' not in label:
            link = i.findAll('a')
            d[label] = link[3].get('href')

    for i in d:
        subprocess.run(["you-get", "-o", path, "-O", i, d[i]])

my_open.close()

