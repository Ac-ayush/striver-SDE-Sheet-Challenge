bool detectCycle(Node *head)
{
    if(head == NULL)return false ; 
  
	  Node* slow = head ; 
    Node* fast = head ; 
    
    while( fast && fast->next)
    {
        slow = slow->next ; 
        fast = fast->next->next ; 
        if(slow == fast)
            return true ; 
    }
    return false ; 
}
