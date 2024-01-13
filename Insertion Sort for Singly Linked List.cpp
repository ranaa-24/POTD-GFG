Node *insertionSort(struct Node *head)
{
    // code here
    if (!head || !(head->next))
        return head;
    // main moto is will always try to insert in b/w prev and prev->next->next
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *prev = dummy;
    Node *curr = head;

    while (curr != NULL)
    {
        prev = dummy;

        if (curr->next != nullptr && (curr->next->data < curr->data))
        { // insert at correct pos.
            // find first greater val than curr->next->val
            while (prev->next != nullptr && prev->next->data < curr->next->data)
            {
                prev = prev->next;
            }
            Node *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        else
        { // if next element is greater than curr, then curr in right place
            curr = curr->next;
        }
    }

    return dummy->next;
}