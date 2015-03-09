import urllib    
import urllib2  
import cookielib  
  
#初始化一个CookieJar来处理Cookie的信息#  
cookie = cookielib.CookieJar()  
  
#创建一个新的opener来使用我们的CookieJar#  
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
  
#打印cookie的值  
for item in cookie:    
    print 'Cookie：Name = '+item.name    
    print 'Cookie：Value = '+item.value  
  
      
#访问该链接#  
result = opener.open('http://218.7.49.35:7778/pls/wwwbks/xk.CourseView')  
  
#打印返回的内容#  
print result.read() 