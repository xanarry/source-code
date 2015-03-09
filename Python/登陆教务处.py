import urllib    
import urllib2  
import cookielib  
  
cookie = cookielib.CookieJar()    
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cookie))  
  
#需要POST的数据#  
postdata=urllib.urlencode({    
    'stuid':'2013023058',    
    'pwd':'xy58316992'    
})  
  
#自定义一个请求#  
req = urllib2.Request(    
    url = 'http://218.7.49.35:7778/pls/wwwbks/bks_login2.login',    
    data = postdata  
)  
  
#访问该链接#  
result = opener.open(req)  
  
#打印返回的内容#  
print result.read()