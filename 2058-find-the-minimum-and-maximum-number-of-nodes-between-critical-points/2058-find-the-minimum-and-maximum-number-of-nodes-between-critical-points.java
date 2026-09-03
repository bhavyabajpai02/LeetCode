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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int first = -1, last = -1,len = 1,before = -1,maxi = 0, mini= Integer.MAX_VALUE;
        ListNode prev = head , temp = head.next;
        while(temp != null && temp.next != null) {
                if((temp.val > prev.val && temp.val > temp.next.val) || (temp.val < prev.val && temp.val<temp.next.val)){
                    if(first == -1){
                        first = len;
                    }
                    else{
                        last = len;
                    }
                    if(before == -1){
                        before = len;
                    }
                    else {
                        mini = Math.min(mini,len-before);
                        before = len;
                    }
                }
                len++;
                prev = temp;
                temp = temp.next;            
        }
        if(first != -1 && last != -1){
            return new int[]{mini,last-first};
        }
        return new int[]{-1,-1};
    }
}