import sys
input = sys.stdin.readline
INF = int(1e9)

n = int(input())
m = int(input())

def printGraph(graph):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if(graph[i][j] == INF):
                print(0, end=" ")
            else:
                print(graph[i][j], end=" ")
        print()

def floyd_warshall(graph):
    for k in range(1, n + 1):
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

graph = [[INF for i in range(n + 1)] for j in range(n + 1)]

for i in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = min(graph[a][b], c)

for i in range(1, n + 1):
    graph[i][i] = 0

floyd_warshall(graph)
printGraph(graph)