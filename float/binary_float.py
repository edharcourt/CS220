
y = .09  # convert to binary point
print('0.', end="")

# 70 bits of y
for i in range(70):
    y = 2*y
    if y >= 1.0:
        print('1', end="")  # named argument
        y = y - 1
    else:
        print('0', end="")

print()
    
    
