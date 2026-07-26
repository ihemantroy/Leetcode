class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> dict;

    void backtrack(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string &p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        dict = unordered_set<string>(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int sz = q.size();
            unordered_set<string> levelVisited;

            while (sz--) {

                string word = q.front();
                q.pop();

                string original = word;

                for (int i = 0; i < word.size(); i++) {

                    char old = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        word[i] = c;

                        if (!dict.count(word))
                            continue;

                        if (!visited.count(word)) {

                            if (!levelVisited.count(word)) {
                                q.push(word);
                                levelVisited.insert(word);
                            }

                            parent[word].push_back(original);

                            if (word == endWord)
                                found = true;
                        }
                    }

                    word[i] = old;
                }
            }

            for (auto &w : levelVisited)
                visited.insert(w);
        }

        if (!found)
            return {};

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, path);

        return ans;
    }
};