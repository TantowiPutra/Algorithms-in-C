            if(!visited[v] && adj_mat[top.second][v] != INT_MAX) {
                pq.push({adj_mat[top.second][v], v});
            }
        }