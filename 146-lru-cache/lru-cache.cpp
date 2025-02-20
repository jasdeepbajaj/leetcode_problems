class LRUCache {
public:
    class Node{
        public:
            int key;
            int value;
            Node* next;
            Node* prev;

            Node(int _key, int _val){
                key = _key;
                value = _val;
                next = nullptr; 
                prev = nullptr;
            }
    };

private:

    Node* head;
    Node* tail;
    unordered_map<int, Node*> dict;
    int _capacity;

public:

    LRUCache(int capacity) {

    _capacity = capacity; 
    head = new Node(-1,-1);
    tail = new Node(-1,-1);
    
    head -> next = tail;
    tail -> prev = head;

    }

    void addNode(Node* new_node){
        Node* temp = head -> next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }

    void deleteNode(Node* del_node){
        Node* del_prev = del_node->prev;
        Node* del_next = del_node->next;
        del_prev -> next = del_next;
        del_next -> prev = del_prev;

    }
    
    int get(int key) {
        //if key exists, get the value and move to front
        if(dict.find(key) != dict.end()){
            Node* res_node = dict[key];
            int res = res_node -> value;
            dict.erase(key);
            deleteNode(res_node);
            addNode(res_node);
            dict[key] = head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // If key exists, update value and move to front
        if(dict.find(key) != dict.end()){
            Node* existing_node = dict[key];
            dict.erase(key);
            deleteNode(existing_node);
            delete existing_node;
            
            Node* new_node = new Node(key, value);
            addNode(new_node);
            dict[key] = new_node;
        }


        // If capacity is full, remove LRU item
        else if (dict.size() >= _capacity){
            Node* lru_node = tail -> prev;
            deleteNode(lru_node);
            dict.erase(lru_node -> key);

            Node* new_node = new Node(key, value);
            addNode(new_node);
            dict[key] = new_node;
        }

        //if capacity is not full then add to front
        else if (dict.size() < _capacity){
            Node* new_node = new Node(key, value);
            addNode(new_node);
            dict[key] = new_node;
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */