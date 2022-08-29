#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class Stack
{
public:
    Node* head;
    Node* top;
    int cnt;
    Stack(){
        this->head = NULL;
        this->top = NULL;
        this->cnt = 0;
    }
    void Push(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = top = newNode;
            cnt++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        cnt++;
    }
    int Pop(){
        Node* delNode = top;
        int popVal = -1;
        if(top==NULL){
            return popVal;
        }
        if(top==head){
            top = head = NULL;
        }
        else{
            top = delNode->prev;
            top->next = NULL;
        }
        popVal = delNode->val;
        delete delNode;
        cnt--;
        return popVal;
    }
    bool isEmpty()
    {
        if(head==NULL) return true;
        else return false;
    }
};




int main()
{
    int n;
    cin>>n;
    Stack st;
    int aNum;
    int totalCnt = 0;
    for(int i=0;i<n;i++){
        cin>>aNum;
        st.Push(aNum);
        totalCnt++;
        if(totalCnt<=1) continue;
        Node* temp = st.top;
        int count = 0;
        int delCount = 1;
        while(temp!=NULL){
            count += temp->val;
            if(count != 0){
                delCount++;
            }
            else if(count==0){
                totalCnt-=delCount;
                while(delCount>=1){
                    st.Pop();
                    delCount--;
                }
                break;
            }
            temp = temp->prev;
        }

    }
    if(st.isEmpty()){
        cout<<"The list is empty"<<endl;
        return 0;
    }
    Node* newTemp = st.head;

    while(newTemp!=NULL){
        cout<<newTemp->val;
        if(newTemp->next!=NULL) cout<<"->";
        newTemp=newTemp->next;
    }
    return 0;
}
