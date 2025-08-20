#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 50
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'
#define SOL '*'
#define PLAYER '@'
typedef struct {
 int rows, cols, startRow, startCol, endRow, endCol;
 char grid[MAX][MAX];
} Maze;
typedef struct {
 int row, col;
} Point;
typedef struct {
 Point data[MAX * MAX];
 int front, rear;
} Queue;
Point parent[MAX][MAX];
void initQueue(Queue *q) { q->front = q->rear = 0; }
int isEmpty(Queue *q) { return q->front == q->rear; }
void enqueue(Queue *q, int r, int c) { q->data[q->rear].row = r; q->data[q->rear++].col = c; }
Point dequeue(Queue *q) { return q->data[q->front++]; }
void initMaze(Maze *m, int r, int c) {
 m->rows = r; m->cols = c;
 for(int i = 0; i < r; i++)
