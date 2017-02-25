/* adjacent list */
void BSFTraverselist(GraphAdjList GL){
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL<-numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q);
    for (i = 0; i < GL<-numVertexes; i++){
        if(!visited[i]){
            visited[i] = TRUE;
            printf('%c', GL->adjList[i].data);
            EnQueue(&Q, i);
            While (!QueueEmpty(Q)){
                DeQueue(&Q, &i);
                p = GL->adjList[i].firstedge;
                while (p){
                    if (!visited[p->adjvex]){
                        visited[p->adjvex] = TRUE;
                        printf('%c', GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }    
}

void BSFTraversematrix(MGraph G){
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q);
    for (i = 0; i < G.numVertexes; i++){
        if (!visited[i]){
            visited[i] = TRUE;
            printf('%c', G.vexs[i]);
            EnQueue(&Q, i);
            while (!QueueEmpty(Q)){
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++){
                    if (G.arc[i][j] == INFINITY && !visited[j]){
                        visited[j] = TRUE;
                        printf('%c', G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }                                 
            }
        }
    }
}