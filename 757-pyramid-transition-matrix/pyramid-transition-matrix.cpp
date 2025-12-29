class Solution {
public:
	unordered_map<string, vector<char>> mp;
	unordered_map<string, bool> memo;
	
	bool DFS(string row){
		if (row.size() == 1){
			return true;
		}
		
		if (memo.count(row)){
			return memo[row];
		}
		
		string next_row = "";
		bool ret = buildNext(row, next_row, 0);
		memo[row] = ret;
		return ret;
	}
	
	bool buildNext(string& row, string& next_row, int idx){
		if (next_row.size() == row.size()-1){
			return DFS(next_row);
		}
		
		string key = row.substr(idx,2);
		if (!mp.count(key)){
			return false;
		}
		
		for (char c: mp[key]){
			next_row.push_back(c);
			if (buildNext(row, next_row, idx+1)){
				return true;
			}
			next_row.pop_back();
		}
		return false;
	}

    bool pyramidTransition(string bottom, vector<string>& allowed) {
		for (auto& s:allowed){
			mp[s.substr(0, 2)].push_back(s[2]);
		}
		return DFS(bottom);
    }
};