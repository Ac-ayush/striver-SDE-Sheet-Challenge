                        //Appproach 1 , used extra space//
/* 1. store list elements in vector
   2. check vector is palindrome or not by 2 pointers    */

bool checkPalindrome( vector<int> &v)
{
    int i=0 , j=v.size()-1 ; 
    while(i<=j)
    {
        if(v[i] != v[j])
            return false ;
        
        i++ ; 
        j-- ; 
    }
    return true ; 
}


bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> v ; 
    while(head != NULL){
        v.push_back(head->data) ; 
        head = head->next ;
    }

    return checkPalindrome(v) ; 
}


                        //Approach 2 //
/*
1. find middle node 
2. reverse the list after midddle node 
3. middle ke baad ki list par ek pointer laga do aur ek ek elemeent check karlo 
*/
    
//get middle of linked list
    ListNode* getMiddle(ListNode* &head)
    {
        ListNode* slow = head ; 
        ListNode* fast = head->next; 
        
        while( fast && fast->next ){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
    }
   
//reverse linked list 
    ListNode* reverse(ListNode* &head){
        
        ListNode* curr = head ; 
        ListNode* prev = NULL ; 
        ListNode* next = NULL ; 
        
        while(curr != NULL)
        {
            next = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = next ; 
        }
        return prev ; 
    }
    
//MAin 
    bool isPalindrome(ListNode* &head) {
        
        if(head->next == NULL) return true ;

        ListNode* middle = getMiddle(head) ;    //get middle node 
        
        //reverse after middle
        ListNode* temp = middle->next ;
        middle->next = reverse(temp) ;
        
        //now compare 
        ListNode* head1 = head ;
        ListNode* head2 = middle->next ; 
        
        while( head2 != NULL)
        {
            if( head1->val != head2->val )
                return false ; 
            
            head1 = head1->next ;
            head2 = head2->next ; 
        }
        return true ; 
    }
};
