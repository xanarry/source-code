def f(x):
    return x * 2

g = lambda x: x * 2

print(f(10)); print(g(10))


def make_increament(n):
    return lambda x: x + n

f = make_increament(10)
g = make_increament(100)

print(f(3)); print(g(3))

foo = [2, 18, 9, 22, 17, 24, 8, 12, 27]

#filter()函数的功能相当于过滤器。调用一个布尔函数bool_func来迭代遍历每个seq中的元素；返回一个使bool_seq返回值为true的元素的序列。
print(list(filter(lambda x: x % 3 == 0, foo)))

#map()函数处理一个列表里的所有元素，可以使用一个for循环来完成这个工作。但是Python内置的map函数可以帮我们的忙，它接受函数和列表作为参数，然后返回函数处理之后的列表：
print(list(map(lambda x: x * 10, foo)))

#reduce()函数对sequence中的item顺序迭代调用function，如果有starting_value，还可以作为初始值调用
from functools import reduce
print(reduce(lambda x, y: x + y, foo))


sentence = "It is raining cats and dogs"
lens = list(map(lambda x: len(x), sentence.split()))
print(lens)

'''
map(function, iterable, ...) 
Return an iterator that applies function to every item of iterable, yielding the results. If additional iterable arguments are passed, function must take that many arguments and is applied to the items from all iterables in parallel. With multiple iterables, the iterator stops when the shortest iterable is exhausted. For cases where the function inputs are already arranged into argument tuples, see

functools.reduce(function, iterable[, initializer]) 
Apply function of two arguments cumulatively to the items of sequence, from left to right, so as to reduce the sequence to a single value. For example, reduce(lambda x, y: x+y, [1, 2, 3, 4, 5]) calculates ((((1+2)+3)+4)+5). The left argument, x, is the accumulated value and the right argument, y, is the update value from the sequence. If the optional initializer is present, it is placed before the items of the sequence in the calculation, and serves as a default when the sequence is empty. If initializer is not given and sequence contains only one item, the first item is returned.

filter(function, iterable) 
Construct an iterator from those elements of iterable for which function returns true. iterable may be either a sequence, a container which supports iteration, or an iterator. If function is None, the identity function is assumed, that is, all elements of iterable that are false are removed.
Note that filter(function, iterable) is equivalent to the generator expression (item for item in iterable if function(item)) if function is not None and (item for item in iterable if item) if function is None.
'''




