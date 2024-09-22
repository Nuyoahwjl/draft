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


# 元组(元素类型可以不相同,元素不可改变)
tuple=(1,2.5,3+4j,"rr",5)
print(tuple) # 输出元组
print(tuple[0]) # 输出元组第一个元素
print(tuple[1:3]) # 输出第二个到第三个元素
print(tuple[2:]) # 输出从第三个开始的所有元素
print(tuple*2) # 输出元组两次
print(tuple+(6,7,8)) # 连接元组
tuple=() # 空元组
tuple=(50,) # 元组只包含一个元素时,需要在元素后面添加逗号


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
dict={} # 创建空字典
dict['one']="1-菜鸟教程"
dict[2]="2-菜鸟工具"
tinydict={'name':'runoob','code':1,'site':'www.runoob.com'}
print(dict['one']) # 输出键为'one'的值
print(dict[2]) # 输出键为2的值
print(tinydict) # 输出完整字典
print(tinydict.keys()) # 输出所有键
print(tinydict.values()) # 输出所有值
# 构造函数dict()直接从键值对元组列表中构建字典
# dict=dict([('Runoob',1),('Google',2),('Taobao',3)]) 
# dict1={x:x**2 for x in (2,4,6)} # 字典推导式
# dict2=dict(Runoob=1,Google=2,Taobao=3) # 关键字参数


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