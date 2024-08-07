#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[][V], int setOfCities, int currentPos, int n, int dp[][V]) {
    if (setOfCities == (1 << n) - 1)
        return graph[currentPos][0];

    if (dp[setOfCities][currentPos] != -1)
        return dp[setOfCities][currentPos];

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((setOfCities & (1 << city)) == 0) {
            int newAns = graph[currentPos][city] + tsp(graph, setOfCities | (1 << city), city, n, dp);
            ans = (ans < newAns) ? ans : newAns;
        }
    }
    return dp[setOfCities][currentPos] = ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
        for (int j = 0; j < V; j++)
            dp[i][j] = -1;
    printf("The minimum cost is %d", tsp(graph, 1, 0, V, dp));
    return 0;
}
