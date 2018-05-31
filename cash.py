# gives number of coins (25c 10c 5c 1c) to make a float input
import cs50

# get positive float input
while True:
    change = cs50.get_float("How much change?")
    if change > 0:
        break

# input in cents, rounded to nearest cent
cents = round(100 * change)

count = 0

# quarters, floor-divide by 25 for count, remainder is what's left!
count += (cents // 25)
cents = cents % 25

# dimes
count += (cents // 10)
cents = cents % 10

# nickels
count += (cents // 5)
cents = cents % 5

# pennies, no need to divide here.
count += cents

print(f"count is {count}")
