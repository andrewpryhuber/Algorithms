#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
private:
    list<int> history;
    unordered_map<int, int> hash;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (hash.find(key) != hash.end())
        {
            history.remove(key);
            history.push_front(key);
            return hash.find(key)->second;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        // if find key, update its value and put to most recent
        if (hash.find(key) != hash.end())
        {
            //replace value of key
            hash.find(key)->second = value;
            //move key to most recently used in history
            history.remove(key);
            history.push_front(key);
        }
        else
        {
            //if capacity not met, insert
            if (hash.size() < capacity)
            {
                hash.insert(make_pair(key, value));
                history.push_front(key);
            }
            else
            {
                //capacity met. delete oldest key
                int oldestKey = history.back();
                history.pop_back();
                hash.erase(oldestKey);
                hash.insert(make_pair(key, value));
                history.push_front(key);
            }
        }
    }
};