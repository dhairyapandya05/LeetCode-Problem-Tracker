class Solution {
public:
    int bfs(int node, int parent_node, vector<vector<int>>& reversed)
    {
        queue<pair<int, int>> q;
        q.push({node, 0});
        int max_length = 0;

        while(!q.empty())
        {
            int node = q.front().first;
            int length = q.front().second;
            max_length = max(max_length, length);
            q.pop();
            for(auto adj_node : reversed[node])
            {
                if(adj_node == parent_node) continue;
                q.push({adj_node, length + 1});
            }
        }

        return max_length;

    }
    int maximumInvitations(vector<int>& favorite) {
        /*
            1. Every connected component has exactly one cycle.
            2. components with a cycle length of 2 forms a nonclosed circle.
               So they can be connected to other nonclosed circles. In this component
               we have to consider, longest path that forms non closed circle.
            3. components with a cycle length > 2 forms a closed circle.
                so they can not be connected to other closed circles. So in this
                case the longest path of the cycle would be the answer.

            Hence, the answer is max(sum of all longest paths of nonclosed circles, longest path of closed circle).
        */
        
        int longest_path = 0, n = favorite.size();
        vector<bool> vis(n, false);
        vector<pair<int, int>> cycle_2_nodes;

        // components with a cycle length > 2.
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                int start_node = i, curr_node = i;
                unordered_set<int> stack;
                while(!vis[curr_node])
                {
                    vis[curr_node] = true;
                    stack.insert(curr_node);
                    curr_node = favorite[curr_node];
                }
                if(stack.count(curr_node) > 0)
                {
                    int length = stack.size();
                    while(start_node != curr_node)
                    {
                        length -= 1;
                        start_node = favorite[start_node];
                    }
                    longest_path = max(longest_path, length);
                    if(length == 2) 
                        cycle_2_nodes.push_back({curr_node, favorite[curr_node]});
                }   
            }
        }

        int sum_2_length_cycles = 0;
        vector<vector<int>> reversed(n);
        for(int i = 0; i < n; i++)
        {
            reversed[favorite[i]].push_back(i);
        }
        // components with cycle length 2.
        for(auto it : cycle_2_nodes)
        {
            int node1 = it.first, node2 = it.second;
            sum_2_length_cycles += bfs(node1, node2, reversed) + bfs(node2, node1, reversed);
            // including it.first and it.second nodes.
            sum_2_length_cycles += 2;
        }
        

        return max(longest_path, sum_2_length_cycles);
    }
};