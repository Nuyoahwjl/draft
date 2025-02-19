import keyword
print("Hello,World!")
print(keyword.kwlist) # 输出关键字列表


# 同一行显示多条语句
import sys; x = 'runoob'; sys.stdout.write(x + '\n') # 输出到屏幕


# 多个变量赋值
a,b,c,d,e=20,5.5,True,4+3j,complex(1,4)
# 查询变量所指对象类型
print(type(a),type(b),type(c),type(d),type(e))
print(a,b,c,d,e) # 输出变量值
print(isinstance(a,int)) # 判断变量类型



# 删除对象引用
del a
# print(a) # 报错


# 数值运算
print(2+2) # 加法
print(2-2) # 减法
print(2*2) # 乘法
print(2/2) # 除法
print(2//2) # 整除
print(2%2) # 取余
print(2**2) # 幂


# 字符串(元素类型相同,元素不可改变)
str='Runoob'
print(str) # 输出字符串
print(str[0:-1]) # 输出第一个到倒数第二个的所有字符
print(str[0]) # 输出字符串第一个字符
print(str[2:5]) # 输出从第三个开始到第五个的字符
print(str[2:]) # 输出从第三个开始后的所有字符
print(str[1:5:2]) # 输出从第二个开始到第五个且每隔两个的字符
print(str*2) # 输出字符串两次
print(str+'你好') # 连接字符串


# 列表(元素类型可以不相同,元素可以改变)
list=[1,2.5,3+4j,"rr",5]
print(list) # 输出列表
print(list[0]) # 输出列表第一个元素
print(list[1:3]) # 输出第二个到第三个元素
print(list[2:]) # 输出从第三个开始的所有元素
print(list*2) # 输出列表两次
print(list+[6,7,8]) # 连接列表
list.append('Baidu') # 添加元素
print(list)
del list[2] # 删除元素
print(list)
list.remove('rr') # 删除元素
print(list)
print(len([1, 2, 3]))
print([1, 2, 3]+[4, 5, 6])
print(['Hi!']*4)
print(3 in [1, 2, 3])
for x in [1, 2, 3]: print(x, end=" ")
a = ['a', 'b', 'c']
n = [1, 2, 3]
x = [a, n]
print(x)
print(x[0])
print(x[0][1])
import operator
a = [1, 2]
b = [2, 3]
c = [2, 3]
print("operator.eq(a,b): ", operator.eq(a,b))
print("operator.eq(c,b): ", operator.eq(c,b))
def reverseWords(input):
    inputWords=input.split(" ") # 通过空格将字符串分隔为列表
    inputWords=inputWords[-1::-1] 
    # 第一个参数为-1：表示从最后一个元素开始
    # 第二个参数为空：表示移动到列表末尾
    # 第三个参数为-1：表示逆向
    output=' '.join(inputWords)
    return output
if __name__=="__main__":
    input='I like runoob'
    rw=reverseWords(input)
    print(rw)
# 列表函数&方法
# len(list) 列表元素个数
# max(list) 返回列表元素最大值
# min(list) 返回列表元素最小值
# list(seq) 将元组转换为列表
# list.append(obj) 在列表末尾添加新的对象
# list.count(obj) 统计某个元素在列表中出现的次数
# list.extend(seq) 在列表末尾一次性追加另一个序列中的多个值(用新列表扩展原来的列表)
# list.index(obj) 从列表中找出某个值第一个匹配项的索引位置
# list.insert(index, obj) 将对象插入列表
# list.pop(obj=list[-1]) 移除列表中的一个元素(默认最后一个元素),并且返回该元素的值
# list.remove(obj) 移除列表中某个值的第一个匹配项
# list.reverse() 反向列表中元素
# list.sort([func]) 对原列表进行排序
# list.clear() 清空列表
# list.copy() 复制列表


# 元组(元素类型可以不相同,元素不可改变)
tuple=(1,2.5,3+4j,"rr",5)
print(tuple) # 输出元组
print(tuple[0]) # 输出元组第一个元素
print(tuple[1:3]) # 输出第二个到第三个元素
print(tuple[2:]) # 输出从第三个开始的所有元素
print(tuple*2) # 输出元组两次
print(tuple+(6,7,8)) # 连接元组
tuple=() # 空元组
tuple=(50,) # 元组只包含一个元素时,需要在元素后面添加逗号，否则括号会被当作运算符使用


# 集合(无序、可变、不重复)
student={'Tom','Jim','Mary','Tom','Jack','Rose'}
print(student) # 输出集合,重复的元素被自动去掉
if 'Rose' in student:
    print('Rose 在集合中')
else:
    print('Rose 不在集合中')
#可用set函数创建集合
a=set('abracadabra')
b=set('alacazam')
print(a) # 输出集合a
print(a-b) # a和b的差集
print(a|b) # a和b的并集
print(a&b) # a和b的交集
print(a^b) # a和b中不同时存在的元素
fruits = set(['apple', 'banana', 'orange', 'apple'])
print(fruits) # 输出集合，重复的元素被自动去掉


# 字典(元素类型可以不相同,元素可以改变,无序,通过键来访问)
dic={} # 创建空字典
dic['one']="1-菜鸟教程"
dic[2]="2-菜鸟工具"
tinydict={'name':'runoob','code':1,'site':'www.runoob.com'}
print(dic['one']) # 输出键为'one'的值
print(dic[2]) # 输出键为2的值
print(tinydict) # 输出完整字典
print(tinydict.keys()) # 输出所有键
print(tinydict.values()) # 输出所有值
# 构造函数dict()直接从键值对元组列表中构建字典
dict_=dict([('Runoob',1),('Google',2),('Taobao',3)])
dict1={x:x**2 for x in (2,4,6)} # 字典推导式
dict2=dict(Runoob=1,Google=2,Taobao=3) # 关键字参数


# bytes(不可变类型,0-255之间的整数)
a=bytes(3)
print(a) # 输出b'\x00\x00\x00'
b=bytes([1,2,3])
print(b) # 输出b'\x01\x02\x03'
c=bytes('runoob','utf-8')
print(c) # 输出b'runoob'
d=b"hello"
e=x[1:3]
f=e+b"world"
print(f) # 输出b'elloworld'
x=b"hello"
if x[0]==ord('h'): # ord()函数返回对应的 ASCII 数值
    print("x[0]是h")


for i in range(10):
    print(i) #print默认输出换行符
for i in range(10):
    print(i,end=",")


# 推导式
# 列表推导式
names = ['Bob','Tom','alice','Jerry','Wendy','Smith']
new_names = [name.upper() for name in names if len(name)>3]
print(new_names)
multiples = [i for i in range(30) if i % 3 == 0]
print(multiples)
# 字典推导式
listdemo = ['Google','Runoob', 'Taobao']
newdict = {key:len(key) for key in listdemo}
print(newdict)
dic = {x: x**2 for x in (2, 4, 6)}
print(dic)
# 集合推导式
setnew = {i**2 for i in (1,2,3)}
print(setnew)
a = {x for x in 'abracadabra' if x not in 'abc'}
print(a)
# 元组推导式,返回的结果是一个生成器对象
tuple_ = (x for x in range(10))
print(tuple_) # 输出生成器对象
print(tuple(tuple_)) # 输出元组


# 迭代器,字符串,列表或元组对象都可用于创建迭代器
list=[1,2,3,4]
it=iter(list) # 创建迭代器对象
print(next(it)) # 输出迭代器的下一个元素
print(next(it))
for x in it:
    print(x,end=" ")
# 把一个类作为一个迭代器使用需要在类中实现
# 两个方法 __iter__() 与 __next__()
class MyNumbers:
  def __iter__(self):
    self.a = 1
    return self
  def __next__(self):
    x = self.a
    self.a += 1
    return x
myclass = MyNumbers()
myiter = iter(myclass)
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))


