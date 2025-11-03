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
    size_t size = 0;
    string s;
    
    while(1)
    {
        cin>>s;
        if(s== "push")
        {
            int ch;
            cin>>ch;
            head = new Node(ch,head);
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
                if(head->next ==nullptr) head =nullptr;
                else head = head->next;
                delete curr;
                size--;
            }
        }
        else if(s == "back")
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
                if(head->next == nullptr) head = nullptr;
                else head = head->next;
                delete curr;
                size--;
            }
            cout<<"ok"<<endl;
        }
        else
        {
            cout<<"bye"<<endl;
            break;
        }
    }
    return 0;

}