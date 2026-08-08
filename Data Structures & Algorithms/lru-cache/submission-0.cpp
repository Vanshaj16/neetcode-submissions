class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key_,int val_){
            key=key_;
            val=val_;
        }
    };
    int cap;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(Node* delNode){
        Node* prevN=delNode->prev;
        Node* nextN=delNode->next;
        prevN->next=nextN;
        nextN->prev=prevN;
    }
    void addNode(Node* adNode){
        Node* temp=head->next;
        adNode->next=temp;
        adNode->prev=head;
        head->next=adNode;
        temp->prev=adNode;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            int res=temp->val;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};
