#!/usr/bin/python
#-*- coding:utf-8 -*-

#Author: Ben

def checkmask(mask):
    all_mask=['128.0.0.0','192.0.0.0','224.0.0.0','240.0.0.0','248.0.0.0','252.0.0.0','254.0.0.0','255.0.0.0','255.128.0.0','255.192.0.0','255.224.0.0','255.240.0.0','255.248.0.0','255.252.0.0','255.254.0.0','255.255.0.0','255.255.128.0','255.255.192.0','255.255.224.0','255.255.240.0','255.255.248.0','255.255.252.0','255.255.254.0','255.255.255.0','255.255.255.128','255.255.255.192','255.255.255.224','255.255.255.240','255.255.255.248','255.255.255.252','255.255.255.254']
    if mask in all_mask:
        return True
    else:
        return False

def isValidMask(num):
    if 0xffffffff == ((num^(num-1)) ^ (num&(num-1))):
        return True
    else:
        return False

def convertStr2num(ipStr):
    a,b,c,d = map(int, ipStr.split('.'))
    ipNum = (a<<24) | (b<<16) | (c<<8) | d
    return ipNum

aAcounts = 0
bAcounts = 0
cAcounts = 0
dAcounts = 0
eAcounts = 0
errorAcounts = 0
privateAcounts = 0

while True:
    try:
        ipStr, maskStr = raw_input().split('~')
        try:
            maskNum = convertStr2num(maskStr)
            ipNum = convertStr2num(ipStr)
        except:
            errorAcounts +=1
            continue
            
        #if isValidMask(maskNum):
        if checkmask(maskStr):
            ipFinal = ipNum & maskNum
            if 0x01000000 <= ipFinal <= 0x7effffff:
                aAcounts += 1
            elif 0x80000000 <= ipFinal <= 0xbfffffff:
                bAcounts += 1
            elif 0xc0000000 <= ipFinal <= 0xdfffffff:
                cAcounts += 1
            elif 0xe0000000 <= ipFinal <= 0xefffffff:
                dAcounts += 1
            elif 0xf0000000 <= ipFinal <= 0xffffffff:
                eAcounts += 1

            if 0x0a000000 <= ipFinal <= 0x0affffff:
                privateAcounts += 1
            if 0xac100000 <= ipFinal <= 0xac1fffff:
                privateAcounts += 1
            if 0xc0a80000 <= ipFinal <= 0xc0a8ffff:
                privateAcounts += 1
        else:
            errorAcounts += 1
    except:
        break

print '%d %d %d %d %d %d %d' % (aAcounts, bAcounts, cAcounts, dAcounts, eAcounts, errorAcounts, privateAcounts)
