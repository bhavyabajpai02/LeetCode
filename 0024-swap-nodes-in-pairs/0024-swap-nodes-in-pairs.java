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
    public ListNode swapPairs(ListNode head) {
        ListNode ptr = head,prev = null;
        while( ptr != null && ptr.next != null){
           ListNode nxt = ptr.next;
           ptr.next = nxt.next;
           nxt.next = ptr;
           if(prev != null)
           prev.next = nxt;
           if(head == ptr){
            head = nxt;
           }
           prev = ptr;
            ptr = ptr.next;
        }
        return head;
    }
}