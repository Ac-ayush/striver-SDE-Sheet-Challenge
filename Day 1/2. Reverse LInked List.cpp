                //Reverse a Linked List//
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prev = NULL ; 
    LinkedListNode<int> *curr = head ; 
    LinkedListNode<int> *next = NULL ; 
    
    while(curr != NULL){
        next = curr->next ;    //1.  
        curr->next = prev ;    //2. 
        prev = curr ;          //3. update first prev then curr
        curr = next ;          //4,
    }

    return prev ; 
}
