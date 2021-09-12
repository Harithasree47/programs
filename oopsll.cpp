#include <iostream>
using namespace std;
//here structure acts like a data tyoe and it reoresents the node
struct node { 
  int data; 
  node *next; 
};
class linkedlist
{
    node* head,*tail;
  public:
    // each linked list starts with a head
    linkedist()
    {
      head = NULL;
    }
    // inserting elements
    void insert(int n)
    {
       node *t = new node;
        t->data = n;
        t->next = NULL;

        if(head == NULL)
        {
            head = t;
            tail = t;
        }
        else
        {
            tail->next = t;
            tail = tail->next;
        }
    }
    void display()
    {
      node* t = head;
      while(t != NULL)
      {
        cout << t->data << " ";
        t = t->next;
      }
      cout << endl;
    }
};

int main() {
  
  linkedlist l;
  l.insert(2);
  l.insert(2);
  l.insert(1);
  l.insert(6);
  l.insert(9);
  l.display();
  return 0;
  }