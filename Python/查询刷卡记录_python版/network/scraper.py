import urllib.request
import re
import functools
import http.cookiejar
from network import conversion
from functools import reduce

urls = {
    "login" : "http://172.16.51.37/user_login.html",#登陆连接
    "jlb" : "http://172.16.51.37/personJLBQueryZC_personalJLBDetailQuery.html", #俱乐部记录链接
    "zc" :  "http://172.16.51.37/personQueryZC_personalDetailQuery.html", #早操记录链接
    "zzxx" : "http://172.16.51.37/attendanceZZXX_list.html", #自主学习记录链接
    "sttz" : "http://172.16.51.37/attendanceSTTZ_list.html" #身体素质拓展链接
}

class login:
    __headers = { #设置请求头信息, 伪装成浏览器
        "Connection" : "keep-alive",
        "Host" : "jecvay.com",
        "Referer" : "http://jecvay.com/category/smtech/python3-webbug",
        "User-Agent" : "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.152 Safari/537.36"
    }
    wrong_passwold = "用户名或密码不正确" #用于检查标志文本, 因为如果密码错误, 网页中有这段话

    def __init__(self, account, password):
        self.account = account
        self.password = password
		#封装post发送的数据
        self.post_data = {
            "loginName" : self.account,
            "password" : self.password
        }

    def get_opener(self):
        cookie =  http.cookiejar.CookieJar()#保存cookie,用来连续访问登陆后的网站
        opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie))#构建opener打开请求
        encode_post_data = urllib.parse.urlencode(self.post_data).encode()#对post数据编码 
        home_page = ""
        try:#登陆网站
            result = opener.open(urls["login"], encode_post_data, 6)
            home_page = result.read().decode("utf8")
        except Exception as e:
            print("网络连通故障, 请稍后再试!, error detail:", e)
            return None

        if self.wrong_passwold in home_page:
            print(self.wrong_passwold)
            return None
        else:
            convert = lambda x : conversion.ncr_to_python(x)
            pattern = re.compile("&#\d{5};")
            m = pattern.findall(home_page)
            user_name = reduce(lambda x, y : str(x) + str(y), list(convert(x) for x in m))
            return (opener, user_name)#返回opener用于继续访问其他页面, 和用户姓名

class scrap:
    def __init__(self, opener):
        self.opener = opener
        self.pattern_day = re.compile("\d{4}-\d\d-\d\d")#匹配xxxx-xx-xx格式的日期
        self.pattern_time = re.compile("\d\d:\d\d:\d\d\-\d\d:\d\d:\d\d|\d\d:\d\d:\d\d\-?")#匹配xx:xx:xx或者xx:xx:xx-xx:xx:xx或者xx:xx:xx-
        self.pattern_valid = re.compile("有效|无效")
        self.pattern_pagecount = re.compile("\d+页")#匹配页面数量

    def __getcontent(self, dest_url):
        day_list, time_list, valid_list = [], [], []
        try:
            result = self.opener.open(dest_url).read().decode("utf8")
            result = result[result.index("是否有效") : ]
            page_count = int(self.pattern_pagecount.search(result).group()[0])
            cur_page = 1
            for x in range(1, page_count + 1):
                day_list += self.pattern_day.findall(result)
                time_list += self.pattern_time.findall(result)
                valid_list += self.pattern_valid.findall(result)[1 : ]
                result = self.opener.open(dest_url + "?pageNum=" + str(cur_page + 1)).read().decode("utf8")
                result = result[result.index("是否有效") : ]
            return list(x for x in zip(day_list, time_list,valid_list))
        except Exception as e:
            print("该记录查询失败, 错误详情:", e)
            return None
        
    def get_zc(self):
        return self.__getcontent(urls["zc"])
        
    def get_jlb(self, ):
        return self.__getcontent(urls["jlb"])

    def get_zzxx(self):
        return self.__getcontent(urls["zzxx"])

    def get_sttz(self):
        return self.__getcontent(urls["sttz"])

    def get_all(self):
        return {
            "zc" : get_zc(),
            "jlb" : get_jlb(),
            "zzxx" : get_zzxx(),
            "sttz" : get_sttz()
        }
