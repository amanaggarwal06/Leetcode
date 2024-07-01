class Node{
public:

    int key, value;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int k, int v){
        this->key = k;
        this->value = v;
    }
};

class LRUCache {
public:

    unordered_map<int, Node*> keynode;
    Node* head;
    Node* tail;
    int size = 0;

    LRUCache(int capacity) {
        
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        size = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* root){

        Node* temp = head->next;
        head->next = root;
        root->prev = head;

        root->next = temp;
        temp->prev = root;
    }

    void deletenode(Node* root){

        Node* delprev = root->prev;
        Node* delnxt = root->next;

        delete(root);
        delprev->next = delnxt;
        delnxt->prev = delprev;
    }
    
    int get(int key) {
        
        if(keynode.find(key) != keynode.end()){

            Node* temp = keynode[key];
            keynode.erase(key);
            int ans = temp->value;

            Node* newnode = new Node(key, ans);
            addnode(newnode);
            deletenode(temp);

            keynode[key] = newnode;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        //already there in the list
        if(keynode.find(key) != keynode.end()){

            Node* temp = keynode[key];
            keynode.erase(key);

            deletenode(temp);
        }

        //capacity full
        if(keynode.size() == size && size != 0){

            Node* delnode = tail->prev;
            keynode.erase(delnode->key);
            deletenode(delnode);
        }

        Node* newnode = new Node(key, value);
            addnode(newnode);

            keynode[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */