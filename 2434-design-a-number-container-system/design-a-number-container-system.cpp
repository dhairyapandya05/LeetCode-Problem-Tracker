class NumberContainers {
private:
    map<int, set<int>> mpq; // Map to store number and its indices
    map<int,int> mp; // Map to store index and number
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // If the index already has a number
        if(mp.find(index) != mp.end())
        {
            int prevNumber = mp[index];
            // If the new number is the same as the previous, do nothing
            if(prevNumber == number)
                return;
            // Remove the index from the set of the previous number
            if(mpq.find(prevNumber) != mpq.end())
            {
                mpq[prevNumber].erase(index);
                // If the set becomes empty, remove the number from the map
                if(mpq[prevNumber].empty()) mpq.erase(prevNumber);
            }
        }
        // Update the index with the new number
        mp[index] = number;
        // Add the index to the set of the new number
        mpq[number].insert(index);
    }
    
    int find(int number) {
        // If the number exists and has indices
        if(mpq.find(number) != mpq.end() && !mpq[number].empty())
            // Return the smallest index
            return *(mpq[number].begin());
        // Otherwise, return -1
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */