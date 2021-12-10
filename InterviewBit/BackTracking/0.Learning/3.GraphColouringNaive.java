public class InterviewBit{
    private static boolean isSafeToColor(int[][] graph, int[] color)
    {
        // check for every edge, if any adjacent edge has same color, return false
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (graph[i][j] == 1 && color[j] == color[i])
                    return false;
        return true;
    }
    
    private static void printColorArray(int[] color){
        System.out.println("Solution colors are: ");
        for(int i =0;i < color.length; i++){
            System.out.println(color[i]);
        }
    }

    /**
    * returns false if the m colors cannot be assigned, else, 
    * return true and print assignments of colors to all vertices.
    * Note: There may be more than one solutions
    * The function prints only one of the solutions.
    * */
    private static boolean graphColoring(int[][] graph, int m, int i, int[] color)
    {
        // if current index becomes end
        if (i == V) {
            // check whether its safe to color
            if (isSafeToColor(graph, color)) {
                //If safe, print solution array and return true
                printColorArray(color);
                return true;
            }
            return false;
        }

        // Assign each color from 1 to m
        for (int j = 1; j <= m; j++) {
            color[i] = j;

            // Check for the rest vertices by recursion
            if (graphColoring(graph, m, i + 1, color))
                return true;

            color[i] = 0;
        }

        return false;
    }
}