#!/usr/bin/python3
from sys import argv as av

def sieve_of_eratos(number):
    if number < 2:
        return []

    listNumber = [n for n in range(2, number + 1)]
    i, size = 0, len(listNumber)
    listBool = [1] * size
    primeArray = []
    tmpR = listNumber[-1]**(0.5)

    while i < size:
        n = listNumber[i]
        currentIndex = i
        i += 1
        if not listBool[currentIndex]:
            continue

        primeArray.append(n)
        j = currentIndex + n
        while n <= tmpR and j < size:
            listBool[j] = 0
            j += n

    return primeArray


if __name__ == "__main__":
    if len(av) < 2:
        print(f"Usage: {av[0]} <num>")
        exit(1)

    output = sieve_of_eratos(int(av[1]))

    print(output)