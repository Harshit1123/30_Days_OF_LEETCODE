
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
         if(head==NULL)
            return NULL;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy;
      
        while(head!=NULL)
        {  if(head->val==val)
             {
                 ListNode *temp=head;
                 head=head->next;
                 prev->next=head;
                 delete temp;
            }
         else 
              { 
               head=head->next;
                prev=prev->next;
              }
        }
        return dummy->next;
        
    }
};
