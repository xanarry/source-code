class student:
    def __init__(self, name, final, average, isgan, isw, pac):
        self.name = name
        self.final = final
        self.average = average
        self.isgan = isgan
        self.isw = isw
        self.pac = pac
        self.scl = self.cal_scl()

    def cal_scl(self):
        sum = 0
        if self.final > 80 and self.pac >= 1:
            sum += 8000
        if self.final > 85 and self.average > 80:
            sum += 4000
        if self.final > 90:
            sum += 2000
        if self.final > 85 and self.isw == 'Y':
            sum += 1000
        if self.average > 80 and self.isgan == 'Y':
            sum += 850
        return sum

n = int(input())
students = []
for i in range(n):
    a = input().strip().split()
    students.append(student(a[0], int(a[1]), int(a[2]), a[3], a[4], int(a[5])))

maxs = -1
total = 0
name = None
for x in reversed(students):
    if x.scl > maxs:
        maxs = x.scl
        name = x.name
    total += x.scl
print(name)
print(maxs)
print(total)