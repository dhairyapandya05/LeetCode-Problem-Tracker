class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        queue<int> q1;
        queue<int> q2;
        q1.push(node1);
        set<int>s1;
        set<int>s2;
        s1.insert(node1);
        s2.insert(node2);
        q2.push(node2);
        int level=0;
        int count=0;
        while (!q1.empty() and !q2.empty()) {
            int N = max(q1.size(), q2.size());
            if(count>=100000) return -1;
            while (N--) {
                count++;
                auto temp1 = q1.front();
                q1.pop();
                auto temp2 = q2.front();
                q2.pop();
                s1.insert(temp1);
                s2.insert(temp2);
                if(temp1<temp2){
if(s2.find(temp1)!=s2.end()) return temp1;
if(s1.find(temp2)!=s1.end()) return temp2;
                }
                else{
if(s1.find(temp2)!=s1.end()) return temp2;

if(s2.find(temp1)!=s2.end()) return temp1;
                }
                
                
                if (edges[temp1] == -1)
                    q1.push(temp1);
                else
                    q1.push(edges[temp1]);
                if (edges[temp2] == -1)
                    q2.push(temp2);
                else
                    q2.push(edges[temp2]);
            }
            level++;
        }
        return -1;
    }
};