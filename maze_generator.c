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
 for(int j = 0; j < c; j++)
 m->grid[i][j] = WALL;
}
void display(Maze *m) {
 printf("\n");
 for(int i = 0; i < m->rows; i++) {
 printf(" ");
 for(int j = 0; j < m->cols; j++)
 printf("%c ", m->grid[i][j]);
 printf("\n");
 }
 printf("\n");
}
int valid(Maze *m, int r, int c) {
 return r > 0 && r < m->rows-1 && c > 0 && c < m->cols-1;
}
void carve(Maze *m, int r, int c) {
 int dir[4][2] = {{-2,0},{0,2},{2,0},{0,-2}}, i, j, nr, nc;
 m->grid[r][c] = PATH;
 for(i = 3; i > 0; i--) {
 j = rand() % (i+1);
 int tr = dir[i][0], tc = dir[i][1];
 dir[i][0] = dir[j][0]; dir[i][1] = dir[j][1];
 dir[j][0] = tr; dir[j][1] = tc;
 }
 for(i = 0; i < 4; i++) {
 nr = r + dir[i][0]; nc = c + dir[i][1];
 if(valid(m, nr, nc) && m->grid[nr][nc] == WALL) {
 int cnt = 0, dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
 for(j = 0; j < 4; j++)
 if(valid(m, nr+dr[j], nc+dc[j]) && m->grid[nr+dr[j]][nc+dc[j]] == PATH) cnt++;
 if(cnt <= 1) {
 m->grid[r + dir[i][0]/2][c + dir[i][1]/2] = PATH;
 carve(m, nr, nc);
 }
 }
 }
}
void addPaths(Maze *m, int n) {
 for(int i = 0, att = 0; i < n && att < n*10; att++) {
 int r = 2 + rand() % (m->rows-4), c = 2 + rand() % (m->cols-4);
 if(m->grid[r][c] == WALL) {
 int cnt = 0;
 if(valid(m,r-1,c) && m->grid[r-1][c]==PATH) cnt++;
 if(valid(m,r+1,c) && m->grid[r+1][c]==PATH) cnt++;
 if(valid(m,r,c-1) && m->grid[r][c-1]==PATH) cnt++;
 if(valid(m,r,c+1) && m->grid[r][c+1]==PATH) cnt++;
 if(cnt == 2) { m->grid[r][c] = PATH; i++; }
 }
 }
}
void generate(Maze *m, int r, int c) {
 if(r%2==0) r++; if(c%2==0) c++;
 initMaze(m, r, c);
 carve(m, 2, 2);
 addPaths(m, (r*c)/50);
 m->startRow = 2; m->startCol = 2;
 m->grid[m->startRow][m->startCol] = START;
 int br = 2, bc = 2, md = 0;
 for(int i = r-3; i > r/2; i--)
 for(int j = c-3; j > c/2; j--)
 if(m->grid[i][j] == PATH) {
 int d = abs(i-m->startRow) + abs(j-m->startCol);
 if(d > md) { md = d; br = i; bc = j; }
 }
 m->endRow = br; m->endCol = bc;
 m->grid[m->endRow][m->endCol] = END;
}
int solve(Maze *m) {
 Queue q; int vis[MAX][MAX] = {0}, dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
 initQueue(&q);
 for(int i = 0; i < m->rows; i++)
 for(int j = 0; j < m->cols; j++)
 parent[i][j].row = parent[i][j].col = -1;
 enqueue(&q, m->startRow, m->startCol);
 vis[m->startRow][m->startCol] = 1;
 while(!isEmpty(&q)) {
 Point p = dequeue(&q);
 if(p.row == m->endRow && p.col == m->endCol) {
 int pr = m->endRow, pc = m->endCol, len = 0;
 while(!(pr == m->startRow && pc == m->startCol)) {
 if(m->grid[pr][pc] != START && m->grid[pr][pc] != END) {
 m->grid[pr][pc] = SOL; len++;
 }
 int tr = parent[pr][pc].row, tc = parent[pr][pc].col;
 pr = tr; pc = tc;
 }
 return len;
 }
 for(int i = 0; i < 4; i++) {
 int nr = p.row + dir[i][0], nc = p.col + dir[i][1];
 if(valid(m,nr,nc) && !vis[nr][nc] && (m->grid[nr][nc]==PATH || m->grid[nr][nc]==END)) {
 vis[nr][nc] = 1;
 parent[nr][nc].row = p.row; parent[nr][nc].col = p.col;
 enqueue(&q, nr, nc);
 }
 }
 }
 return -1;
}
void showSolution(Maze *m) {
 Maze temp = *m;
 printf("\nFinding shortest path...\n");
 int len = solve(&temp);
 if(len >= 0) {
 printf("Solution found\n\nS=Start, E=End, *=Shortest Path\n");
 display(&temp);
 printf("Path length: %d steps\n", len+1);
 } else printf("No solution found\n");
}
void manual(Maze *m) {
 int vis[MAX][MAX] = {0}, cr = m->startRow, cc = m->startCol, moves = 0;
 char move;
 for(int i = 0; i < m->rows; i++)
 for(int j = 0; j < m->cols; j++) vis[i][j] = 0;
 vis[cr][cc] = 1;
 printf("\nManual Mode\nW=Up, S=Down, A=Left, D=Right, Q=Quit\nPress Enter...");
 getchar();
 while(1) {
 system("clear || cls");
