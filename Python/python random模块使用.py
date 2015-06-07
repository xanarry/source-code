import random
words = ["I", "will", "tell", "you", "how", "to", "use", "random", "module", "in", "pyton"]
a = random.getrandbits(32)#返回python 1到32位中随机某一位的long int
a = random.randrange(100)#随机返回一个range(start, stop, step)中的一个数
a = random.randrange(1, 100, 2)#这里就返回1,3,5...99所有奇数中的任意一个
a = random.randint(1, 100)#生成1到100之间整数,两端都取等
a = random.choice(words)#从word中随机返回一个值
a = random.random()#返回[0.0, 1.0)之间的浮点数
a = random.uniform(10, 100)#返回[a, b]之间的浮点数,如果a < b, 如果a==b,返回a
a = random.sample(words, 4)#返回原始序列中随机抽取n个元素构成新的序列返回
random.shuffle(a)#对序列重新洗牌乱序