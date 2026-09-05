#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Create a new adjacency-list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Add an undirected edge
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function to detect cycle
bool dfs(int vertex, int parent, bool visited[], Node* adj[]) {
    visited[vertex] = true;

    Node* temp = adj[vertex];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        // Visit unvisited neighbor
        if (!visited[neighbor]) {
            if (dfs(neighbor, vertex, visited, adj))
                return true;
        }

        // If already visited and not parent -> cycle
        else if (neighbor != parent) {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

// Check whether graph contains a cycle
bool isCycle(int V, Node* adj[]) {
    bool* visited = (bool*)calloc(V, sizeof(bool));

    // Graph may have multiple components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                free(visited);
                return true;
            }
        }
    }

    free(visited);
    return false;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    Node** adj = (Node**)calloc(V, sizeof(Node*));

    printf("Enter edges (u v):\n");

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
    }

    if (isCycle(V, adj))
        printf("true\n");
    else
        printf("false\n");

    // Free adjacency list
    for (int i = 0; i < V; i++) {
        Node* current = adj[i];

        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    free(adj);

    return 0;
}