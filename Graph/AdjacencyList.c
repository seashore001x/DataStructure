/* node definition */
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next; /* point to the next edgenode */
} EdgeNode;

typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge; /* point to the first edgenode */
} VertexNode, AdjList[MAXVEX]; /* array to store the VertexNode */

typedef struct{
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;


/* creat an adjacency list */
void CreatALGraph(GraphAdjList *G){
    int i, j, k,;
    EdgeNode *e;
    printf('Input the number of vertexes and edges:\n');
    scanf('%d, %d', &G->numVertexes, &G->numEdges);

    /* import vertex imformation and create vertexnode */
    for (i = 0; i < G->numVertexes; i++){
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge = NULL; /* G->adjList等效于(*G).adjList */
    }
    /* build the edgenode */
    for (k = 0; k < G->numEdges; k ++){
        printf('input vertex number of edge(vi, vj)');
        scanf('%d, %d', &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* when the adjacent vertex is j */
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        /* when the adjacent vertex is i */
        e->adjvex = i;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e
        }
    }
}
/* for n vertexes and e edges, the time complexity is O(n+e) */