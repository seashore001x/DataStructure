typedef int Boolean;
Boolean visited[MAX]

/* main body */
void DFSTraverse(GraphAdjList GL){
    int i;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    for (i = 0; i < GL->numVertexes; i++)
        if(!visited[i])
            DFSlist(GL, i)
            /* or using DFSmatrix(G, i) */
}

/* using the adjacent list */
void DFSlist(GraphAdjList GL, int i){
    EdgeNode *p;
    visited[i] = TRUE;
    printf('%c', GL->adjList[i].data);
    p = GL->adjList[i].firstedge
    while(p){
        if (!visited[p->adjvex])
            DFS(GL, p->adjvex);
        p = p->next;
    }
}

/* using the adjacent matrix */
void DFSmatrix(MGraph G, int i){
    int j;
    visited[i] = TRUE;
    printf('%c', G.vexs[i]);
    for (j = 0; j < G.numVertexes; j++){
        if(G.arc[i][j] != INFINITY && !visited[j])
            DFS(G, j);
    }
}