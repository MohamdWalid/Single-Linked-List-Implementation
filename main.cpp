#include <iostream>
using namespace std;
template<class t>
class node
{
public:
    t item;
    node *next;
};
template<class t>
class FCISLL
{
private:
    node<t> *head,*tail;
    int length=0;
public:
    void addTohead(t item)
    {
        node<t> *newNode = new node<t>;
        newNode->item = item;
        if (length == 0)
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }
    void addTotail(t item)
    {
        node<t> *newNode = new node<t>;
        newNode->item = item;
        if (length == 0)
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next=newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        length++;
    }
    void addToindex(int data, int index)
    {
        if (index < 0 || index > length)
        {
            cout << "ERROR Range" << endl;
        }
        else
        {
            node<t> *newNode = new node<t>;
            newNode->item = data;
            if (index == 0)
            {
                addTohead(data);
            }
            else if (index == length)
            {
                addTotail(data);
            }
            else
            {
                node<t> *current = head;
                for (int i = 1; i < index; i++)
                    current = current->next;

                newNode->next = current->next;
                current->next = newNode;
                length++;
            }

        }
    }
    bool isempty()
    {
        if(length==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void removehead()
    {

        if(isempty())
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            node<t>*current=head;
            head=head->next;
            delete current;
            length--;
        }
    }
    void removetail()
    {
        if(isempty())
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            node<t> *current = head->next;
            node<t> *trailCurrent = head;
            while (current != tail)
            {
                trailCurrent = current;
                current = current->next;
            }
            delete current;
            trailCurrent->next = NULL;
            tail = trailCurrent;
            length--;
        }

    }
    void removeitem(int value)
    {
        if(isempty())
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            node<t>*current;
            node<t>*prev=head;
            current=head->next;
            if(head->item==value) //Delete First Node
            {
               removehead();
            }
            else if(tail->item==value)
            {
                removetail();
            }
            else
            {
                while(current!=NULL)
                {
                    if(current->item==value)
                    {

                            prev->next=current->next;
                            delete current;
                            length--;
                            break;
                    }
                    else
                    {
                        prev=current;
                        current=current->next;
                    }
                }
                if(current==NULL)
                {
                    cout<<"Element Not Found on the List!!!"<<endl;
                }
            }
        }

    }
    void removeindex(int position)
    {
        if(isempty())
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            if(position>length-1||position<0)
            {
                cout<<"Deletion out of Bound"<<endl;
            }
            else if(position==0)
            {
                removehead();
            }
            else if(position==length-1)
            {
                removetail();
            }
            else
            {
                node<t>*current;
                node<t>*prev;
                current=head;
                for(int i=0; i<position; i++) //Go to Right Position
                {
                    prev=current;
                    current=current->next;
                }
                    prev->next=current->next;
                    delete current;
                    length--;
            }
        }

    }
    bool Search(t data)
    {
        if(isempty())
        {
            cout<<"list is empty"<<endl;
            return false;
        }
        else if(tail->item==data)
        {
            return true;
        }
        else
        {
            node<t> *curr=head;
            while(curr->item!=data && curr!=tail)
            {
                curr=curr->next;
            }
            if(curr!=tail)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
    void print()
    {
        if(isempty())
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            node<t> *curr;
            curr=head;
            for(int i=0; i<length; i++)
            {
                cout<<curr->item<<"\n";
                curr=curr->next;
            }
        }

    }
    void removeWithPredicate1()
    {
        if(isempty())
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            node<t> *curr=new node<t>;
            curr=head;
            while(curr!=NULL)
            {
                if(odd(curr->item))
                {
                    removeWithPredicate(curr->item);
                }
                curr=curr->next;
            }
        }

    }
    bool odd(int num)
    {
        if(num%2==1)
            return true;
        else
            return false;

    }
    void removeWithPredicate(int num)
    {
        removeitem(num);
    }
};
int main()
{
    FCISLL<int> o1;
    int choice,choice2,index,data;
    while(true)
    {
        do
        {
            cout<<"[1] add to head"<<endl<<"[2] add to tail"<<endl<<"[3] add to index"<<endl<<"[4] remove from head"<<endl<<"[5] remove from tail"<<endl<<"[6] remove item "<<endl<<"[7] remove with index" <<endl<<"[8] search in list"<<endl<<"[9] removeWithPredicate"<<endl<<"[10] print list"<<endl;
            cout<<"Enter choice: ";
            cin>>choice;
        }
        while(choice<1 || choice>10);
        switch(choice)
        {
        case 1:
            cout<<"Enter data: ";
            cin>>data;
            o1.addTohead(data);
            break;

        case 2:
            cout<<"Enter data: ";
            cin>>data;
            o1.addTotail(data);
            break;

        case 3:
            cout<<"Enter data: ";
            cin>>data;
            cout<<"Enter index: ";
            cin>>index;
            o1.addToindex(data,index);
            break;

        case 4:
            o1.removehead();
            break;

        case 5:
            o1.removetail();
            break;

        case 6:
            cout<<"Enter data: ";
            cin>>data;
            o1.removeitem(data);
            break;
        case 7:
            cout<<"Enter index: ";
            cin>>index;
            o1.removeindex(index);
            break;
        case 8:
            cout<<"Enter data: ";
            cin>>data;
            if(o1.Search(data))
            {
             cout<<"this item found in list"<<"\n";
            }
            else
            {
             cout<<"this item not found in list"<<"\n";
            }
            break;

        case 9:
            o1.removeWithPredicate1();
            break;

        case 10:
            o1.print();
            break;
        }
        do
        {
          cout<<"[1] continue"<<"[2] stop"<<endl;
          cin>>choice2;
        }while(choice2!=1 && choice2!=2);
        if(choice2==2)
        {
            break;
        }
    }
    return 0;
}
