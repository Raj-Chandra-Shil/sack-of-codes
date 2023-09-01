> # ```Shortest Path using BFS``` 
- Source -> level 0  
- Childs of the source or level 0 vertices -> level 1  
- Childs of level 0 vertice -> level 2  
- go on....


## Bellman-Ford algorithm 
> We have to relax all the nodes in the graph for |V| - 1 times (in worst case, in some  case if relaxation result doesn't change we can stop iterating the process)

The worst case could be happened on edge sequencing. 