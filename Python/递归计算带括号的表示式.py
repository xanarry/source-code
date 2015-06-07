nums = "0123456789"
optrs = "+-*/="

def isoperator(expression, index):
    if nums.find(expression[index - 1]) != -1 and optrs.find(expression[index]) != -1:
        return True
    return False

def gen_list(expression):
    units = []
    start = 0
    expression = (expression if expression[len(expression) - 1] == "=" else expression + "=")
    for i in range(len(expression)):
        if (isoperator(expression, i)):
            units.append(float(expression[start:i]))
            units.append(expression[i])
            start = i + 1
    return units

def base_calculate(expression, isFirst = True):
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
        return base_calculate(expression, False)
    else:
        return expression[0]

def calculate(expression):
    if expression.find("(") == -1:
        return base_calculate(gen_list(expression))

    parathesis = []
    for i in range(len(expression)):
        if expression[i] == '(':
            parathesis.append(i)
        elif expression[i] == ')':
            if len(parathesis) != 0:
                subexp = expression[parathesis[-1] : i + 1][1 : -1]
                if subexp.find("(") == -1:
                    result = base_calculate(gen_list(subexp))
                    pre = expression[0 : parathesis[-1]]
                    post = expression[i + 1 : ]
                    expression = pre + str(result) + post
                    return calculate(expression)
                parathesis.pop()
while True:
    expression = input('input a expression:')
    print(calculate(expression))