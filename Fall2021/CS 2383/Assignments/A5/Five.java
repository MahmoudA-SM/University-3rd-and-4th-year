vertices[G.size()] array;
Algorithm cycleDFS(G, v)
    setLabel(v, VISITED)
    S.push(v)
    for all  e in G.incidentEdges(v)
        if  getLabel(e) UNEXPLORED
            w  opposite(v,e)
            S.push(e)
            if getLabel(w) UNEXPLORED
            setLabel(e, DISCOVERY)
            cycleDFS(G, w)
            S.pop(e)
        else
            T <- new empty stack
            repeat
                o <- S.pop()

                T.push(o)
            until o = w
            return T.elements()
    S.pop(v)