# 生成器
# 使用了 yield 的函数被称为生成器（generator）
# 当在生成器函数中使用 yield 语句时，函数的执行将会暂停，并将 yield 后面的表达式作为当前迭代的值返回。
# 然后，每次调用生成器的 next() 方法或使用 for 循环进行迭代时，函数会从上次暂停的地方继续执行，直到再次遇到 yield 语句
# 生成器是一个返回迭代器的函数,只能用于迭代操作
def fibonacci(n): # 生成器函数
    a,b,counter=0,1,0
    while True:
        if counter>n:
            return
        yield a
        a,b=b,a+b
        counter+=1
f=fibonacci(10) # f是一个迭代器,由生成器返回生成
# for x in f:
#     print(x,end=" ")
while True:
    try:
        print (next(f), end=" ")
    except StopIteration:
        sys.exit()

# python 函数的参数传递：
# a=10,la=[1,2,3,4]
# 不可变类型：类似 C++ 的值传递，如整数、字符串、元组。
# 如 fun(a)，传递的只是 a 的值，没有影响 a 对象本身。
# 如果在 fun(a) 内部修改 a 的值，则是新生成一个 a 的对象。
# 可变类型：类似 C++ 的引用传递，如 列表，字典。
# 如 fun(la)，则是将 la 真正的传过去，修改后 fun 外部的 la 也会受影响
def change(a):
    print(id(a))   # 指向的是同一个对象
    a=10
    print(id(a))   # 一个新对象
