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
        public ListNode removeElements(ListNode head, int val) {
    if(head==null)return head;
    ListNode dummy=new ListNode(0);
    dummy.next=head;
    ListNode cur=dummy; //**start from dummy not head
    
    while(cur.next!=null){
        if(cur.next.val==val){
            cur.next=cur.next.next;
        }
        else{
            cur=cur.next;
        }
        
    }
    return dummy.next;  //**head may be deleted already
}
        
    }
