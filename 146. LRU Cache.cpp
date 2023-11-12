// struct ListNode
// {
//     int key;
//     int value;
//     ListNode* next = NULL;
//     ListNode* prev = NULL;
// };
class LRUCache {
public:
    class ListNode
    {
        public:
        int key;
        int value;
        ListNode* prev = NULL;
        ListNode* next = NULL;
    };
    ListNode* head = new ListNode();
    ListNode* tail = new ListNode();
    map<int,ListNode*> hashmap;
    int cap;

    LRUCache(int capacity) 
    {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) 
    {
        if(hashmap.find(key)!=hashmap.end())
        {
            //Getting address of node to update
            ListNode* toupdate = hashmap[key];

            //Removing the node from its current pos
            toupdate->prev->next = toupdate->next;
            toupdate->next->prev = toupdate->prev;

            //Adding it again to cache
            ListNode* neighbour = head->next;
            toupdate->next = neighbour;
            neighbour->prev = toupdate;

            head->next = toupdate;
            toupdate->prev = head;

            return hashmap[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        //If it is already in cache
        if(hashmap.find(key)!=hashmap.end() && hashmap.size()!=1)
        {
            //Getting address of node to update
            ListNode* toupdate = hashmap[key];

            //Removing the node from its current pos
            toupdate->prev->next = toupdate->next;
            toupdate->next->prev = toupdate->prev;

            //Adding it again to cache
            ListNode* neighbour = head->next;
            toupdate->next = neighbour;
            neighbour->prev = toupdate;

            head->next = toupdate;
            toupdate->prev = head;
            toupdate->value = value;
        }
        else
        {
            //Creating the new node
            ListNode* newnode = new ListNode();
            newnode->key = key;
            newnode->value = value;

            //Adding new node to cache
            ListNode* neighbour = head->next;
            newnode->next = neighbour;
            neighbour->prev = newnode;

            head->next = newnode;
            newnode->prev = head;

            hashmap[key] = newnode;

            //Checking if cache exceeds limit
            if(hashmap.size()>cap)
            {
                //Removing Last Node
                ListNode* toremove = tail->prev;

                tail->prev = toremove->prev;
                toremove->prev->next = tail;

                hashmap.erase(toremove->key);
            }


        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */