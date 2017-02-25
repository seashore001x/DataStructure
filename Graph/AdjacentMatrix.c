/* node definition */
typedef char Vertextype;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

/* create an undirected adjacent matrix */
Void CreateMGraph(MGraph *G){
    int i, j, k, w;
    printf('input number of vertexs and edges:\n');
    scanf('%d, %d', &G->numVertexes, &G->numEdges);
    /* build vertexnode list */
    for (i = 0; i < G->numVertexes; i++)
        scanf(&G->vexs[i]);
    /* initiate adjacent matrix */
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;
    /* read edges, build adjacent matrix */
    for (k = 0; k < G->numEdges; k++){
        printf('input the superscript, subscript and weight of edges');
        scanf('%d, %d, %d', &i, &j, &w);
        G->arc[i][j] = w;
        /* the undirected matrix is symmetrical */
        G->arc[j][i] = G->arc[i][j];
    }
}