a=1
print(id(a))
change(a)

# 加了星号 * 的参数会以元组(tuple)的形式导入
def printinfo( arg1, *vartuple ):
   "打印任何传入的参数"
   print ("输出: ")
   print (arg1)
   print (vartuple)
printinfo( 70, 60, 50 )
# 加了两个星号 ** 的参数会以字典的形式导入
def printinfo( arg1, **vardict ):
   "打印任何传入的参数"
   print ("输出: ")
   print (arg1)
   print (vardict)
printinfo(1, a=2,b=3)

a=[str(round(355/113, i)) for i in range(1, 6)]
print(a)
b=[round(355/113, i) for i in range(1, 6)]
print(b)



matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
]
print([[row[i] for row in matrix] for i in range(4)])
transposed = []
for i in range(4):
    transposed.append([row[i] for row in matrix])
print(transposed)


knights = {'gallahad': 'the pure', 'robin': 'the brave'}
for k, v in knights.items():
    print(k, v)

for i, v in enumerate(['tic', 'tac', 'toe']):
    print(i, v,end=" ")

questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print('What is your {0}?  It is {1}.'.format(q, a))

for i in reversed(range(1, 10, 2)):
    print(i)

basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
for f in sorted(set(basket)):
    print(f)



import sys
print('命令行参数如下:')
for i in sys.argv:
   print(i)
print('\n\nPython 路径为：', sys.path, '\n')
# 1、import sys 引入 python 标准库中的 sys.py 模块；这是引入某一模块的方法。
# 2、sys.argv 是一个包含命令行参数的列表。
# 3、sys.path 包含了一个 Python 解释器自动查找所需模块的路径的列表。

# import module1[, module2[,... moduleN]
# from modname import name1[, name2[, ... nameN]]
dir(sys)
print(str(1/7))
print(repr(1/7))
print('{}网址： "{}!"'.format('菜鸟教程', 'www.runoob.com'))
print('{0} 和 {1}'.format('Google', 'Runoob'))
print('{name}网址： {site}'.format(name='菜鸟教程', site='www.runoob.com'))
print('站点列表 {0}, {1}, 和 {other}。'.format('Google', 'Runoob', other='Taobao'))
# !a (使用 ascii()), !s (使用 str()) 和 !r (使用 repr()) 可以用于在格式化某个值之前对其进行转化:
import math
print('常量 PI 的值近似为： {!r}。'.format(math.pi))
print('常量 PI 的值近似为： {!a}。'.format(math.pi))
print('常量 PI 的值近似为： {!s}。'.format(math.pi))
# 可选项 ':' 和格式标识符可以跟着字段名。 这就允许对值进行更好的格式化
print('常量 PI 的值近似为 {0:.3f}。'.format(math.pi))

table = {'Google': 1, 'Runoob': 2, 'Taobao': 3}
for name, number in table.items():
    print('{0:10} ==> {1:10d}'.format(name, number))
for x in table:
    print(x, table[x])  



f = open("foo.txt", "w")
f.write( "Python 是一个非常好的语言。\n是的,的确非常好!!\n" )
f.close()

f = open("foo.txt", "r")
str = f.read()
print(str)
f.close()


f = open("foo.txt", "r")
str = f.readline()
print(str,end="")
str = f.readline()
print(str)
f.close()

f = open("foo.txt", "r")
str = f.readlines()
print(str)
f.close()

f = open("foo.txt", "r")
for line in f:
    print(line, end='')
f.close()

f = open("foo1.txt", "w")
value = ['www.runoob.com', 14]
print(value)
s = str(value)
f.write(s)
f.close()

