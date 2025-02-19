import matplotlib.pyplot as plt
import numpy as np


# 在图中(0,0)到(6,250)之间画一条直线
xpoints = np.array([0, 6])
ypoints = np.array([0, 250])
plt.plot(xpoints, ypoints)
plt.plot(xpoints, ypoints, 'o')  # 'o'表示用点标记数据点
plt.show()

xpoints=np.array([1,3,6,8])
ypoints=np.array([3,8,1,10])
plt.plot(xpoints, ypoints)
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints,'o:r')
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20)  # ms表示点的大小
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r')  # mec表示点的边框颜色
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mfc = 'r')  # mfc表示点的填充颜色
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r', mfc = 'r')  # mec表示点的边框颜色，mfc表示点的填充颜色
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r', mfc = 'r', linestyle = 'dotted')  # linestyle表示线的样式
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r', mfc = 'r', linestyle = 'dashed')  # linestyle表示线的样式
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r', mfc = 'r', linestyle = 'dashdot')  # linestyle表示线的样式
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r', mfc = 'r', linestyle = 'solid',color='#4CAF50',linewidth='15')  # linestyle表示线的样式
plt.show()

ypoints = np.array([3, 8, 1, 10])
plt.plot(ypoints, marker = 'o', ms = 20, mec = 'r', mfc = 'r', linestyle = 'None')  # linestyle表示线的样式
plt.show()

y1=np.array([3,8,1,10])
y2=np.array([6,2,7,11])
plt.plot(y1,linestyle='dotted',color='r',linewidth='5',label='line1')
plt.plot(y2,linestyle='dashed',color='g',linewidth='3',label='line2')
plt.show()

x1=np.array([0,1,2,3])
y1=np.array([3,8,1,10])
x2=np.array([3,4,5,6])
y2=np.array([6,2,7,11])
plt.plot(x1,y1,x2,y2)
plt.show()

# linestyle(ls)的值可以是以下值之一：
# 'solid' - 实线            ls='-'
# 'dotted' - 点线           ls=':'
# 'dashed' - 虚线           ls='--'
# 'dashdot' - 点划线        ls='-.'
# 'None' - 无线条           ls=''

# marker的值可以是以下值之一：
# 'o' - 圆圈
# '*' - 星形
# '.' - 点
# ',' - 像素
# 'x' - X
# 'X' - X（大写）
# '+' - 加号
# 'P' - 五角星
# 'p' - 五角星（小写）
# 's' - 正方形
# 'D' - 菱形
# 'd' - 菱形（小写）
# 'H' - 六边形
# 'h' - 六边形（小写）
# 'v' - 倒三角
# '^' - 三角
# '<' - 左三角
# '>' - 右三角
# '|' - 垂直线
# '_' - 水平线

# color的值可以是以下值之一：
# 'r' - 红色
# 'g' - 绿色
# 'b' - 蓝色
# 'c' - 青色
# 'm' - 品红
# 'y' - 黄色
# 'k' - 黑色
# 'w' - 白色
# 也可以是十六进制值（如'#0000ff'）或任何合法的颜色名称。

# ms的值是一个数字，表示点的大小。
# mec的值是一个颜色字符串，表示点的边框的颜色。
# mfc的值是一个颜色字符串，表示点的填充颜色。
# linewidth的值是一个数字，表示线的宽度。




# 图例
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
matplotlib.rcParams['font.family'] = 'KaiTi'  # 设置中文字体

font1={'family':'KaiTi','color':'blue','size':20}
font2={'family':'Microsoft YaHei','color':'darkred','size':15}
x=np.array([80,85,90,95,100,105,110,115,120,125])
y=np.array([240,250,260,270,280,290,300,310,320,330])
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')
plt.title('图一',fontdict=font1,loc='center') # loc表示标题的位置
plt.xlabel('平均脉搏',fontdict=font2)
plt.ylabel('卡路里消耗量',fontdict=font2)
plt.grid(axis='x',color='orange',linestyle='--',linewidth='1.0') # 显示网格
plt.show()




