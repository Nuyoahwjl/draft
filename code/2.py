import matplotlib.pyplot as plt
import numpy as np
import matplotlib.cm as cm  # 导入颜色映射库

# 设置中文字体（Windows 下使用微软雅黑，Linux/Mac 可能需要调整）
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 微软雅黑
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 数据
years = [2020, 2021, 2022, 2023, 2024]
cancer_cases = [154310, 172731, 166614, 181129, 174972]

# 创建颜色渐变（从蓝色到深蓝色）
colors = cm.Blues(np.linspace(0.3, 1, len(cancer_cases)))  # 生成渐变色

# 创建横向柱状图
plt.figure(figsize=(10, 6))  # 设置图表大小
bars = plt.barh(years, cancer_cases, color=colors)  # 应用渐变色

# 添加标题和标签
plt.title('2020-2024年中国税收收入', fontsize=14, pad=15)
plt.xlabel('税收收入（亿元）', fontsize=12)  # x轴改为税收收入
plt.ylabel('年份', fontsize=12)  # y轴改为年份

# 添加数据标签（在柱右侧显示数值）
for bar in bars:
    width = bar.get_width()  # 使用width替代height
    plt.text(x=width + 1000,  # 明确指定x参数
             y=bar.get_y() + bar.get_height()/2.,  # 明确指定y参数
             s=int(width),  # 明确指定文本内容s
             ha='left', va='center')  # 对齐参数

# 设置 X 轴范围（根据数据调整）
plt.xlim(0, 200000)

# 添加图例
plt.legend(['税收收入'], loc='lower right')  # 图例位置

# 显示网格（改为x轴方向的虚线）
plt.grid(axis='x', linestyle='--', alpha=0.7)  # 改为axis='x'

# 调整布局
plt.tight_layout()

# 显示图表
plt.show()
