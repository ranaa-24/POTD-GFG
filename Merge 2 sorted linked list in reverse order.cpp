class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *previous = NULL;
        Node *current = head;

        while (current != NULL)
        {

            Node *next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }

        head = previous;
        return head;
    }
    struct Node *mergeResult(Node *node1, Node *node2)
    {
        node1 = reverse(node1);
        node2 = reverse(node2);

        Node *head = NULL;
        Node *tail = NULL;

        while (node1 and node2)
        {
            if (node1->data > node2->data)
            {
                if (!head)
                {
                    head = node1;
                    tail = node1;
                }
                else
                {
                    tail->next = node1;
                    tail = node1;
                }
                node1 = node1->next;
            }
            else
            {
                if (!head)
                {
                    head = node2;
                    tail = node2;
                }
                else
                {
                    tail->next = node2;
                    tail = node2;
                }
                node2 = node2->next;
            }
        }

        while (node1)
        {
            if (!head)
            {
                head = node1;
                tail = node1;
            }
            else
            {
                tail->next = node1;
                tail = node1;
            }
            node1 = node1->next;
        }

        while (node2)
        {
            if (!head)
            {
                head = node2;
                tail = node2;
            }
            else
            {
                tail->next = node2;
                tail = node2;
            }
            node2 = node2->next;
        }

        return head;
    }
};