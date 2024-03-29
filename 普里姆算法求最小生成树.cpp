/*白春辉*/
/*普里姆算法求最小生成树*/
/*2018.06.16*/


#include<stdio.h>      
#include<stdlib.h>     
#include<string.h>
#include<ctype.h>     
#define NOTEXIST -1    
#define BEGIN -1     
#define MAXVEX 100      
#define INFINITY 65535      
#define TRUE 1      
#define FALSE 0       
typedef int EdgeType;
typedef int VertexType;
int dist[MAXVEX];  //dist指 从 该点到被收录的各点中 距离的最小值   
typedef struct Graph 
{
	VertexType vex[MAXVEX];
	EdgeType edge[MAXVEX][MAXVEX];
	int vex_num, edge_num;
}Graph;



int get_pos(Graph g, int ch)
{
	int i;
	for (i = 0; i < g.vex_num; i++) 
	{
		if (g.vex[i] == ch)
			return i;
	}
	return -1;
}

void create_graph(Graph *g)
{
	int i, j, k;
	
	FILE *fp;
	fp = fopen("a.txt", "r");

	if (fp == NULL)
	{
		printf("fail");
		exit(0);
	}

	fclose(fp);
	fp = fopen("a.txt", "r");

	fscanf(fp, "%d	%d", &g->vex_num, &g->edge_num);
	fscanf(fp, "\n");

	printf("顶点数与边数为:");
	printf("%d	%d\n", g->vex_num, g->edge_num);


	for (i = 0; i < g->vex_num; i++) {
		for (j = 0; j < g->vex_num; j++) {
			if (i == j) {
				g->edge[i][j] = 0;
			}
			else
				g->edge[i][j] = INFINITY;
		}
	}
	
	
	for (i = 0; i < g->vex_num; i++) 
	{
		fscanf(fp, "%d", &g->vex[i]);
		fscanf(fp, "\n");
	}


	printf("顶点信息为:\n");
	for (i = 0; i < g->vex_num; i++)
	{
		printf("%d\n", g->vex[i]);
	}


	int c1, c2;
	int p1, p2, w;


	for (i = 0; i < g->edge_num; i++)
	{
		fscanf(fp, "%d	%d	%d", &c1,&c2,&w);
		fscanf(fp, "\n");

		printf("%d	%d	%d\n", c1, c2, w);

		p1 = get_pos(*g, c1);
		p2 = get_pos(*g, c2);
		g->edge[p1][p2] = w;//有向边的权重     
		g->edge[p2][p1] = w;
	}
	

	fclose(fp);


}


void Prim(Graph g, int start)
{
	int sum = 0;
	int index = 0;
	int i, j;
	int prims[MAXVEX];
	prims[index++] = g.vex[start];

	for (i = 0; i < g.vex_num; i++) {
		dist[i] = g.edge[start][i];
	}
	dist[start] = 0; //需要   
	int min, u, v;
	int pre;
	for (i = 0; i < g.vex_num; i++) {
		if (start == i)
			continue;
		min = INFINITY;
		for (j = 0; j < g.vex_num; j++) {
			if (dist[j] != 0 && dist[j] < min) {
				min = dist[j];
				u = j;
			}
		}
		if (dist[u] != 0)// not really needed anymore.   
			prims[index++] = g.vex[u];
		dist[u] = 0;
		for (v = 0; v < g.vex_num; v++) {
			if (dist[v] != 0 && g.edge[u][v] < dist[v])
				dist[v] = g.edge[u][v];
		}
	}
	for (i = 1; i < g.vex_num; i++) {
		min = INFINITY;//可以排除u v两点不存在边的情况   
		v = get_pos(g, prims[i]);
		for (j = 0; j < i; j++) {
			u = get_pos(g, prims[j]);
			if (g.edge[u][v] < min) {
				min = g.edge[u][v];
			}
		}
		sum += min;
	}

	printf("prim %d = %d\n", g.vex[start], sum);
	for (i = 0; i < index; i++) {
		printf("%d ", prims[i]);
	}

	printf("\n");
}

void print_graph(Graph g)
{
	int i, j;
	for (i = 0; i < g.vex_num; i++) {
		for (j = 0; j < g.vex_num; j++) {
			if (g.edge[i][j] == INFINITY)
				printf("%5d", '*');
			else {
				printf("%5d", g.edge[i][j]);
			}
		}
		printf("\n");
	}
}

int main()
{
	Graph g;
	int start, end;
	int c1;
	create_graph(&g);
	printf("请输入起始点:\n");
	scanf("%d", &c1);
	start = get_pos(g, c1);
	Prim(g, start);
	return 0;
}