template <typename T>
class Stack{
    struct Node{
        T data;
        Node* next;
    };
    Node* head;
public:
    Stack(){
        head = nullptr;
    }
    bool empty(){return head == nullptr;}
    void push(T val){
        Node* temp = new Node;
        temp->data = val;
        temp->next = nullptr;
        if(head!=nullptr){
            temp->next = head;
        }
        head = temp;
    };
    void pop(){
        Node* temp;
        temp = head;
        head = head->next;
        delete temp;
    };
    T top(){return head-> data;}
};
