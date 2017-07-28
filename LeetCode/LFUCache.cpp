#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache{
private:
	unordered_map<int, pair<int, int>> cache;					//key -> (value, freq)
	unordered_map<int, list<int>> freq_keylist_ht;				//freq -> list of keys
	unordered_map<int, list<int>::iterator> key_iterator_ht;	//key -> list iterator (to locate position in freq_keylist_ht)
	int capacity;
	int least_freq;
	
public:
	
	LFUCache(int _capacity){
		capacity = _capacity;
		least_freq = 1;
	}

	//return value if found else -1, modify hashtables
	int get(int key){
		auto it = cache.find(key);
		if(it == cache.end()){
			return -1;
		}

		int freq = it->second.second;							//get freq
		auto list_iterator = key_iterator_ht[key];				//get iterator for key
		freq_keylist_ht[freq].erase(list_iterator);				//remove key from prev key list
		//remove entry from frequency keylist hash table if list is empty
		if(freq_keylist_ht[freq].size() == 0){
			freq_keylist_ht.erase(freq);
		}
		//update least freq
		if(freq_keylist_ht.find(least_freq) == freq_keylist_ht.end()){
			least_freq++;
		}
		freq++;													//increment freq
		freq_keylist_ht[freq].push_front(key);					//add key to new key list
		key_iterator_ht[key] = freq_keylist_ht[freq].begin();	//change iterator for key
		it->second.second = freq;								//update freq
		return it->second.first;								//return value
	}

	//add key value pair to cache if it does not already exist and modify hash tables
	void put(int key, int value){
		
		if(get(key) != -1){
			auto it = cache.find(key);
            it->second.first = value;
            return;
        } 
		if(capacity == 0) return;								//dont do anything when capacity is 0
		//full capacity reached, evict the least frequently used
		if(cache.size() >= capacity){
			int evict_key = freq_keylist_ht[least_freq].back();
			cache.erase(evict_key);								//remove the key from cache
			freq_keylist_ht[least_freq].pop_back();				//remove the key from list corresponding to its freq from frequency-keylist hash table
			key_iterator_ht.erase(evict_key);					//remove the key from key-iterator hash table
		}

		freq_keylist_ht[1].push_front(key);						//add key to freqency keylist with freq 1(newly added will have frequency 1)
		auto pii = make_pair(value, 1);		
		cache.insert(make_pair(key, pii));						//add key, (value, freq) to cache
		key_iterator_ht[key] = freq_keylist_ht[1].begin();		//add iterator corresponding to key in frequncy-keylist hash table
		least_freq = 1;
	}

};

int main(){

	LFUCache *cache = new LFUCache(2);
	cache->put(1,1);
	cache->put(2,2);
	cout<<cache->get(2)<<endl;
	cache->put(3,3);
	cout<<cache->get(1)<<endl;
	cout<<cache->get(3)<<endl;
	cache->put(4,4);
	cout<<cache->get(3)<<endl;
	cout<<cache->get(4)<<endl;
	cout<<cache->get(1)<<endl;
	
	// LFUCache cache = LFUCache(3);
	// cache.put(1,1);
	// cout<<cache.capacity<<endl;


}