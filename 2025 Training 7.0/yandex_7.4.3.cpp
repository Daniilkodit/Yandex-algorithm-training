#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
class Node
{
    public:
    Node(int ch = 0,Node* next = nullptr,Node* prev = nullptr){ this->data = ch; this->next = next; this->prev = prev;}
    
    int data;
    Node* next;
    Node* prev;
};
int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    while(1)
    {
        string s;
        cin>>s;
        if(s == "push_front")
        {
            int ch;
            cin>>ch;
            if(head == nullptr)
            {
                head = new Node(ch);
                tail = head;
            }
            else
            {
                head = new Node(ch,head);
                head->next->prev = head;
            }
            cout<<"ok"<<endl;
            size++;
        }
        else if(s=="push_back")
        {
            int ch;
            cin>>ch;
            if(head == nullptr)
            {
                head = new Node(ch);
                tail = head;
            }
            else
            {
                tail->next = new Node(ch,nullptr,tail);
                tail = tail->next;
            }
            cout<<"ok"<<endl;
            size++;
        }
        else if(s == "pop_front")
        {
            if(head == nullptr) cout<<"error"<<endl;
            else
            {
                cout<<head->data<<endl;
                Node* curr = head;
                if(head==tail) {head =nullptr; tail = nullptr;}
                else {
                    head = head->next;
                    head->prev = nullptr;
                }
                delete curr;
                size--;
            }

        }
        else if(s == "pop_back")
        {
            if(head == nullptr) cout<<"error"<<endl;
            else
            {
                cout<<tail->data<<endl;
                Node* curr = tail;
                if(head==tail) {head =nullptr; tail = nullptr;}
                else 
                {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                delete curr;
                size--;
            }
        }
        else if(s== "front")
        {
            if(head == nullptr) cout<<"error"<<endl;
            else cout<<head->data<<endl;
        }
        else if(s== "back")
        {
            if(head == nullptr) cout<<"error"<<endl;
            else cout<<tail->data<<endl;
        }
        else if(s == "clear")
        {
            while(head!=nullptr)
            {
                Node* curr = head;
                if(head==tail) {head =nullptr; tail = nullptr;}
                else 
                {
                    head = head->next;
                    head->prev = nullptr;
                }
                delete curr;
                size--;
            }
            cout<<"ok"<<endl;
        }
        else if(s == "size") cout<<size<<endl;
        else
        {
            cout<<"bye"<<endl;
            break;
        }
    }
}