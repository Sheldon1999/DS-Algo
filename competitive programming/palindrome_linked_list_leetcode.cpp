// Given a singly linked list, determine if it is a palindrome.

bool isPalindrome(ListNode* head) {
        
    struct ListNode* tempP = head;
    struct ListNode* tail = NULL;
    struct ListNode* secStartPtr = NULL;
    struct ListNode* firLastPtr = NULL;
    
    //getting length of list and tail ptr.
    int length = 0;
    while(tempP){
        if(tempP->next == NULL)
            tail = tempP;
        tempP = tempP->next;
        ++length;
    }

    if(length == 0)
        return true;

    else if(length == 1 or length == 2 or length == 3)
        return head->n == tail->n;
    
    else{

        //getting the starting ptr of second half part of the list.
        int nodesCovered = 0;
        tempP = head;
        while(tempP){
            ++nodesCovered;
            // printf("nodesCovered: %d", nodesCovered);
            if(nodesCovered == length/2){
                // printf(" got ptr!!");
                firLastPtr = tempP;
            }
            if(nodesCovered == (length+1)/2){
                secStartPtr = tempP->next;
                break;
            }
            // printf("\n");
            tempP = tempP->next;      
        }
        // firLastPtr->next = NULL;
        //printf("%d %d",firLastPtr->n, secStartPtr->n);

        //iterating in the second part of the list and
        //reversing the whole second part for easy checking
        struct ListNode* cur = NULL;
        struct ListNode* nxt = NULL;
        cur = secStartPtr;
        nxt = cur->next;
        // printf("%d %d", cur->n, nxt->n);
        cur->next = NULL;
        while(nxt){
            // printf("loop start!!");
            //reversing the relation btw every pair of nodes
            tempP = nxt->next;
            nxt->next = cur;
            cur = nxt;
            if(tempP == NULL){
                tail = nxt;
                break;
            }
            nxt = tempP;
        }

        //check if list is palindrome or not
        bool isPalin = true;
        // by iterating in first from head and
        // second part from tail
        tempP = tail;
        while(tempP){
            if(head->n != tempP->n){
                isPalin = false;
                break;
            }
            head = head->next;
            tempP = tempP->next;
        }

        return isPalin;
    }
}
