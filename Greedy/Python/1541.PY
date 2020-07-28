string = input()
sub = False
total = 0
num = 0
for s in string:
    if s in "0123456789":
        num = num*10 + int(s)
    elif sub == True:
        total -= num
        num = 0
    else:
        total += num
        num = 0
        if s == '-':
            sub = True
if sub == True:
    total -= num
else:
    total += num
print(total)
