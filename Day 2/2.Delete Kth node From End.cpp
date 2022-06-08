#include <bits/stdc++.h> 

//slow & fast pointer method 
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k )
{
    if( head == NULL || k==0) return head ; 
    
    LinkedListNode<int>* slow = head ; 
    LinkedListNode<int>* fast = head ; 
    
    for(int i=0 ; i<k ; i++)
    {
        fast = fast->next ;  
    }
    if( fast == NULL)return head->next ;         // if first element to be remove
    
    while(fast->next != NULL){        // move both pointers maintaining same diff
        fast = fast->next ;
        slow = slow->next ;  
    }
 
    slow->next = slow->next->next ;     // skip the nth node
    return head ; 
}
