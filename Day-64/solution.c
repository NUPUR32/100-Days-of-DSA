#include <stdio.h>

#define MAX 10

typedef struct {
    int row;
    int col;
} Node;

int orangesRotting(int grid[MAX][MAX], int rows, int cols)
{
    Node queue[MAX * MAX];
    int front = 0, rear = 0;
    int fresh = 0;
    int minutes = 0;

    // Add all initially rotten oranges to the queue
    // and count fresh oranges.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 2)
            {
                queue[rear].row = i;
                queue[rear].col = j;
                rear++;
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    // No fresh oranges
    if (fresh == 0)
        return 0;

    int directions[4][2] = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1}    // Right
    };

    // Multi-source BFS
    while (front < rear && fresh > 0)
    {
        int levelSize = rear - front;

        // Process all oranges that are rotten
        // at the current minute.
        for (int i = 0; i < levelSize; i++)
        {
            Node current = queue[front++];

            for (int d = 0; d < 4; d++)
            {
                int newRow = current.row + directions[d][0];
                int newCol = current.col + directions[d][1];

                // Check boundaries and fresh orange
                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == 1)
                {
                    // Make orange rotten
                    grid[newRow][newCol] = 2;
                    fresh--;

                    // Add newly rotten orange to queue
                    queue[rear].row = newRow;
                    queue[rear].col = newCol;
                    rear++;
                }
            }
        }

        minutes++;
    }

    // Fresh oranges still remain
    if (fresh > 0)
        return -1;

    return minutes;
}

int main()
{
    int grid[MAX][MAX];
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter grid:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, rows, cols);

    printf("Minimum minutes: %d\n", result);

    return 0;
}