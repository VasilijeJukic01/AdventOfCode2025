# Advent of Code 2025 🎄

My solutions for Advent of Code 2025.

## Diary

### Day 1: Rotations
- **The Vibe:** Easy start.
- **Tech:** String parsing, Modulo Arithmetic.
- **Thoughts:** *Nice warm-up. The only trick was handling negative results modulo operations. `((a % n) + n) % n` saves lives.*

### Day 2: ID Validation
- **The Vibe:** I actually have to think for part 2 xD?
- **Tech:** Sliding Window.
- **Thoughts:** *Part 1 was a simple loop. Part 2 looked scary until I realized that it is just a sliding window.*

### Day 3: Greedy Optimization
- **The Vibe:** Maximize everything.
- **Tech:** Greedy.
- **Thoughts:** *Pure greedy logic. Find the biggest number, move it to the front.*

### Day 4: Grid Traversal
- **The Vibe:** Fun until you have an indexing error.
- **Tech:** 2D Arrays, BFS.
- **Thoughts:** *Used a queue to cascade the updates across the grid. Debugging grids is always a pain because I must print everything...*

### Day 5: Interval Merging
- **The Vibe:** A classic interview question.
- **Tech:** Merge Intervals, Binary Search.
- **Thoughts:** *Felt smart here. Sorted the ranges, merged the overlaps and then binary searched the IDs :D.*

### Day 6: Columnar Parsing
- **The Vibe:** Why is the input vertical!? Who writes math like this? -.-
- **Tech:** Complex String Parsing!
- **Thoughts:** *The algorithm wasn't hard, but parsing columns was the real boss fight today. Also, writing this in C++ is a pain :(.*

### Day 7: Path Counting
- **The Vibe:** My stack overflowed.
- **Tech:** DFS + DP (Memoization).
- **Thoughts:** *Part 1 was easy with a stack. Part 2 exploded my recursion depth, so I had to implement memoization to cache the results.*

### Day 8: Clustering & MST
- **The Vibe:** I am a Graph wizard.
- **Tech:** Union-Find + Kruskal.
- **Thoughts:** *Okay problem. Merging 3D points based on distance felt really satisfying. Part 2 was basically finding a Minimum Spanning Tree.*

### Day 9: Computational Geometry
- **The Vibe:** I hate Geometry! I hate Ray Casting! Bring back the graphs!!!
- **Tech:** Coordinate Geometry, Ray Casting Algorithm.
- **Thoughts:**  *This was heavy. To check if a rectangle center was inside a polygon, I needed a way to determine it. I didn't even know an algorithm for this existed! I discovered Ray Casting on the fly. You draw an imaginary line from the point and count how many times it intersects the polygon's edges. Odd number of hits = Inside. Even number of hits = Outside. My brain hurts, but now I know this technique forever.*

### Day 10: Constraint Solving
- **The Vibe:** WTF IS THIS PROBLEM :'(((.
- **Tech:** C++ Brute Force -> Python Z3 Linear Programming.
- **Thoughts:** *Part 1 was fine with bitmasks. Part 2 was impossible to brute force because the combinations exploded. This was a rollercoaster. It looked like a graph problem. I started in C++, throwing standard BFS and DFS at it, thinking I just needed to find the right path of button presses. I hit a hard limit. The search space was way too massive, and my algorithms crashed. I found out this type of problem is called Linear Programming. I have literally never encountered that in my life. I actually tried doing manual Gauss-Jordan elimination to solve it. It worked for finding a solution, but I got stuck on the requirement to find the minimal total presses. I switched to Python and used the Z3 solver.*

### Day 11: Graph Search with State
- **The Vibe:** Tricky, but much easier with detailed drawing of the graph.
- **Tech:** DFS with State Bitmasks.
- **Thoughts:** *A classic traversal, but we had to visit specific nodes. I handled this by adding the current state into the memoization key.*

### Day 12: Tetris, Backtrack??
- **The Vibe:** Tetris from hell.
- **Tech:** Backtracking, Matrix Transformations, Pruning.
- **Thoughts:** *This was an absolute beast. Before I could even get to the logic, I spent a lot of time just fighting string parsing. Manually slicing strings to extract dimensions and shape IDs was painful. Once I finally got the data in, the actual logic hit me like a truck. I stared at my screen for hours watching my recursive function run forever. I honestly lost my mind and turn to the internet to figure out how to optimize the backtracking. The trick for handling identical pieces was a saviour, but I could not have come up with it alone. I am physically exhausted.*
