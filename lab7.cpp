#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Graph {
    int numVertices;
    vector<vector<int>> adjacencyMatrix;
};

Graph read(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return { 0, {} };
    }

    int numVertices;
    inputFile >> numVertices;

    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));
    int u, v;

    while (inputFile >> u >> v) {
        adjacencyMatrix[u][v] = 1;
    }

    inputFile.close();

    return { numVertices, adjacencyMatrix };
}

void displayAdjacencyMatrix(const Graph& graph) {
    for (const auto& row : graph.adjacencyMatrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
vector<int> calculateDegrees(const vector<vector<int>>& adjacencyMatrix) {
    int numVertices = adjacencyMatrix.size();
    vector<int> degrees(numVertices, 0);

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            degrees[i] += adjacencyMatrix[i][j];
        }
    }

    return degrees;
}

void displayDegrees(const vector<int>& degrees) {
    for (int i = 0; i < degrees.size(); ++i) {
        cout << "Degree of Node " << i << ": " << degrees[i] << endl;
    }
}

void dfs_(const Graph& graph, int currentNode, vector<bool>& visited) {
    cout << currentNode << " ";
    visited[currentNode] = true;

    for (int i = 0; i < graph.numVertices; ++i) {
        if (graph.adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
            dfs_(graph, i, visited);
        }
    }
}

void dfs(const Graph& graph, int startNode) {
    vector<bool> visited(graph.numVertices, false);
    dfs_(graph, startNode, visited);
}

void bfs(const Graph& graph, int startNode) {
    int numVertices = graph.numVertices;
    vector<bool> visited(numVertices, false);
    vector<int> queue;
    int front = 0, r= 0;

    queue.push_back(startNode);
    visited[startNode] = true;

    while (front <= r) {
        int currentNode = queue[front++];
        cout << currentNode << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (graph.adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                queue.push_back(i);
                visited[i] = true;
                r++;
            }
        }
    }
}

int main()
{
    string filename = "C:\\Users\\nhorg\\Desktop\\teme\\SD\\input.txt";
    Graph graph = read(filename);

    cout << "Adjacency Matrix:" << endl;
    displayAdjacencyMatrix(graph);
    cout << endl;

    vector<int> degrees = calculateDegrees(graph.adjacencyMatrix);
    cout << "Degrees:" << endl;
    displayDegrees(degrees);

    cout << endl;
    cout << "DFS Traversal: ";
    dfs(graph, 0);
    cout << endl;

    cout << "BFS Traversal: ";
    bfs(graph, 2);

    return 0;
}

