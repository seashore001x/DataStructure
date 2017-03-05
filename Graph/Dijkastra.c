#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX]
typedef int ShortPathTable[MAXVEX]

void ShortestPath_Dijstra(MGraph G, init source, Patharc *P, ShortPathTable *D){
    int v, w, k, min;
    int final[MAXVEX];
    
    /* data initilization */
    for (v = 0; v < G.numVertexes; v++){
        final[v] = 0;   // all nodes are unvisited
        (*D)[v] = G.arc[source][v]; // the distance from node to source, the distance of non-adjacent node in adjacent matrix are defined as INFINITY
        (*P)[v] = -1;
    }

    (*D)[source] = 0;   // the distance of source is zero
    final[source] = 1;  //source has been visited

    /* begin the main loop, calculate the distance between source and vertex v in each loop */
    for (v = 1; v < G.numVertexes; v++){
        min = INFINITY;

        /* looking for the nearest node to source */
        for (w = 0; w < G.numVertexes; w++){
            if (!final[w] && (*D)[w] < min){
                k = w;
                min = (*D)[w];
            }
        }

        final[k] = 1;   // set the nearest node as visited

        for (w = 0; w < G.numVertexes; w++){
            if (!final[w] && (min + G.arc[k][w] < (*D)[w])){
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}
