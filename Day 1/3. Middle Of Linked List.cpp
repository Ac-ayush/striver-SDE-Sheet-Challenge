 #include<bits/stdc++.h>
 
        //Middle of a linked list 
int findLength(Node *head)
{
    Node* temp = head ; 
    int cnt = 0 ; 
    
    while( temp != NULL){
        cnt++ ; 
        temp = temp->next ; 
    }
    return cnt ; 
}


Node *findMiddle(Node *head) {
    //first  find the length / no of nodes of Linked list 
    int len = findLength(head) ; 
    int middle = len/2 ; 
    
    Node *temp = head ;
    
    while(middle--)
    {
        temp = temp->next ;
    }
    return temp ; 
}
