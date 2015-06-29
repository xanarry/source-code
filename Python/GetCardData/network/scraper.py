import urllib.request
import re
import functools
import http.cookiejar
from network import conversion
from functools import reduce

urls = {
    "login" : "http://172.16.51.37/user_login.html", #登陆链接
    "jlb" : "http://172.16.51.37/personJLBQueryZC_personalJLBDetailQuery.html", #俱乐部地址
    "zc" :  "http://172.16.51.37/personQueryZC_personalDetailQuery.html", #早操地址
    "zzxx" : "http://172.16.51.37/attendanceZZXX_list.html", #自主学习地址
    "sttz" : "http://172.16.51.37/attendanceSTTZ_list.html" #身体拓展地址
}

class login:
    '''本类用于登陆网站, 并获取刷卡信息'''
    #请求头信息, 伪装成浏览器
    __headers = {
        "Connection" : "keep-alive",
        "Host" : "jecvay.com",
        "Referer" : "http://jecvay.com/category/smtech/python3-webbug",
        "User-Agent" : "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.152 Safari/537.36"
    }
    #关键词, 如果密码错误, 网页中会有则句话, 因此查找网页是否包含这句话来判断是否登陆成功
    wrong_passwold = "用户名或密码不正确"

    def __init__(self, account, password):
        self.account = account
        self.password = password
        self.post_data = {
            "loginName" : self.account, 
            "password" : self.password
        }

    def get_opener(self):
        '''登陆网站, 并返回可以持续访问链接的对象和用户姓名'''
        cookie =  http.cookiejar.CookieJar()
        opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie))
        encode_post_data = urllib.parse.urlencode(self.post_data).encode()
        home_page = ""
        try:
            result = opener.open(urls["login"], encode_post_data, 6)
            home_page = result.read().decode("utf8")
        except Exception as e:
            print("网络连通故障, 请稍后再试!, error detail:", e)
            return None

        if self.wrong_passwold in home_page:#如果以上关键词在网页中说明登陆失败
            return None
        else:
            convert = lambda x : conversion.ncr_to_python(x)#转换网页中姓名NCR码为中文
            pattern = re.compile("&#\d{5};")#提取姓名的NCR码
            m = pattern.findall(home_page)
            #保存姓名
            user_name = reduce(lambda x, y : str(x) + str(y), list(convert(x) for x in m))
            return (opener, user_name)

class scrap:
    def __init__(self, opener):
        self.opener = opener
        self.pattern_day = re.compile("\d{4}-\d\d-\d\d")#匹配xxxx-xx-xx格式的日期
        #匹配xx:xx:xx或者xx:xx:xx-xx:xx:xx或者xx:xx:xx-
        self.pattern_time = re.compile("\d\d:\d\d:\d\d\-\d\d:\d\d:\d\d|\d\d:\d\d:\d\d\-?")
        self.pattern_valid = re.compile("有效|无效")
        self.pattern_pagecount = re.compile("\d+页")#匹配页面数量

    def __getcontent(self, dest_url):
        '''根据传递过来的参数, 抓起刷卡数据, 并返回保存刷卡日期, 刷卡时间, 是否有效的三元组列表'''
        day_list, time_list, valid_list = [], [], []
        try:
            result = self.opener.open(dest_url).read().decode("utf8")#获取网页源码
            result = result[result.index("是否有效") : ]
            page_count = int(self.pattern_pagecount.search(result).group()[0])#获取页面数量
            cur_page = 1
            for x in range(1, page_count + 1):#循环多页查询
                day_list += self.pattern_day.findall(result)
                time_list += self.pattern_time.findall(result)
                valid_list += self.pattern_valid.findall(result)[1 : ]
                ##################################################给定链接的页面参数
                result = self.opener.open(dest_url + "?pageNum=" + str(cur_page + 1)).read().decode("utf8")
                result = result[result.index("是否有效") : ]
            return list(x for x in zip(day_list, time_list,valid_list))
        except Exception as e:
            print("该记录查询失败, 错误详情:", e)
            return None

    def get_zc(self):
        '''返回早操数据'''
        return self.__getcontent(urls["zc"])
        
    def get_jlb(self, ):
        '''返回俱乐部数据'''
        return self.__getcontent(urls["jlb"])

    def get_zzxx(self):
        '''返回自主学习数据'''
        return self.__getcontent(urls["zzxx"])

    def get_sttz(self):
        '''返回身体拓展数据'''
        return self.__getcontent(urls["sttz"])

    def get_all(self):
        '''依次返回数据以上所有'''
        zc = self.get_zc()
        jlb = self.get_jlb()
        sttz = self.get_sttz()
        zzxx = self.get_zzxx()

        if zc != None and jlb != None and sttz != None and zzxx != None:
            return {"zc" : zc, "jlb" : jlb, "zzxx" : zzxx, "sttz" : sttz}
        else:
            return None