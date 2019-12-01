
def fuel(num):
    return (num // 3) - 2 


def check_fuel(num):
    
    result = fuel(num) # original value 
    if result <= 0:
        return 0
    return result + check_fuel(result) 

result = 0
with open('./input.txt') as f:
    for line in f:
        num =long(line)
        result += check_fuel(num)

print(result)
