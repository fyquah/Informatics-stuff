#include <cstdio>
#include <cmath>
using namespace std;
 
int n, sequence[14] = { 0 }, sols=0;
 
void dfs(long v_cols, long l_diag, long r_diag, int row, const int goal) {
    if (v_cols != goal) {
        long av = goal & ~(v_cols | l_diag | r_diag), col;
        while (av && (col=av & -av)) {
            av -= col, sequence[row] = col;
            dfs(v_cols + col, (l_diag + col) << 1, (r_diag + col) >> 1, row + 1, goal);
        }
    } else {
        if (sols < 3) {
            for (int i = 0; i < row-1; i++)
                printf("%d ", int(log2(sequence[i]))+1);
            printf("%d\n", int(log2(sequence[row-1]))+1);
        }
        sols++;
    }
}
 
int main(int argc, char *argv[]) {
 
    freopen("checker.in", "r", stdin), freopen("checker.out", "w", stdout);
    scanf("%d", &n);
    dfs(0, 0, 0, 0, (1 << n) - 1);
    printf("%d\n", sols);
 
    return 0;
}