class Node{
    
    int val;
    Node next ;
    Node( int val){
        this.val = val;
        next = null;
    }
};
class MyLinkedList {
    // Node head ;
        Node head = null;
    public MyLinkedList() {
    }
    
    public int get(int index) {
        if(head == null) return -1;
        int count = 0;
        Node ptr = head;
        while(count<index){
            count++;
            ptr = ptr.next;
            if(ptr == null) return -1;
        }
        return ptr.val;
    }
    
    public void addAtHead(int val) {
        if(head == null){
            head = new Node (val);
            return;
        }
        Node node = new Node(val);
        node.next = head;
        head = node;        
    }
    
    public void addAtTail(int val) {
        if(head == null){
            head =new Node( val);
            return;
        }
        Node node = new Node(val);
        Node ptr = head;
        while(ptr.next != null){
            ptr = ptr.next ;
        }
        ptr.next = node;
    }
    
    public void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        Node node = new Node(val);
        Node prev = null, ptr = head;
        int count = 0;
        while(count<index && ptr != null){
            prev = ptr;
            ptr = ptr.next;
            count++;
        }
        if(count == index){
            node.next = ptr;
            prev.next = node;
        }
        
    }
    
    public void deleteAtIndex(int index) {
        if(head == null) return ;
        if(index == 0){
            head = head.next;
        }
        int count = 0;
        Node prev = null,ptr = head;
        while(ptr != null && count<index){
            prev = ptr;
            ptr = ptr.next;
            count++;
        }
        if(count == index  && prev != null){
            if( ptr != null)
            prev.next = ptr.next;
            else{
                prev.next = null;
            }
        }
        
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */