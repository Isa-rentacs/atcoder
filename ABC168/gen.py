import logging
n = 100000
m = 200000

print("{} {}".format(n, m))
counter = 0
for i in range(n):
    for j in range(n):
        if i >= j:
            continue
        
        print("{} {}".format(i+1, j+1))
        counter += 1
        if counter == m:
            break
    logging.error(counter)
    if counter == m:
        break