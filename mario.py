import cs50

#get height
while True:
    height = cs50.get_int("How high?")
    if height > 0 and height < 24:
        break

#iterate {height} times
for i in range(height):
    #print spaces
    for space in range(height - 1 - i):
        print(" ", end="")
    #print hashes
    for block in range(i + 2):
        print("#", end="")
    #print newline
    print()

