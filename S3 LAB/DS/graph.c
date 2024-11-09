#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node* adjList[MAX_NODES];
};

// Function to create a new graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For undirected graph, add edge from dest to src as well
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Depth First Search (DFS)
void DFS(struct Graph* graph, int startNode, int visited[]) {
    visited[startNode] = 1;
    printf("%d ", startNode);

    struct Node* temp = graph->adjList[startNode];

    while (temp != NULL) {
        int adjNode = temp->data;
        if (!visited[adjNode]) {
            DFS(graph, adjNode, visited);
        }
        temp = temp->next;
    }
}

// Breadth First Search (BFS)
void BFS(struct Graph* graph, int startNode, int visited[]) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        struct Node* temp = graph->adjList[currentNode];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                queue[rear++] = adjNode;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numVertices,src,dest; 
    printf("Number of vertices : ");
    scanf("%d",&numVertices);
    struct Graph* graph = createGraph(numVertices);
    int visited[MAX_NODES] = {0}; // Initialize all vertices as not visited

    // Adding edges to the graph
    for(int i=0;i<numVertices;i++){
        printf("Enter source and destination : ");
        scanf("%d %d",&src,&dest);
        addEdge(graph,src,dest);
    }
    
    printf("Depth First Search (DFS): ");
    DFS(graph, 0, visited);
    printf("\n");

    // Reset visited array
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = 0;
    }

    printf("Breadth First Search (BFS): ");
    BFS(graph, 0, visited);
    printf("\n");

    return 0;
}
