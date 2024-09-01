#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;         // 选手编号
    int score;      // 当前总分
    int power;      // 实力值
} Player;

// 比较函数用于排序
int compare(const void *a, const void *b) {
    Player *p1 = (Player *)a;
    Player *p2 = (Player *)b;

    if (p1->score != p2->score) {
        return p2->score - p1->score;  // 按分数降序
    } else {
        return p1->id - p2->id;        // 分数相同时按编号升序
    }
}

int main() {
    int N, R, Q;
    scanf("%d %d %d", &N, &R, &Q);

    int numPlayers = 2 * N;
    Player players[numPlayers];

    // 读取初始分数
    for (int i = 0; i < numPlayers; i++) {
        players[i].id = i + 1;
        scanf("%d", &players[i].score);
    }

    // 读取实力值
    for (int i = 0; i < numPlayers; i++) {
        scanf("%d", &players[i].power);
    }

    // 首次排序
    qsort(players, numPlayers, sizeof(Player), compare);

    // 进行 R 轮比赛
    for (int round = 0; round < R; round++) {
        for (int i = 0; i < numPlayers; i += 2) {
            if (players[i].power > players[i + 1].power) {
                players[i].score++;
            } else {
                players[i + 1].score++;
            }
        }
        // 重新排序
        qsort(players, numPlayers, sizeof(Player), compare);
    }

    // 输出最终排名第 Q 的选手编号
    printf("%d\n", players[Q - 1].id);

    return 0;
}
