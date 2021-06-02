from collections import defaultdict


class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.Time = 0
        self.last_reached = 0

    def addBridge(self, u, v):
        self.graph[u].append(v)

    def removeBridge(self, u, v):
        for index, key in enumerate(self.graph[u]):
            if key == v:
                self.graph[u].pop(index)
        for index, key in enumerate(self.graph[v]):
            if key == u:
                self.graph[v].pop(index)

    def DFSCount(self, v, visited):
        count = 1
        visited[v] = True
        for i in self.graph[v]:
            if visited[i] == False:
                count = count + self.DFSCount(i, visited)
        return count

    def isNextEdgeValid(self, u, v):
        if len(self.graph[u]) == 1:
            return True
        else:
            visited = [False] * (self.V)
            count1 = self.DFSCount(u, visited)
            self.removeBridge(u, v)
            visited = [False] * (self.V)
            count2 = self.DFSCount(u, visited)
            self.addBridge(u, v)
            return False if count1 > count2 else True

    def travel(self, u):
        self.last_reached = u
        for v in self.graph[u]:
            if self.isNextEdgeValid(u, v):

                print("%d-%d " % (u, v)),
                self.removeBridge(u, v)
                self.travel(v)

    def printPath(self):
        u = 0
        for i in range(self.V):
            if len(self.graph[i]) % 2 != 0:
                u = i
                break
        print("\n")
        self.travel(u)
        if not u == self.last_reached:
            print(
                "we made the tour across all the landmasses \nwe could not comeback to where we started off :("
            )
        else:
            print(
                "we made the tour across all the landmasses \nwe have come back to where we started off :)"
            )


print("\n")
print("******** 17ETS002124 K Srikanth ********")
g1 = Graph(4)
g1.addBridge(0, 1)
g1.addBridge(0, 2)
g1.addBridge(1, 2)
g1.addBridge(2, 3)
print("\n")
print("******** this is the path ******** ")
g1.printPath()

g2 = Graph(3)
g2.addBridge(0, 1)
g2.addBridge(1, 2)
g2.addBridge(2, 0)
print("\n")
print("******** this is the circuit ******** ")
g2.printPath()
