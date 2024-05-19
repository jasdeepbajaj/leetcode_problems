from queue import PriorityQueue

def move(i,j,n):
        # possible_new_cells = []
        directions = [(0,1), (1,0), (0,-1),(-1,0)]
        for dx, dy in directions:
            new_pos = i+dx, j+dy
            if (0<=new_pos[0]<n) and (0<=new_pos[1]<n):
                # possible_new_cells.append(new_pos)
                yield new_pos
        #  possible_new_cells

class Solution: 
    

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)

        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return 0

        dist = [[float('inf')] * n for i in range(n)]

        q = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    q.append((i,j))
                    dist[i][j] = 0

        while q:
            i, j  = q.popleft()
            for new_cell in move(i,j, n):
                if dist[new_cell[0]][new_cell[1]] == float('inf'):
                    dist[new_cell[0]][new_cell[1]]  = dist[i][j] + 1
                    q.append(new_cell)

        pq = []
        heappush(pq,(-dist[0][0], 0,0))
        # queue = PriorityQueue()
        # queue.put((-dist[0][0], 0,0))
        # searched_nodes = []
        visited = set()
        while pq:
        # while not queue.empty():
            # dis, i, j = queue.get()
            dis, i, j = heappop(pq)
            dis = -dis
            if (i, j) in visited:
                continue
            visited.add((i,j)) 

            if i == n-1 and j == n-1:
                return dis

            for new_cell in move(i,j, n):
                
                if new_cell not in visited:
                    # queue.put((-min(dis, dist[new_cell[0]][new_cell[1]]), new_cell[0], new_cell[1]))
                    heappush(pq,(-min(dis, dist[new_cell[0]][new_cell[1]]), new_cell[0], new_cell[1]))