#!/usr/bin/python3
from sys import argv as av

def trial_division(number):
    primeArray = []

    for n in range(2, number + 1):
        tmpR = n**(0.5) # this line gets the square root of n
        i, is_prime = 0, 1

        while (primeArray and primeArray[i] <= tmpR):
            if n % primeArray[i] == 0:
                is_prime = 0
                break
            i += 1
        
        if is_prime:
            primeArray.append(n)

    return (primeArray)


if __name__ == "__main__":
    if len(av) < 2:
        print(f"Usage: {av[0]} <num>")
        exit(1)

    output = trial_division(int(av[1]))

    print(output)