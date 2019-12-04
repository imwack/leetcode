#pragma once
class LRUCache
{
	unordered_map<int, pair<int, int>> map;
	list<pair<int, int>> element;
	int count;
public:
	LRUCache(int capacity) {
		count = capacity;
	}

	int get(int key) {
		if(map.find(key)!=map.end())
		{
			int value = map[key].second;
			element.remove(map[key]);
			pair<int, int> p(key, value);
			element.push_back(p);
			map[key] = p;
			return value;
		}
		return -1;
	}

	void put(int key, int value) 
	{
		if (map.find(key) != map.end())
		{
			element.remove(map[key]);
			pair<int, int> p(key, value);
			element.push_back(p);
			map[key] = p;
		}
		else
		{
			if(count == element.size())
			{
				//FULL
				auto pair = element.front();
				map.erase(pair.first);
				element.pop_front();
			}
			pair<int, int> p(key, value);
			element.push_back(p);
			map[key] = p;
		}
	}
	LRUCache();
	~LRUCache();
};

