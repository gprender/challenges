/**
 * Given an (n x n) maze, decide if it can be solved by starting in the top left.
 * The maze may contain walls, indicate by a W character in the input string.
 * 
 * Pretty standard maze solving question, but who doesn't love graph algorithms??
 */

#include <unordered_set>
#include <queue>
#include <string>

std::vector<int> adj(int pos, std::string maze, int n) {
  std::vector<int> neighbours;
  
  // west + east neighbours; these are adjacent in the string
  if ((pos % n) && (maze[pos-1] != 'W')) neighbours.push_back(pos-1);
  if (((pos % n) != (n-1)) && (maze[pos+1] != 'W')) neighbours.push_back(pos+1);
  
  // north + south neighbours; change in pos depends on the n
  if ((pos >= n) && (maze[pos-n] != 'W')) neighbours.push_back(pos-n);
  if ((pos < (n*n)-n) && (maze[pos+n] != 'W')) neighbours.push_back(pos+n);
  
  return neighbours;
}

bool path_finder(std::string maze) {
  int n = maze.find("\n");
  int goal = (n * n) - 1;
  
  // create a copy of the maze without newlines - should be its own function
  std::string simplified_maze(maze);
  size_t found = simplified_maze.find("\n");
  while (found != std::string::npos) {
    simplified_maze.replace(found,1,"");
    found = simplified_maze.find("\n");
  }
  
  std::unordered_set<int> visited({0});
  std::queue<int> q({0});
  
  // BFS!
  while (!q.empty() && q.front() != goal) {
    int pos = q.front();
    q.pop();
    
    for (auto const e : adj(pos, simplified_maze, n)) {
      if (!visited.count(e)) {
        visited.insert(e);
        q.push(e);
      }
    }
  }
  return !q.empty();
}
