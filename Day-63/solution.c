#include <stdio.h>

#define MAX 50

// DFS function for Flood Fill
void dfs(int image[MAX][MAX], int rows, int cols,
         int r, int c, int oldColor, int newColor)
{
    // Boundary check
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    // Process only pixels having the original color
    if (image[r][c] != oldColor)
        return;

    // Change the color
    image[r][c] = newColor;

    // Visit 4 adjacent pixels
    dfs(image, rows, cols, r - 1, c, oldColor, newColor); // Up
    dfs(image, rows, cols, r + 1, c, oldColor, newColor); // Down
    dfs(image, rows, cols, r, c - 1, oldColor, newColor); // Left
    dfs(image, rows, cols, r, c + 1, oldColor, newColor); // Right
}

void floodFill(int image[MAX][MAX], int rows, int cols,
               int sr, int sc, int color)
{
    int oldColor = image[sr][sc];

    // Important: prevents infinite recursion
    if (oldColor == color)
        return;

    dfs(image, rows, cols, sr, sc, oldColor, color);
}

void printImage(int image[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int image[MAX][MAX];
    int rows, cols;
    int sr, sc, color;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter image matrix:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter starting row (sr): ");
    scanf("%d", &sr);

    printf("Enter starting column (sc): ");
    scanf("%d", &sc);

    printf("Enter new color: ");
    scanf("%d", &color);

    floodFill(image, rows, cols, sr, sc, color);

    printf("\nImage after Flood Fill:\n");
    printImage(image, rows, cols);

    return 0;
}