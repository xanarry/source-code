nums = "0123456789"
optrs = "+-*/="
print("sdf sdf sdfe " + dest)
def isoperator(expression, index):
    if nums.find(expression[index - 1]) != -1 and optrs.find(expression[index]) != -1:
        return True
    return False

def gen_list(expression):
    units = []
    start = 0
    for i in range(len(expression)):
        if (isoperator(expression, i)):
            units.append(float(expression[start:i]))
            units.append(expression[i])
            start = i + 1
    return units

def calculate(expression, isFirst = True):
    i = 0
    while i < len(expression) - 3:
        a = expression[i]
        b = expression[i + 2]
        optr = expression[i + 1]
        tresult = None
        if optr == "*":
            tresult = a * b
        elif optr == "/":
            tresult = a / b
        elif not isFirst and optr == "+":
            tresult = a + b
        elif not isFirst and optr == "-":
            tresult = a - b

        if tresult != None:
            expression[i] = tresult
            del(expression[i + 1 : i + 3])
        else:
            i += 2
        
    if isFirst:
        return calculate(expression, False)
    else:
        return expression[0]

expression = input('input a expression:')
expression = gen_list(expression if expression[len(expression) - 1] == "=" else expression + "=")
print(calculate(expression))