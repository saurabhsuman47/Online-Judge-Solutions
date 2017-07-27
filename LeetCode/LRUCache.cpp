#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
private:
	list<int> lru_queue;  // queue structure (mru -> lru), dll
	unordered_map<int, pair<int, list<int>::iterator>> cache;

	//moves the item pointed by iterator to front of the queue
	void bringToFront(list <int>::iterator it){
		int item = *it;
		lru_queue.erase(it);
		lru_queue.push_front(item);
	}

public:
	
	int capacity;
	LRUCache(int _capacity){
		capacity = _capacity;
	}

	//return value if found else -1, modifyqueue
	int get(int key){
		auto it = cache.find(key);
		if(it == cache.end()){
			return -1;
		}
		bringToFront(it->second.second);
		list<int>::iterator it_lru_queue_start = lru_queue.begin();
		it->second.second = it_lru_queue_start;
		return it->second.first;
	}

	//add key value pair to cache if it does not already exist and modify queue
	void put(int key, int value){
		if(get(key) != -1){
            auto it = cache.find(key);
            it->second.first = value;
            return;
        } 
		//full capacity reached, evict the least recently used
		if(lru_queue.size() >= capacity){
			cache.erase(lru_queue.back());
			lru_queue.pop_back();
		}
		lru_queue.push_front(key);
		pair<int, list<int>::iterator> pili = make_pair(value, lru_queue.begin());		
		cache.insert(make_pair(key, pili));

	}

};

int main(){

	LRUCache *cache = new LRUCache(2);
	cache->put(1,1);
	cache->put(2,2);
	cout<<cache->get(1)<<endl;
	cache->put(3,3);
	cout<<cache->get(2)<<endl;
	cout<<cache->get(3)<<endl;
	cache->put(4,4);
	cout<<cache->get(3)<<endl;
	cout<<cache->get(4)<<endl;
	cout<<cache->get(1)<<endl;
	
	// LRUCache cache = LRUCache(3);
	// cache.put(1,1);
	// cout<<cache.capacity<<endl;


}