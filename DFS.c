#include <stdio.h>
#include <stdlib.h>

typedef struct ll{
    int data;
    struct ll *nxt;
} Stack;

void push(Stack **sp, int data){
    Stack *temp = (Stack *) malloc(sizeof(Stack));
    temp->data = data;
    temp->nxt = *sp;
    *sp = temp;
}

int pop(Stack **sp){
    int data = (*sp)->data;
    *sp = (*sp)->nxt;
    return data;
}

int isEmpty(Stack *sp){
    return (sp == NULL);
}

void initialise(int v, int graph[v][v], int visited[v]){
    int i,j;
    for(i = 0; i<v; i+=1){
        visited[v] = 0;
        for(j = 0; j<v; j+=1){
            graph[i][j] = 0;
        }
    }
}

void printgraph(int v, int graph[v][v]){
    int i,j;
    for(i = 0; i<v; i+=1){
        for(j = 0; j<v; j+=1){
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

void creategraph(int v, int graph[v][v]){
    int connect,i,j;
    for(i = 0; i<v; i+=1){
        for(j = 0; j<v; j+=1){
            if(i == j) continue;
            printf("Connection from %d to %d (1 to connect, 0 to disconnect) -> ", i, j);
            scanf("%d", &connect);
            graph[i][j] = connect;
        }
    }
}

void dfs(int v, int graph[v][v], int visited[v], int start, Stack *sp){
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    visited[start] = 1;
    push(&sp, start);
    while(!isEmpty(sp)){
        int n = pop(&sp);
        int i;
        printf("%d ", n);
        visited[n] = 1;
        for(i = 0; i<v; i+=1){
            if(graph[n][i] == 1 && !visited[i]) push(&sp, i);
        }
    }
    printf("\n");
}

int main(){
    Stack *sp = NULL;
    int v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    int graph[v][v], visited[v];
    initialise(v, graph, visited);
    creategraph(v, graph);
    dfs(v, graph, visited, start, sp);
    printgraph(v, graph);
    return 0;
}
