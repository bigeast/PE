#!/usr/bin/env python
import pygame
import random
import sys
import time
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
darkBlue = (0,0,128)
white = (255,255,255)
black = (0,0,0)
pink = (255,200,200)

N = 30
xs, ys = 0, 0

pygame.init()
screen = pygame.display.set_mode((300, 300))

dColor = 80
grids = [[1 for x in range(N)] for x in range(N)]
gridsT = [[0 for x in range(N)] for x in range(N)]
screen.fill(green)

# Dir = { "up": (-1, 0), "down": (1, 0), "left": (0, -1), "right": (0, 1)}
class Dir:
    up = (-1, 0)
    down = (1, 0)
    left = (0, -1)
    right = (0, 1)

clock = pygame.time.Clock()
for frame in range(500):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    for x in range(N):
        for y in range(N):
            c = min(dColor * grids[x][y], 255)
            pygame.draw.rect(screen, (c, c, c), (xs + x * 10, ys + y * 10, 10, 10), 0)

    # for NxN grid
    print "Jump"
    S = 0
    for x in range(N):
        for y in range(N):
            S += grids[x][y]
            # eight cases
            if x == 0 and y == 0:
                # down, right
                for i in range(grids[x][y]):
                    dir = random.randint(0, 1)
                    if dir == 0:
                        gridsT[x + Dir.down[0]][y + Dir.down[1]] += 1
                    else:
                        gridsT[x + Dir.right[0]][y + Dir.right[1]] += 1
                #print "Case 1", x, y, grids[x][y]
            elif x == 0 and y == N - 1:
                # down, left
                for i in range(grids[x][y]):
                    dir = random.randint(0, 1)
                    if dir == 0:
                        gridsT[x + Dir.down[0]][y + Dir.down[1]] += 1
                    else:
                        gridsT[x + Dir.left[0]][y + Dir.left[1]] += 1
                #print "Case 2", x, y, grids[x][y]
            elif x == N - 1 and y == 0:
                # up, right
                for i in range(grids[x][y]):
                    dir = random.randint(0, 1)
                    if dir == 0:
                        gridsT[x + Dir.up[0]][y + Dir.up[1]] += 1
                    else:
                        gridsT[x + Dir.right[0]][y + Dir.right[1]] += 1
                #print "Case 3", x, y, grids[x][y]
            elif x == N - 1 and y == N - 1:
                # up, left
                for i in range(grids[x][y]):
                    dir = random.randint(0, 1)
                    if dir == 0:
                        gridsT[x + Dir.up[0]][y + Dir.up[1]] += 1
                    else:
                        gridsT[x + Dir.left[0]][y + Dir.left[1]] += 1
                #print "Case 4", x, y, grids[x][y]
            elif x == 0:
                # down, left, right
                for i in range(grids[x][y]):
                    dir = random.randint(0, 2)
                    if dir == 0:
                        gridsT[x + Dir.down[0]][y + Dir.down[1]] += 1
                    elif dir == 1:
                        gridsT[x + Dir.left[0]][y + Dir.left[1]] += 1
                    else:
                        gridsT[x + Dir.right[0]][y + Dir.right[1]] += 1
                #print "Case 5", x, y, grids[x][y]
            elif x == N - 1:
                # up, left, right
                for i in range(grids[x][y]):
                    dir = random.randint(0, 2)
                    if dir == 0:
                        gridsT[x + Dir.up[0]][y + Dir.up[1]] += 1
                    elif dir == 1:
                        gridsT[x + Dir.left[0]][y + Dir.left[1]] += 1
                    else:
                        gridsT[x + Dir.right[0]][y + Dir.right[1]] += 1
                #print "Case 6", x, y, grids[x][y]
            elif y == 0:
                # up, down, right
                for i in range(grids[x][y]):
                    dir = random.randint(0, 2)
                    if dir == 0:
                        gridsT[x + Dir.up[0]][y + Dir.up[1]] += 1
                    elif dir == 1:
                        gridsT[x + Dir.down[0]][y + Dir.down[1]] += 1
                    else:
                        gridsT[x + Dir.right[0]][y + Dir.right[1]] += 1
                #print "Case 7", x, y, grids[x][y]
            elif y == N - 1:
                # up, down, left
                for i in range(grids[x][y]):
                    dir = random.randint(0, 2)
                    if dir == 0:
                        gridsT[x + Dir.up[0]][y + Dir.up[1]] += 1
                    elif dir == 1:
                        gridsT[x + Dir.down[0]][y + Dir.down[1]] += 1
                    else:
                        gridsT[x + Dir.left[0]][y + Dir.left[1]] += 1
                #print "Case 8", x, y, grids[x][y]
            else:
                # up, down, left, right
                for i in range(grids[x][y]):
                    dir = random.randint(0, 3)
                    if dir == 0:
                        gridsT[x + Dir.up[0]][y + Dir.up[1]] += 1
                    elif dir == 1:
                        gridsT[x + Dir.down[0]][y + Dir.down[1]] += 1
                    elif dir == 2:
                        gridsT[x + Dir.left[0]][y + Dir.left[1]] += 1
                    else:
                        gridsT[x + Dir.right[0]][y + Dir.right[1]] += 1
                #print "Case 9", x, y, grids[x][y]
    # print "===============", frame
    # for x in range(N):
    #     for y in range(N):
    #         print gridsT[x][y],
    #     print ""

    for x in range(N):
        for y in range(N):
            grids[x][y] = gridsT[x][y]
            gridsT[x][y] = 0
    pygame.display.update()
    time.sleep(0.1)
