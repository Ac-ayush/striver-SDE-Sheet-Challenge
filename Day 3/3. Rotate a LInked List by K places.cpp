          //Optimised Code TC--> O(n)//


//Rotate Clockwise : leetcode & CodeStudio
class Solution {
    void findLastNodes(ListNode* head ,ListNode* &lastNode ,ListNode* &prev)
    {
        ListNode* temp = head ; 
        while(temp->next != NULL)
        {
            prev = temp ;
            temp = temp->next ; 
        }
        
        lastNode = temp ; 
    }
    
    
    int listLenght(ListNode* head)
    {
        int cnt=0 ; 
        ListNode* temp = head ;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next ; 
        }
        return cnt ; 
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL) return NULL ;
        if(head->next == NULL )return head ; 
        
        int len = listLenght(head) ;
        
        while(k%len != 0)
        {
            ListNode* prev = NULL ;         //2nd last node of the list 
            ListNode* lastNode = head ; 
            findLastNodes( head , lastNode , prev ) ; 
            
            //change links and add last node in front 
            lastNode->next = head ; 
            prev->next = NULL ; 
            
            head = lastNode ; 
            k-- ; 
            
        }
        
        return head; 
    }
};



//Rotate anti Clockwise : gfg 
class Solution
{                //Optimised : TC--> O(n) : Gives TLE//
    void findLastNodes(Node* head ,Node* &lastNode)
    {
        Node* temp = head ; 
        while(temp->next != NULL)
        {
            temp = temp->next ; 
        }
        lastNode = temp ; 
    }
    
    
    int listLenght(Node* head)
    {
        int cnt=0 ; 
        Node* temp = head ;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next ; 
        }
        return cnt ; 
    }
    
    public:
    
    Node* rotate(Node* head, int k) {
        
        if(head == NULL) return NULL ;
        if(head->next == NULL )return head ; 
        
        int len = listLenght(head) ;
        
        Node* frontNode = head ;
        Node* lastNode = head ; 
        findLastNodes( head , lastNode ) ;
        
        while(k%len != 0)
        {
            //change links and add last node in front 
            
            Node*nextHead = frontNode->next ;
            frontNode->next = NULL ;        //frontNode is node to shift
            lastNode->next = frontNode ;
            
            lastNode = frontNode ;          //update last & front node
            frontNode = nextHead ; 
            k-- ; 
        }
        return frontNode; 
    }
};
