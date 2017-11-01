//2009 World Practice Problem D
//How many subtrees

#include <iostream>

using namespace std;

int graph[10][10];
bool DEBUG = false;

int treeCount(int i, int numNodes){

    int count = 1; // a tree that is just one node

    // count of links from first node
    int links = 0;
    for(int j = i+1; j < numNodes; j++){
        if(graph[i][j]) {
            links++;
        }
    }

    // number of one-level trees with first node
    int subtrees = 1;
    for(int i = 0; i < links; i++){
        subtrees *= 2;
    }
    
    count += subtrees-1;

    // go deeper
    for(int j = i+1; j < numNodes; j++){
        if(graph[i][j]) {
            count += subtrees/2 * (treeCount(j,numNodes)-1);
        }
    }
    if(DEBUG) cout << "i: " << i << " count: " << count << endl;
    return count;
}

int main(int c, char *arg[]){

    int numNodes;
    int thecase = 0;
    int count;

    cin >> numNodes;

    while(numNodes > 0) {
        thecase++;
        if(DEBUG) cout << "case: " << thecase << "nodes: " << numNodes << endl;

        // clear array
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                graph[i][j] = 0;

        // read data
        int n1, n2, max = 0;
        for(int i = 0; i < numNodes-1; i++){
            cin >> n1;
            cin >> n2;
            graph[n1][n2] = 1;
        }

        // check possible answers

        count = 0;
        for(int i = 0; i < numNodes; i++){
            count += treeCount(i, numNodes);
        }

        // produce output for the case

        cout << "Case " << thecase << ":" << " " << count << endl;
        
        // possibly a next case
        count = 0;
        cin >> numNodes;
    }
    return 0;
}
