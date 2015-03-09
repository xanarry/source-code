import urllib2
url='http://www.baidu.com'
content=urllib2.urlopen(url).read()
print(content)

