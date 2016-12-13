import sys
import os

def distance(p1,p2):
    r1 = int(p1[0:8],2)
    g1 = int(p1[8:16],2)
    b1 = int(p1[16:24],2)

    r2 = int(p2[0:8],2)
    g2 = int(p2[8:16],2)
    b2 = int(p2[16:24],2)

    d = float( ((r1 - r2)**2) + ((g1-g2)**2) + ((b1-b2)**2) )**(1.0/2)
    return d

def ClosestColor(hexcodes):

    black = '000000000000000000000000'
    white = '111111111111111111111111'
    red   = '111111110000000000000000'
    green = '000000001111111100000000'
    blue  = '000000000000000011111111'

    results = []
    for pixel in hexcodes:
        colors = ['Black','White','Red','Green','Blue']
        distances = [distance(pixel,black),
                     distance(pixel,white),
                     distance(pixel,red),
                     distance(pixel,green),
                     distance(pixel,blue)]

        minval = min(distances)
        if (distances.count(minval) > 1) :
            mincolor = 'Ambiguous'
        else:
            mincolor = colors[distances.index(minval)]

        results.append(mincolor)
    return results


_hexcodes_cnt = 0
_hexcodes_cnt = int(raw_input())
_hexcodes_i = 0
_hexcodes = []

while _hexcodes_i < _hexcodes_cnt:
    _hexcodes_item = raw_input()
    _hexcodes.append(_hexcodes_item)
    _hexcodes_i += 1

print ClosestColor(_hexcodes);

