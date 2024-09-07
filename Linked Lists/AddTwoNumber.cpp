/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
// Node* reverse(Node* node) {
//     if (node == NULL || node->next == NULL) {
//         return node;
//     }
//     Node* rest = reverse(node->next);
//     node->next->next = node;  // Reverse the pointer
//     node->next = NULL;        // Set the current node's next to NULL
//     return rest;
// }
// --> with reverse
// Node* addTwoNumbers(Node* num1, Node* num2) {
//     Node* revNum1 = reverse(num1);
//     Node* revNum2 = reverse(num2);
//     Node* dummyNode = new Node(-1);  // Dummy node to store result
//     Node* current = dummyNode;
//     int rem = 0;

//     // Traverse both lists
//     while (revNum1 || revNum2 || rem) {
//         int val1 = (revNum1) ? revNum1->data : 0;  // Use 0 if revNum1 is NULL
//         int val2 = (revNum2) ? revNum2->data : 0;  // Use 0 if revNum2 is NULL
//         int sum = val1 + val2 + rem;
//         rem = sum / 10;  // Carry for next position
//         sum = sum % 10;  // Value to store in the current position

//         current->next = new Node(sum);
//         current = current->next;

//         if (revNum1) revNum1 = revNum1->next;
//         if (revNum2) revNum2 = revNum2->next;
//     }


//     // Reverse the result list to get the final answer
//     Node* result = reverse(dummyNode->next);
//     delete dummyNode;  // Clean up the dummy node
//     return result;
// }

// --> without reverse
Node* addTwoNumbers(Node* num1, Node* num2) {
   
    Node* dummyNode = new Node(-1);  // Dummy node to store result
    Node* current = dummyNode;
    int rem = 0;

    // Traverse both lists
    while (num1 || num2 || rem) {
        int val1 = (num1) ? num1->data : 0;  // Use 0 if revNum1 is NULL
        int val2 = (num2) ? num2->data : 0;  // Use 0 if revNum2 is NULL
        int sum = val1 + val2 + rem;
        rem = sum / 10;  // Carry for next position
        sum = sum % 10;  // Value to store in the current position

        current->next = new Node(sum);
        current = current->next;

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }
   
    return dummyNode->next;
}

