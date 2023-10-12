import colorsys

# 从一行输入中解析RGB颜色值（范围是0到255，用空格分隔）
input_values = input().split()
r = int(input_values[0])
g = int(input_values[1])
b = int(input_values[2])

# 将RGB转换为HSV
h, s, v = colorsys.rgb_to_hsv(r / 255.0, g / 255.0, b / 255.0)

# 将S和V转换为百分比形式，并保留4位小数点
s_percent = format(s * 100, ".4f")
v_percent = format(v * 100, ".4f")

# 在结果中加上百分号
s_percent += "%"
v_percent += "%"

# 用逗号分隔结果
result = f"{h:.4f},{s_percent},{v_percent}"

print(result)