# 多图(1行2列)
import matplotlib.pyplot as plt
import numpy as np
x=np.array([0,1,2,3])
y=np.array([3,8,1,10])
plt.subplot(1,2,1)  # 1行2列第1个
plt.plot(x,y,marker='*')

x=np.array([0,1,2,3])
y=np.array([10,20,30,40])
plt.subplot(1,2,2)  # 1行2列第2个
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')

plt.show()




# 多图(2行3列)
import matplotlib.pyplot as plt
import numpy as np
x=np.array([0,1,2,3])
y=np.array([3,8,1,10])
plt.subplot(2,3,1)  # 2行3列第1个
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')
plt.title('图一')
plt.grid(axis='both',color='blue',linestyle='--',linewidth='1.0') # 显示网格

x=np.array([0,1,2,3])
y=np.array([10,20,30,40])
plt.subplot(2,3,2)  # 2行3列第2个
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')
plt.title('图二')

x=np.array([0,1,2,3])
y=np.array([3,8,1,10])
plt.subplot(2,3,3)  # 2行3列第3个
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')
plt.title('图三')

x=np.array([0,1,2,3])
y=np.array([10,20,30,40])
plt.subplot(2,3,4)  # 2行3列第4个
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')
plt.title('图四')

x=np.array([0,1,2,3])
y=np.array([3,8,1,10])
plt.subplot(2,3,5)  # 2行3列第5个
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')
plt.title('图五')

x=np.array([0,1,2,3])
y=np.array([10,20,30,40])
plt.subplot(2,3,6)  # 2行3列第6个
plt.plot(x,y,'o',color='r',mec='g',mfc='g',ls='-',lw='2')
plt.title('图六')

plt.suptitle('多图显示')
plt.show()




# 散点图
import matplotlib.pyplot as plt
import numpy as np

x=np.array([5,7,8,7,2,17,2,9,4,11,12,9,6])
y=np.array([99,86,87,88,100,86,103,87,94,78,77,85,86])
plt.scatter(x,y,color='hotpink')
x=np.array([2,2,8,1,15,8,12,9,7,13,6,11,7])
y=np.array([100,105,84,105,90,99,90,95,94,100,79,112,91])
plt.scatter(x,y,color='#88c999')
x=np.array([1,3,4,2,8,11,6,12])
y=np.array([38,78,57,68,45,69,108,72])
colors=np.array(['red','green','blue','yellow','pink','black','orange','purple'])
plt.scatter(x,y,color=colors)

plt.show()




# 颜色图
import matplotlib.pyplot as plt
import numpy as np
x=np.array([5,7,8,7,2,17,2,9,4,11,12,9,6])
y=np.array([99,86,87,88,100,86,103,87,94,78,77,85,86])
# colors=np.array([0,10,20,30,40,45,50,55,60,70,80,90,100])
colors=y
sizes=np.array([20,50,100,200,500,1000,60,90,10,300,600,800,75])
plt.scatter(x,y,c=colors,cmap='plasma',s=sizes,alpha=0.8)  # cmap表示颜色条，s表示点的大小，alpha表示透明度
plt.colorbar() # 显示颜色条
plt.show()
# cmap的值可以是以下值之一：
# 'viridis' - 绿色和蓝色（默认）
# 'plasma' - 红色和黄色
# 'inferno' - 黑色和红色
# 'magma' - 绿色和紫色
# 'cividis' - 黄色和黑色




# 组合颜色、大小和透明度
import matplotlib.pyplot as plt
import numpy as np
x=np.random.randint(100,size=(100))
y=np.random.randint(100,size=(100))
colors=np.random.randint(100,size=(100))
sizes=10*np.random.randint(100,size=(100))
plt.scatter(x,y,c=colors,cmap='nipy_spectral',s=sizes,alpha=0.7)
plt.colorbar()
plt.show()