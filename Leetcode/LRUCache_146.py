/*
To search and update in O(1),
 - use linked-list to maintain a queue: head(least recently used) -> tail(most recently used)
  => get in O(N), insert in O(1) but update in O(N)
 we can use a hashmap to speedup the lookup of the address of the target node
 - use hashmap with (key, value) = (key, address)
*/

typedef struct node {
    int k, v;
    struct node *next, *prev;
}node;

class LRUCache {
public:
    node *head, *tail;
    std::map<int, node*> address_map;
    int length, max_length;

    LRUCache(int capacity) {
        // maintain a linked-list queue: head -> least recently used, tail -> most recently used
        head = (node *)malloc(sizeof(node));
        tail = (node *)malloc(sizeof(node));
        head->k = head->v = tail->k = tail->v = -1;
        head->prev = tail->next = NULL;
        head->next = tail; tail->prev = head;
        // maintain a map for O(1) access to element in queue (key, pointer_to_element)
        address_map = std::map<int, node*>();
        length = 0;
        max_length = capacity;
    }

    int get(int key) {
        // looup the address_map
        std::map<int, node*>::iterator it = address_map.find(key);
        if (it == address_map.end()) return -1; // not in cache
        // found in cache
        node *addr = it->second;
        // move to tail (most recently used)
        addr->prev->next = addr->next;
        addr->next->prev = addr->prev;
        tail->prev->next = addr;
        addr->prev = tail->prev;
        tail->prev = addr;
        addr->next = tail;
        // return value
        return addr->v;
    }

    void put(int key, int value) {
        // lookup the address_map
        std::map<int, node*>::iterator it = address_map.find(key);
        if (it == address_map.end()) { // not in cache
            // check if cache full
            if (length == max_length) { // pop first element
                address_map.erase(head->next->k); // remove lookup
                head->next = head->next->next;
                head->next->prev = head;
                length -= 1;
            }
            // insert new element to tail
            node *new_node = (node *)malloc(sizeof(node));
            address_map.insert(std::pair<int, node*>(key,new_node)); // insert for lookup
            new_node->k = key; new_node->v = value;
            tail->prev->next = new_node;
            new_node->prev = tail->prev;
            new_node->next = tail;
            tail->prev = new_node;
            length += 1;
        } else { // in cache => update value and move to tail
            node *addr = it->second;
            addr->v = value; // update value
            // move to tail
            addr->prev->next = addr->next;
            addr->next->prev = addr->prev;
            tail->prev->next = addr;
            addr->prev = tail->prev;
            tail->prev = addr;
            addr->next = tail;
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
