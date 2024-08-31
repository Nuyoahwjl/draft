from scipy.stats import norm

def calculate_probability():
    mean = float(input("均值："))
    std_dev = float(input("标准差："))
    a_value = float(input("a值: "))
    probability = norm.cdf(a_value, mean, std_dev)
    print(probability)

def calculate_a_value():
    mean = float(input("均值："))
    std_dev = float(input("标准差："))
    p = float(input("概率值: "))
    a_value = norm.ppf(p, mean, std_dev)
    print(a_value)


def calculate_probability_range():
    mean = float(input("均值："))
    std_dev = float(input("标准差："))
    a_value = float(input("a值: "))
    b_value = float(input("b值: "))
    probability = norm.cdf(b_value, mean, std_dev) - norm.cdf(a_value, mean, std_dev)
    print(probability)

while True:
    print("请选择功能：")
    print("1. 输入a,求P(X <= a)的概率")
    print("2. 已知P(X <= a)的概率,求a的值")
    print("3. 求P(a <= X <= b)的概率")
    print("0. 退出")
    choice = input("请输入选项：")
    
    if choice == "1":
        calculate_probability()
    elif choice == "2":
        calculate_a_value()
    elif choice == "3":
        calculate_probability_range()
    elif choice == "0":
        break
    else:
        print("无效的选项，请重新输入。")





