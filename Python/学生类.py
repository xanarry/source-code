class student:
    def __init__(self, name, age, sex, stuno):
        self.name = name
        self.age = age
        self.sex = sex
        self.stuno = stuno

    def introduce(self):
        print("hello every one, my name is " + str(self.name) + " and I'am " + str(self.age) + " so glad to see U")
    
    def study(self):
        print(str(self.name) + " is studying")

stu1 = student("xanarry", 21, "boy", "2013023058")
stu1.introduce()
stu1.study()

stu1 = student("james", 17, "girl", "2013023011")
stu1.introduce()
stu1.study()
