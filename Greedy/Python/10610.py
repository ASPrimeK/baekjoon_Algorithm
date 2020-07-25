string = input()
sum = 0
mul10 = False
for s in string:
    a = int(s)
    if a == 0:
        mul10 = True
    sum += a
if sum % 3 != 0 or mul10 == False:
    print(-1)
else:
    string = sorted(string, reverse=True)
    string = ''.join(string)
    print(string)
