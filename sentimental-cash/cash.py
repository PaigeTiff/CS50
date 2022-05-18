# TODO
from cs50 import get_float

# __float__()
count = 0

while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

cent = round(change * 100)

# the change for quarters
while cent >= 25:
    cent -= 25
    count += 1

# the change for dimes
while cent >= 10:
    cent -= 10
    count += 1

# the change for nickles
while cent >= 5:
    cent -= 5
    count += 1

# the change for pennies
while cent >= 1:
    cent -= 1
    count += 1

print(count)