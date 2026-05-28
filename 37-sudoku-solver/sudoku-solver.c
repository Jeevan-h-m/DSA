int rows[9], cols[9], boxes[9];
int box(int r, int c) { return (r / 3) * 3 + c / 3; } int ok(int r, int c, int bit) {
return !(rows[r] & bit) && !(cols[c] & bit) && !(boxes[box(r,c)] &
 
bit);
}
int solve(char** board, int pos) {
while (pos < 81 && board[pos/9][pos%9] != '.') pos++; if (pos == 81) return 1;

int r = pos / 9, c = pos % 9; for (int d = 1; d <= 9; d++) {
int bit = 1 << d;
if (!ok(r, c, bit)) continue;
rows[r] |= bit; cols[c] |= bit; boxes[box(r,c)] |= bit; board[r][c] = '0' + d;
if (solve(board, pos + 1)) return 1;
rows[r] ^= bit; cols[c] ^= bit; boxes[box(r,c)] ^= bit; board[r][c] = '.';
}
return 0;
}
void solveSudoku(char** board, int boardSize, int* boardColSize) { memset(rows, 0, sizeof(rows));
memset(cols, 0, sizeof(cols));
memset(boxes, 0, sizeof(boxes));
for (int r = 0; r < 9; r++) { for (int c = 0; c < 9; c++) {
if (board[r][c] == '.') continue;
int bit = 1 << (board[r][c] - '0');
rows[r] |= bit; cols[c] |= bit; boxes[box(r,c)] |= bit;
}
}
solve(board, 0);
}
