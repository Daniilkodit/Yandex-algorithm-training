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
    Node(int ch = 0,Node* next = nullptr){ this->data = ch; this->next = next;}
    
    int data;
    Node* next;
};
int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    size_t size = 0;
    string s;
    while(1)
    {
        cin>>s;
        if(s=="push")
        {
            int ch;
            cin>>ch;
            if(head==nullptr)
            {
                head = new Node(ch);
                tail = head;
            }
            else
            {
                tail->next = new Node(ch);
                tail = tail->next;
            }
            size++;
            cout<<"ok"<<endl;
        }
        else if(s == "pop")
        {
            if(head == nullptr) cout<<"error"<<endl;
            else
            {
                cout<<head->data<<endl;
                Node* curr = head;
                if(head==tail) {head =nullptr; tail = nullptr;}
                else head = head->next;
                delete curr;
                size--;
            }
        }
        else if(s=="front")
        {
            if(head== nullptr) cout<<"error"<<endl;
            else cout<<head->data<<endl;
        }
        else if(s == "size")cout<<size<<endl;
        else if(s == "clear")
        {
            
            while(head!=nullptr)
            {
                Node* curr = head;
                if(head==tail) {head = nullptr;tail = nullptr;}
                else head = head->next;
                delete curr;
                size--;
            }
            tail = nullptr;
            cout<<"ok"<<endl;
        }
        else
        {
            cout<<"bye"<<endl;
            break;
        }
    }
}