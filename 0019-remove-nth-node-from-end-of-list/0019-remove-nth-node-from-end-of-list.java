/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode reverse(ListNode head){

        ListNode prev = null,ptr = head,next = null;
        while(ptr != null){
            next = ptr.next;
            ptr.next = prev;
            prev = ptr;
            ptr = next;
        }
        return prev;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        head = reverse(head);
        if(n==1){
            head = head.next;
        }
        else{
            ListNode ptr = head;
            for(int i=1 ; i<n-1 ; i++){
                ptr = ptr.next;
            }
            ptr.next = ptr.next.next;
        }
        head = reverse(head);
        return head;

        // while(ptr != null){
        //     next = ptr.next;
        //     ptr.next = prev;
        //     prev = ptr;
        //     ptr = next;
        // }
        // return prev;
        
    }
}