class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        unordered_map<int, int> vertex_gp;
        unordered_map<int, set<int>> gp_vertices;

        for (vector<int> edge : edges) {
            int v1 = edge[0];
            int v2 = edge[1];
            
            bool v1_exists = vertex_gp.find(v1) != vertex_gp.end();
            int v2_exists = vertex_gp.find(v2) != vertex_gp.end();

            if (!v1_exists && !v2_exists) {
                int gp = min(v1, v2);
                vertex_gp[v1] = gp;
                vertex_gp[v2] = gp;
                gp_vertices[gp] = set<int>({v1, v2});
            } else if (!v1_exists && v2_exists) {
                int gp = vertex_gp[v2];
                vertex_gp[v1] = gp;
                gp_vertices[gp].insert(v1);
            } else if (v1_exists && !v2_exists) {
                int gp = vertex_gp[v1];
                vertex_gp[v2] = gp;
                gp_vertices[gp].insert(v2);
            } else {
                int gp1 = vertex_gp[v1];
                int gp2 = vertex_gp[v2];
                if (gp1 == gp2) {
                    continue;
                }
                // merge gp2 into gp1
                set<int>::iterator iter;
                for (iter = gp_vertices[gp2].begin(); iter != gp_vertices[gp2].end(); iter++) {
                    gp_vertices[gp1].insert(*iter);
                    vertex_gp[*iter] = gp1;
                }
                gp_vertices.erase(gp2);
            }

            // Check source-destination path existence
            int s_exists = vertex_gp.find(source) != vertex_gp.end();
            int d_exists = vertex_gp.find(destination) != vertex_gp.end();
            if (s_exists && d_exists) {
                if (vertex_gp[source] == vertex_gp[destination]) {
                    return true;
                }
            }
        }

        return false;
    }
};
