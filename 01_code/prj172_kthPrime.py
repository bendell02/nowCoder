#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

primes = [2, 3]
maxn = 10000

def isPrime(number):
    if number > 1:
        if number == 2:
            return True
        if number % 2 == 0:
            return False
        i = 3
        while i*i <= number:
            if number % i == 0:
                return False
            i += 2
        return True
    return False

def generatePrimes():
    idx = 5
    nums=2
    while nums <= maxn:
        if isPrime(idx):
            primes.append(idx)
            nums += 1
        idx += 2

generatePrimes()
while True:
    try:
        k = input()
        print primes[k-1]
    except:
        break
