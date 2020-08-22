from bs4 import BeautifulSoup
import requests

url = 'http://ocw.nthu.edu.tw/ocw/index.php?page=course&cid=7&'
r = requests.get(url)
text = r.text


soup = BeautifulSoup(text, 'lxml')
li = soup.find('li', id='search2')

a = li.find_all('a')

for i in a:
    print(i.get('href'))
