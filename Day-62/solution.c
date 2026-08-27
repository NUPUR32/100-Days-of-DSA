#include <stdio.h>

void dfs(int room, int rooms[][1000], int roomSize[], int visited[])
{
    visited[room] = 1;

    for (int i = 0; i < roomSize[room]; i++)
    {
        int nextRoom = rooms[room][i];

        if (!visited[nextRoom])
        {
            dfs(nextRoom, rooms, roomSize, visited);
        }
    }
}

int canVisitAllRooms(int rooms[][1000], int roomSize[], int n)
{
    int visited[1000] = {0};

    dfs(0, rooms, roomSize, visited);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return 0;
    }

    return 1;
}

int main()
{
    int n = 4;

    int rooms[1000][1000] = {
        {1},
        {2},
        {3},
        {}
    };

    int roomSize[4] = {1, 1, 1, 0};

    if (canVisitAllRooms(rooms, roomSize, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}