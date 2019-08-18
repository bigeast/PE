#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
const int N = 30;
int grids[N][N];
int gridsT[N][N];
const int K = 10000;
int all_zeros = 0;
struct dir {
  int x;
  int y;
};
struct dir Dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct dir *up = &Dir[0];
struct dir *down = &Dir[1];
struct dir *left = &Dir[2];
struct dir *right = &Dir[3];
int fleas_jump() {
  int d;
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      if (x == 0 && y == 0) {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 2;
          if (d == 0) {
            ++gridsT[x + down->x][y + down->y];
          } else {
            ++gridsT[x + right->x][y + right->y];
          }
        }
      } else if (x == 0 && y == N - 1){
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 2;
          if (d == 0) {
            ++gridsT[x + down->x][y + down->y];
          } else {
            ++gridsT[x + left->x][y + left->y];
          }
        }
      } else if(x == N - 1 && y == 0) {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 2;
          if (d == 0) {
            ++gridsT[x + up->x][y + up->y];
          } else {
            ++gridsT[x + right->x][y + right->y];
          }
        }
      } else if(x == N - 1 && y == N - 1) {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 2;
          if (d == 0) {
            ++gridsT[x + up->x][y + up->y];
          } else {
            ++gridsT[x + left->x][y + left->y];
          }
        }
      } else if (x == 0) {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 3;
          if (d == 0) {
            ++gridsT[x + down->x][y + down->y];
          } else if(d == 1){
            ++gridsT[x + left->x][y + left->y];
          } else {
            ++gridsT[x + right->x][y + right->y];
          }
        }
      } else if (x == N - 1) {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 3;
          if (d == 0) {
            ++gridsT[x + up->x][y + up->y];
          } else if(d == 1){
            ++gridsT[x + left->x][y + left->y];
          } else {
            ++gridsT[x + right->x][y + right->y];
          }
        }
      } else if (y == 0) {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 3;
          if (d == 0) {
            ++gridsT[x + up->x][y + up->y];
          } else if(d == 1){
            ++gridsT[x + down->x][y + down->y];
          } else {
            ++gridsT[x + right->x][y + right->y];
          }
        }
      } else if (y == N - 1) {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 3;
          if (d == 0) {
            ++gridsT[x + up->x][y + up->y];
          } else if(d == 1){
            ++gridsT[x + down->x][y + down->y];
          } else {
            ++gridsT[x + left->x][y + left->y];
          }
        }
      } else {
        for (int i = 0; i < grids[x][y]; i++) {
          d = rand() % 4;
          if (d == 0) {
            ++gridsT[x + up->x][y + up->y];
          } else if (d == 1) {
            ++gridsT[x + down->x][y + down->y];
          } else if (d == 2) {
            ++gridsT[x + left->x][y + left->y];
          } else {
            ++gridsT[x + right->x][y + right->y];
          }
        }
      }
    }
  }
  return 0;
}
int main(int argc, const char *argv[]) {
  time_t t;
  int J = atoi(argv[1]);
  std::vector<int> zeros_grid(J + 1);
  srand((unsigned) time(&t));
  for(int k = 0; k < K; ++k) {
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < N; y++) {
        grids[x][y] = 1;
      }
    }
    for (int jump = 1; jump <= J; jump++) {
      fleas_jump();
      int zeros = 0;
      for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
          if (grids[x][y] == 0)
            ++zeros;
        }
      }
      zeros_grid[jump] = zeros;
      memcpy(grids, gridsT, sizeof(grids));
      memset(gridsT, 0, sizeof(gridsT));
    }
    // printf("%d\n", zeros);
  }
  for (int jump = 1; jump <= J; jump++) {
    printf("Jump %d: %10d %.6f\n", jump, zeros_grid[jump], zeros_grid[jump] / 900.0);
  }
  return 0;
}
