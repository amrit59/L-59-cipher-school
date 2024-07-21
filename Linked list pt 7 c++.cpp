
#include<iostream>
using namespace std;

class node
{
    public:
    int data;   //Let us assume for now that the data which the linked list is storing is int
    node *next;

    node(int data_input)
    {
        this->data = data_input;
        this->next = NULL;
    }
};

void printnode(node * &node)
{
    cout<<"Value : "<<node->data;
    cout<<"Address: "<<node->next;
}
void printlinkedlist(node * &head)
{
    if(head == NULL)
    {
        cout<<"The linked list is still empty!! "<<endl;
        return;
    }
    node *temp;
    temp = head;

    //This is called the transversing of a linked list
    while(temp!=NULL)
    {
        cout<<temp->data<<" -->";
        temp = temp->next;
    }
    cout<<endl;
}

void Insertatstart(node * &head, int data)
{
    node * temp = new node(data);

    if(head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;  //where temp is the new head and now, we need to assign the address of the old head to it
    head = temp;
}
void Insertatend(node * &head, int data)
{
    node * temp = new node(data);

    if(head == NULL)
    {
        head = temp;
        return;
    }
    
    node *end;
    end = head;

    while(end->next!=NULL)
    {
        end = end->next;
    }
    //After this while loop is complete, we have basically reached the end of the linked list

    end->next = temp;
}
void Insert_at_middle_after_which_element(node * &head, int location, int data)
{
    
    node * temp = new node(data);
    node * var = head;
    //loop to check whether location exist or not
    while(var->data!=location)
    {
        var = var->next;
        if(var==NULL)
        {
            cout<<"The location doesn't exist, check the location again "<<endl;
            return;
        }
    }

    //Now var will have the node address of the element at whichthe new data is going to be inserted

    temp->next = var->next;
    var->next = temp;

}

void delete_node_of_linked_list(node * &head, int data)
{
    if(head->data == data)
    {
        cout<<"The head of the linked list is going to be deleted!! "<<endl;
        head = head->next;
        return;
    }
    node * temp;
    node * prev;
    temp = head;

    while(temp->data!=data)
    {
        if(temp->next == NULL)
        {
            cout<<"The element to be deleted doesn't exist"<<endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        prev->next = NULL;
        return;
    }

    prev->next = prev->next->next;
}
int main()
{
    //Head of a linked list is nothing but a fancy term to indicate the top or the first element of the linked list
    node *head = NULL;
    // printlinkedlist(head);

    node * node1 = new node(5);
    head = node1;
    // printlinkedlist(head);
    // cout<<endl;

    node * node2 = new node(7);
    node1->next = node2;    //The storing address of the first node which was initially pointing to NULL will now point to the address of the next node
    // printlinkedlist(head);
    // cout<<endl;

    node * node3 = new node(8);
    node2->next = node3;
    printlinkedlist(head);
    // cout<<endl;

    // printnode(node1);
    // cout<<node2<<endl;
    // printnode(node2);
    // cout<<node3<<endl;
    // printnode(node3);
    
    // printnode(node1->next);     //node2 == node1->next
    // printnode(node1->next->next);       //node3 == node2->next == node1->next->next

    //Inserting new elements to the linked list, when the head is given
    //Inserting new element at the start of the linked list

    Insertatstart(head,3);
    //printlinkedlist(head);
    Insertatstart(head,2);
    //printlinkedlist(head);'

    Insertatend(head,9);
    Insertatend(head,10);

    // printlinkedlist(head);
    
    Insert_at_middle_after_which_element(head, 3, 4);
    Insert_at_middle_after_which_element(head, 5, 6);
    // Insert_at_middle_after_which_element(head, 100, 101);
    // printlinkedlist(head);

    //Now I want to delete the elements 2,10,6

    delete_node_of_linked_list(head,2);
    delete_node_of_linked_list(head,10);
    delete_node_of_linked_list(head,6);

    printlinkedlist(head);
    return 0;
}

