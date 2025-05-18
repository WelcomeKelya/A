public class graphColoring {

    static final int V = 4; // Number of vertices

    // Check if the current color assignment is safe for vertex
    static boolean isSafe(int v, int[] color, boolean[][] graph, int c) {
        for (int i = 0; i < V; i++) {
            if (graph[v][i] && color[i] == c)
                return false;
        }
        return true;
    }

    // Recursive utility to solve m-coloring problem
    static boolean graphColoringUtil(boolean[][] graph, int m, int[] color, int v) {
        if (v == V)
            return true;

        for (int c = 1; c <= m; c++) {
            if (isSafe(v, color, graph, c)) {
                color[v] = c;
                if (graphColoringUtil(graph, m, color, v + 1))
                    return true;
                color[v] = 0; // Backtrack
            }
        }
        return false;
    }

    // Main function to solve the graph coloring problem
    static boolean graphColoring(boolean[][] graph, int m) {
        int[] color = new int[V];

        if (!graphColoringUtil(graph, m, color, 0)) {
            System.out.println("Solution does not exist.");
            return false;
        }

        // Print the solution
        System.out.println("Solution Exists: Colors assigned to vertices:");
        for (int c : color)
            System.out.print(c + " ");
        System.out.println();
        return true;
    }

    // Driver code
    public static void main(String[] args) {
        // Example graph as adjacency matrix
        boolean[][] graph = {
            {false, true, true, true},
            {true, false, true, false},
            {true, true, false, true},
            {true, false, true, false}
        };

        int m = 3; // Number of colors
        graphColoring(graph, m);
    }
}
