class person:
    """docstring for person"""

    def __init__(self, name, birth, sex):
        self.name = name
        self.birth = birth
        self.sex = sex

    def speack(self, lang):
        print(lang)

    def output(self):
        print(self.name)
        print(self.birth)
        print(self.sex)

        
class engeer(person):
    """docstring for engeer"""
    def __init__(self, name, birth, sex, wage, orientation):
        person.__init__(person, name, birth, sex)
        self.wage = wage
        self.orientation = orientation

    def output(self):
        person.output(person)
        print(self.wage)
        print(self.orientation)
        
p = person("xanarry", "1994", "boy")
p.output()
print("------------------")
e = engeer("xiongyang", "1993", "F", 9000, "algorithm")
e.output()
        