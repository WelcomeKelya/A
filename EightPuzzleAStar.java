import java.util.*;

public class EightPuzzleAStar {

    static class State {
        int[][] board;
        int g; // Cost from start to current
        int h; // Heuristic (misplaced tiles)
        int blankRow, blankCol;
        State parent;

        public State(int[][] b, int g, State parent) {
            this.board = new int[3][3];
            this.g = g;
            this.parent = parent;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this.board[i][j] = b[i][j];
                    if (b[i][j] == 0) {
                        blankRow = i;
                        blankCol = j;
                    }
                }
            }
            this.h = calculateHeuristic();
        }

        // Heuristic: Number of misplaced tiles
        private int calculateHeuristic() {
            int[][] goal = {
                {1, 2, 3},
                {8, 0, 4},
                {7, 6, 5}
            };
            int misplaced = 0;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] != 0 && board[i][j] != goal[i][j])
                        misplaced++;
            return misplaced;
        }

        public boolean isGoal() {
            int[][] goal = {
                {1, 2, 3},
                {8, 0, 4},
                {7, 6, 5}
            };
            return Arrays.deepEquals(board, goal);
        }

        public List<State> getNeighbors() {
            List<State> neighbors = new ArrayList<>();
            int[][] directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // up, down, left, right

            for (int[] dir : directions) {
                int newRow = blankRow + dir[0];
                int newCol = blankCol + dir[1];
                if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
                    int[][] newBoard = deepCopy(board);
                    newBoard[blankRow][blankCol] = newBoard[newRow][newCol];
                    newBoard[newRow][newCol] = 0;
                    neighbors.add(new State(newBoard, g + 1, this));
                }
            }
            return neighbors;
        }

        // For PriorityQueue (based on f(n) = g + h)
        public int getF() {
            return g + h;
        }

        // Convert board to a unique string
        public String boardToString() {
            StringBuilder sb = new StringBuilder();
            for (int[] row : board)
                for (int val : row)
                    sb.append(val);
            return sb.toString();
        }

        private int[][] deepCopy(int[][] src) {
            int[][] copy = new int[3][3];
            for (int i = 0; i < 3; i++)
                copy[i] = Arrays.copyOf(src[i], 3);
            return copy;
        }
    }

    public static void aStarSearch(int[][] initialBoard) {
        PriorityQueue<State> pq = new PriorityQueue<>(Comparator.comparingInt(State::getF));
        Set<String> visited = new HashSet<>();

        State start = new State(initialBoard, 0, null);
        pq.add(start);

        while (!pq.isEmpty()) {
            State current = pq.poll();
            if (current.isGoal()) {
                printPath(current);
                return;
            }

            visited.add(current.boardToString());

            for (State neighbor : current.getNeighbors()) {
                if (!visited.contains(neighbor.boardToString())) {
                    pq.add(neighbor);
                }
            }
        }

        System.out.println("No solution found.");
    }

    private static void printPath(State state) {
        List<State> path = new ArrayList<>();
        while (state != null) {
            path.add(state);
            state = state.parent;
        }
        Collections.reverse(path);
        for (State s : path) {
            printBoard(s.board);
            System.out.println("g(n)=" + s.g + ", h(n)=" + s.h + ", f(n)=" + (s.g + s.h));
            System.out.println();
        }
    }

    private static void printBoard(int[][] board) {
        for (int[] row : board) {
            for (int val : row)
                System.out.print((val == 0 ? " " : val) + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] initialBoard = {
            {2, 8, 3},
            {1, 6, 4},
            {7, 0, 5}
        };

        aStarSearch(initialBoard);
    }
}