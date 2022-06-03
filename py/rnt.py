#!/usr/bin/env python3

import argparse
import random

parser = argparse.ArgumentParser(description="RNT or Random Node Tree is a program that generates a spanning tree with random lengths between nodes used for calculating a spanning tree")

parser.add_argument('-n', '--nodes', dest='nodes', type=int, default=4, help='Number of nodes')
parser.add_argument('-l', '--length', dest='length', type=int, default=10, help='Maximum length between nodes')
parser.add_argument('-o', '--odds', dest='odds', type=int, default=20, help='Odds of path between nodes (0-100)')
parser.add_argument('-p', '--pretty', dest='pretty', action='store_true', help='print pretty format')

parser.add_argument('--version', action='version', version='Random Node Tree 1.2')

args = parser.parse_args();

def generateTree(nodes: int, length: int, odds: int):
    tree = [[0 for x in range(nodes)] for y in range(nodes)]

    # Start filling the tree with random numbers
    for i in range(nodes - 1):
        hasPath = False
        for j in range(i + 1, nodes):
            if (random.randint(1, 100) < odds):
                tree[i][j] = random.randint(1, length)
                hasPath = True
            else:
                tree[i][j] = 0

        # Check if tree has haning nodes, if it does, add a random path
        if not (hasPath):
            tree[i][random.randint(0, nodes-1)] = random.randint(1, length)

    # Mirror the tree
    for i in range(nodes):
        for j in range(i):
            tree[i][j] = tree[j][i]

    size_separator = len(str(length))

    if (args.pretty):
        # Print pretty tree
        for i in range(nodes):
            for j in range(nodes):
                print('{:{size_separator}d} '.format(tree[i][j], size_separator=size_separator), end='')
            print('')
    else:
        # Print tree
        print('tree = [', end='')
        for i in range(nodes):
            print('[', end='')
            for j in range(nodes):
                print(tree[i][j], end='')
                if (j+1 < nodes):
                    print(' ', end='')
            print(']', end='')
            if (i+1 < nodes):
                print(';', end='')
        print('];')

generateTree(args.nodes, args.length, args.odds)
