class WordGraph {
    // use adjacency list
public:
    int vertex_num;
    vector<vector<int> > adjacency_list;
    vector<string> values;
 
    void buildGraph(unordered_set<string> &wordList, string &beginWord) {
        // initial values
        int length = wordList.size();
        values.push_back(beginWord);
        for (string temp : wordList) {
            values.push_back(temp);
        }
 
 
        // build adjacency_list
        vertex_num = length + 1;
        adjacency_list.resize(vertex_num, vector<int>());
        for (int i = 0; i < vertex_num; i++) {
            for (int j = 0; j < vertex_num; j++) {
                if ((j != i) && (1 == getDistance(values[i], values[j]))) {
                    adjacency_list[i].push_back(j);
                }
            }
        }
    }
 
    int getShortestDistance(string &endWord) {
        // get endWord index
        int endWord_index = INT_MAX;
        for (int i = 0; i < vertex_num; i++) {
            if (0 == endWord.compare(values[i])) {
                endWord_index = i;
                break;
            }
        }
        if (INT_MAX == endWord_index) {
            return 0;
        }
 
        vector<int> shortestDistanceFromStartWord(vertex_num, INT_MAX - 1);
        vector<bool> isVisited(vertex_num, false);
        queue<int> q; q.push(0);
        shortestDistanceFromStartWord[0] = 1;
        int current_index = 0, adjacent_index = 0;
        while (!q.empty()) {
            current_index = q.front(); q.pop();
            if (true == isVisited[current_index]) {
                continue;
            }
 
            for (int i = 0; i < adjacency_list[current_index].size(); i++) {
                adjacent_index = adjacency_list[current_index][i];
                shortestDistanceFromStartWord[adjacent_index] = std::min(shortestDistanceFromStartWord[adjacent_index], shortestDistanceFromStartWord[current_index] + 1);
                q.push(adjacent_index);
            }
            isVisited[current_index] = true;
        }
 
        if (isVisited[endWord_index]) {
            return shortestDistanceFromStartWord[endWord_index];
        }
        else {
            return 0;
        }
    }
 
    // make sure that word1 and word2 hava the same length
    int getDistance(const string &word1, const string &word2) {
        int length = word1.length();
        int dist = 0;
        for (int i = 0; i < length; i++) {
            if (word1[i] != word2[i]) {
                dist++;
            }
 
            // optimization
            if (dist > 1) {
                break;
            }
        }
 
        return dist;
    }
};
 
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        WordGraph wg;
        wg.buildGraph(dict, start);
        return wg.getShortestDistance(end);
    }
};