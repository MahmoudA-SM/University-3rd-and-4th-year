Algorithm DFS(graph,start)
input: Graph graph, vertex start

DFS (graph, start):                                   
      let stackvar be stack
      stackvar.push( start )            //stackvar is a stack variable. Pushing start in stack 
      mark start as visited.
      while ( stackvar is not empty):
          vertex  =  stackvar.top( )
          stackvar.pop( )
          for all neighbours nb of vertex in Graph graph:
             if nb is not visited then
                    stackvar.push( nb )         
                    mark nb as visited
