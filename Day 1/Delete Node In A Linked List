/*Appproach : Kyuki hamare pass jiss Node ko delete karna he(Curr Node) uske Previous node ka access nhi he 
                  isliye jiss node ko delete karna(curr node) he uske Next Node ka data Curr Node me copy karke
                  Next Node ko DELETE kar do 
*/
void deleteNode(LinkedListNode<int> * node) {
    
    LinkedListNode<int> *temp = node->next ;
    
    node->data = node->next->data ; 
    node->next = node->next->next ; 
    delete temp ;
}
