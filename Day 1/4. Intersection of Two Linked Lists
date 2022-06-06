//Intersection of two Linked List
            //Optimised Code time-O(m+n) & spaceO(1)//
int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *a = firstHead ; 
    Node *b = secondHead ; 
    
    while( a!=b )
    {
        if( a==NULL) a = secondHead ;     //agar list A null par pahuch jati to use 2nd list ke head par se shuru karwaO 
        else a = a->next ; 
        
        if( b==NULL) b = firstHead ; 
        else b = b->next ; 
    }
    if( a== NULL) return -1 ; 
    
    return a->data ; 
}
