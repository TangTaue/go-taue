import re
import requests
import json
from multiprocessing import Pool  #进程模块
from requests.exceptions import RequestException


def get_one_page(url):
    headers = {
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.186 Safari/537.36"
    }
    try:
         response=requests.get(url,headers=headers)
         if response.status_code==200:
             return response.text
         return None
    except RequestException:
        return None
def  parese_one_page(html):
    reg=re.compile('<dd>.*?board-index.*?>(\d+)</i>.*?data-src="(.*?)".*?name"><a'
                   +'.*?>(.*?)</a>.*?star">(.*?)</p>.*?releasetime">(.*?)</p>'
                   +'.*?integer">(.*?)</i>.*?fraction">(.*?)</i>.*?</dd>',re.S) #生成正则表达式 生成解析对象。
    items=re.findall(reg,html)

    for item in items:
        yield {
            'name':item[0],
            'index':item[1],
            'tittle':item[2],
            'actor':item[3].strip()[3:],
            'time':item[4].strip()[5:],
            'score':item[5]+item[6]
        }

def write_to_file(content):
    with open('start.txt','a',encoding='UTF-8') as f:
        f.write(json.dumps(content,ensure_ascii=False)+'\n')
        f.close()
def __main__(offset):
    url="http://maoyan.com/board/4?offset="+str(offset)
    html=get_one_page(url)
    for i in parese_one_page(html):
        print(i)
        write_to_file(i)
if __name__=='__main__':
    #for i in range(10):
    # __main__(i*10)
     pool=Pool()
     pool.map(__main__,[i*10 for i in range(10)])

