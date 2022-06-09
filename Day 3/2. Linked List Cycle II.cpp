
      //Que : Find first node of cycle// 
Node* detectCycly(Node* head)
{
    Node* slow = head; 
    Node* fast = head; 
    
    while( fast && fast->next )
    {
        slow = slow->next ; 
        fast = fast->next->next ; 
        if(slow == fast)
            return slow ; 
    }
    return NULL ; 
}

Node *firstNode(Node *head)
{
	if(head == NULL) return NULL; 
    
  //1. detect cycle 
    Node* intersection = detectCycly(head) ;     //if cycle present we got intersection node
    if( intersection == NULL ) return NULL ;     //if cycle is not present 
    
    Node* slow = head ; 
    Node* fast = intersection ; 
  
  //2. find start node of the cycle 
    while(slow != fast)
    {
        slow = slow->next ; 
        fast = fast->next ; 
    }
    return slow ; 
}
