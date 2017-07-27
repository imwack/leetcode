
class Trie {
	bool isEnd = false; // 是否是结尾
	Trie *child[26] = {}; //子节点
public:
	void Insert(string word, int pos) {
		if (pos == word.size()) {
			isEnd = true;
			return;
		}
		int index = word[pos] - 'a';
		if (child[index] == nullptr) {
			child[index] = new Trie();
		}
		child[index]->Insert(word, pos + 1);
	}
	//若是开头 则返回开头的串，否则返回原串
	string isStartWith(string word, int pos) {
		if (pos == word.size()) {
			return word;
		}
		int index = word[pos] - 'a';
		if (child[index] == nullptr) return word;
		else if (child[index]->isEnd) 
			return word.substr(0, pos+1);
		else
			return child[index]->isStartWith(word, pos + 1);
	}
};
class Solution {
public:
string replaceWords(vector<string>& dict, string sentence) {
	Trie root;
	string ret;
	for (string word : dict) {
		root.Insert(word,0);
	}
	stringstream ss;
	ss << sentence;
	string word;
	while (ss>>word)
	{
		if(ret.size())
			ret+=" "+ root.isStartWith(word,0);
		else
			ret+= root.isStartWith(word, 0);
	}
	return ret;
}
};
