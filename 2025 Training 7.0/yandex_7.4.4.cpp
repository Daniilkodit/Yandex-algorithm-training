#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
class Node
{
    public:
    Node(string ch = "",Node* next = nullptr){ this->data = ch; this->next = next;}
    
    string data;
    Node* next;
};
int main()
{
    Node*head = nullptr;
    Node*help = nullptr;
    int n;
    cin>>n;
    cin.ignore();
    string s;
    for(int i =0 ;i<n && getline(cin,s);i++)
    {
        if(s[0] == 'R')
        {
            if(head == nullptr)
            {
                if(s == "Run") s = "";
                else s = s.substr(4);
                head = new Node(s);
                help = new Node("",head);
                head->next = help;
            }
            else
            {
                if(s == "Run") s = "";
                else s = s.substr(4);
                head = new Node(s,head);
                help->next = head;
            }
            cout<<head->data<<endl;
        }
        else
        {
            
            Node*curr = head;
            Node * predcurr = help;
            for(size_t j = 4;j<s.size();j+=4)
            {
                predcurr = predcurr->next;
                curr = curr->next;
                if(curr == help) {curr = head;predcurr = help;}
            }
            cout<<curr->data<<endl;
            if(curr!=head)
            {
                head = new Node(curr->data,head);
                help->next = head;
                predcurr->next = curr->next;
                delete curr;
            }
        }
    }
}