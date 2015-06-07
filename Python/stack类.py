class stack():
    """a module to impliment data structrue stack"""
    index = 0
    def __init__(self):
        self.vessel = []

    def push(self, a):
        self.vessel.append(a)

    def pop(self):
        if not self.is_empty():
            self.vessel.pop()

    def top(self):
        if not self.is_empty():
            return self.vessel[-1]

    def size(self):
        return len(self.vessel)

    def is_empty(self):
        return True if len(self.vessel) == 0 else False

    def __iter__(self):
        self.index = self.size()
        return self

    def __next__(self):
        if self.index == 0:
            raise StopIteration
        self.index = self.index - 1
        return self.vessel[self.index]

stk = stack()
stk.push(1)
stk.push(3)
stk.push(5)
stk.push(7)
stk.push(9)
stk.push(13)
print(list(stk))
stk.pop()
print(list(stk))
print(stk.is_empty())
print(stk.top())
stk.pop()
print(stk.is_empty())
print(list(stk))
stk.pop()
stk.pop()
print(stk.is_empty())
print(list(stk))
print(stk.size())
        