# 如果要改变文件指针当前的位置, 可以使用 f.seek(offset, from_what) 函数
# offset 表示相对于 whence 参数的偏移量，from_what 的值, 如果是 0 表示开头, 如果是 1 表示当前位置, 2 表示文件的结尾
# seek(x,0) ： 从起始位置即文件首行首字符开始移动 x 个字符
# seek(x,1) ： 表示从当前位置往后移动x个字符
# seek(-x,2)：表示从文件的结尾往前移动x个字符
# from_what 值为默认为0，即文件开头
f = open('foo2.txt', 'wb+')
f.write(b'0123456789abcdef')
f.seek(5)     # 移动到文件的第六个字节
print(f.read(1))
f.seek(-3, 2) # 移动到文件的倒数第三字节
print(f.read(1))



 
#类定义
class people:
    #定义基本属性
    name = ''
    age = 0
    #定义私有属性,私有属性在类外部无法直接进行访问
    __weight = 0
    #定义构造方法
    def __init__(self,n,a,w):
        self.name = n
        self.age = a
        self.__weight = w
    def speak(self):
        print("%s 说: 我 %d 岁。" %(self.name,self.age))
# 实例化类
p = people('runoob',10,30)
p.speak()
#单继承示例
class student(people):
    grade=0
    def __init__(self,n,a,w,g):
        #调用父类的构函
        people.__init__(self,n,a,w)
        self.grade = g
    #覆写父类的方法
    def speak(self):
        print("%s 说: 我 %d 岁了，我在读 %d 年级"%(self.name,self.age,self.grade))
s = student('ken',10,60,3)
s.speak()




#类定义
class people:
    #定义基本属性
    name = ''
    age = 0
    #定义私有属性,私有属性在类外部无法直接进行访问
    __weight = 0
    #定义构造方法
    def __init__(self,n,a,w):
        self.name = n
        self.age = a
        self.__weight = w
    def speak(self):
        print("%s 说: 我 %d 岁。" %(self.name,self.age))
#单继承示例
class student(people):
    grade = ''
    def __init__(self,n,a,w,g):
        #调用父类的构函
        people.__init__(self,n,a,w)
        self.grade = g
    #覆写父类的方法
    def speak(self):
        print("%s 说: 我 %d 岁了，我在读 %d 年级"%(self.name,self.age,self.grade))
#另一个类，多继承之前的准备
class speaker():
    topic = ''
    name = ''
    def __init__(self,n,t):
        self.name = n
        self.topic = t
    def speak(self):
        print("我叫 %s,我是一个演说家,我演讲的主题是 %s"%(self.name,self.topic))
#多继承
class sample(speaker,student):
    a =''
    def __init__(self,n,a,w,g,t):
        student.__init__(self,n,a,w,g)
        speaker.__init__(self,n,t)
 
test = sample("Tim",25,80,4,"Python")
test.speak()   #方法名同，默认调用的是在括号中参数位置排前父类的方法




# 方法重写
class Parent:        # 定义父类
   def myMethod(self):
      print ('调用父类方法')
 
class Child(Parent): # 定义子类
   def myMethod(self):
      print ('调用子类方法')
 
c = Child()          # 子类实例
c.myMethod()         # 子类调用重写方法
super(Child,c).myMethod() #用子类对象调用父类已被覆盖的方法



# 类的私有属性
class JustCounter:
    __secretCount = 0  # 私有变量
    publicCount = 0    # 公开变量

    def count(self):
        self.__secretCount += 1
        self.publicCount += 1
        print (self.__secretCount)

counter = JustCounter()
counter.count()
counter.count()
print (counter.publicCount)
print (counter.__secretCount)  # 报错，实例不能访问私有变量

# 类的私有方法
class Site:
    def __init__(self, name, url):
        self.name = name       # public
        self.__url = url   # private
 
    def who(self):
        print('name  : ', self.name)
        print('url : ', self.__url)
 
    def __foo(self):          # 私有方法
        print('这是私有方法')
 
    def foo(self):            # 公共方法
        print('这是公共方法')
        self.__foo()

x = Site('菜鸟教程', 'www.runoob.com')
x.who()        # 正常输出
x.foo()        # 正常输出
x.__foo()      # 报错




# 运算符重载
class Vector:
   def __init__(self, a, b):
      self.a = a
      self.b = b
 
   def __str__(self):
      return 'Vector (%d, %d)' % (self.a, self.b)
   
   def __add__(self,other):
      return Vector(self.a + other.a, self.b + other.b)
 
v1 = Vector(2,10)
v2 = Vector(5,-2)
print (v1 + v2)



from pyecharts.charts import Bar

# 准备数据
x_data = ['一月', '二月', '三月', '四月', '五月']
y_data = [10, 20, 15, 25, 30]

# 创建柱状图
bar_chart = Bar()
bar_chart.add_xaxis(x_data)
bar_chart.add_yaxis("销售额", y_data)

# 也可以传入路径参数，如 bar_chart.render("bar_chart.html")
bar_chart.render()