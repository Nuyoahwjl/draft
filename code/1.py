import matplotlib.pyplot as plt
import numpy as np

# 设置中文字体（Windows 下使用微软雅黑，Linux/Mac 可能需要调整）
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # 微软雅黑
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

# 数据（仅 2020-2024 年）
years = ['2020年1-10月', '2021年1-10月', '2022年1-10月', '2023年1-10月', '2024年1-10月']
fiscal_income = [158533, 181526, 173397, 187494, 184981]  # 累计值亿元
yoy_percent = [-5.5, 14.5, -4.5, 8.1, -1.3]  # 累计同比%

# 创建图表
fig, ax1 = plt.subplots(figsize=(7, 6))

# 绘制深蓝色柱状图（财政收入累计值），调整 width 参数使柱子变窄
ax1.bar(years, fiscal_income, color='navy', alpha=0.7, label='公共财政收入：累计值（亿元）', width=0.35)  # 默认宽度是 0.8，改为 0.4
ax1.set_ylabel('财政收入累计值（亿元）', color='navy')
ax1.tick_params(axis='y', labelcolor='navy')
ax1.set_ylim(0, 205000)  # Y 轴范围（0 到 22 万亿）

# 在柱状图上标注数值（字体大小为 12）
for i, v in enumerate(fiscal_income):
    ax1.text(i, v + 5000, str(v), ha='center', va='bottom', color='navy', fontsize=12)

# 创建第二个 Y 轴（用于同比增长%）
ax2 = ax1.twinx()
ax2.plot(years, yoy_percent, color='#FF4040', marker='o', label='累计同比%')  # 明亮的鲜红色
ax2.set_ylabel('累计同比（%）', color='#FF4040')
ax2.tick_params(axis='y', labelcolor='#FF4040')
ax2.set_ylim(-10, 20)  # Y 轴范围（-15% 到 25%）

# 在折线图数据点上标注数值（字体大小为 12，添加红色矩形背景，字体颜色为白色）
for i, v in enumerate(yoy_percent):
    ax2.text(i, v + 0.5, f'{v}%', 
             ha='center', va='bottom', 
             color='white', fontsize=12,
             bbox=dict(facecolor='#FF4040', edgecolor='none', boxstyle='round,pad=0.2'))

# 添加标题和图例
plt.title('2020-2024年1-10月公共财政收入', fontsize=14)
fig.legend(loc='lower left', bbox_to_anchor=(0.14, 0.16), prop={'size': 12})

# 调整 X 轴刻度标签（旋转 45°，字体大小为 12）
ax1.set_xticklabels(years, rotation=30, fontsize=13)

# 调整布局
plt.tight_layout()

# 显示图表
plt.show()