#include <stdio.h>

void dfs(int graph[][200], int n, int city, int visited[])
{
    visited[city] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[city][i] == 1 && !visited[i])
        {
            dfs(graph, n, i, visited);
        }
    }
}

int findCircleNum(int graph[][200], int n)
{
    int visited[200] = {0};
    int provinces = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(graph, n, i, visited);
            provinces++;
        }
    }

    return provinces;
}

int main()
{
    int n = 3;

    int graph[200][200] = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    printf("Number of Provinces = %d\n", findCircleNum(graph, n));

    return 0;
}