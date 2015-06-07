class Person:
    def __init__(self, name, sex, age):
        self.name = name
        self.sex = sex
        self.age = age

    def __del__(self):
        del self.name
        del self.sex
        del self.age

    def toString(self):
        return "name: " + str(self.name) + ", sex: " + str(self.sex) + ", age: " + str(self.age)

p1 = Person("xanarry", 'F', 21)
print(p1.toString())

class Student(Person):
    def __init__(self, no):
        self.no = no

    def __del__(self):
       
        