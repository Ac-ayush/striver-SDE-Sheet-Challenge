            //TC-> O(n) && SC->O(1)//
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* dummy = new Node<int>(-1) ;
    Node<int>* p3 = dummy ;     //ans list 
    
    while( first && second )
    {
        if(first->data < second->data)
        {
            p3->next = first ; 
            first = first->next ; 
        }
        else{
            p3->next = second ; 
            second = second->next ; 
        }
        p3 = p3->next ; 
    }
    
    //hanlde remaining list 
    while( first != NULL)
    {
        p3->next = first ; 
        first = first->next ; 
        p3 = p3->next ; 
    }
    
    while( second != NULL)
    {
        p3->next = second ; 
        second = second->next ; 
        p3 = p3->next ; 
    }
    return dummy->next  ; 
}
