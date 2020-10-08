//
// Created by Aboubakr on 9/25/2020.
//
#include <iostream>
using namespace std;
//int invertNumber(int n){
//    int reverse=0,rem;
//    while(n!=0)
//    {
//        rem=n%10;
//        reverse=reverse*10+rem;
//        n/=10;
//    }
//    return reverse;
//}
template<typename T>
class LinkedList{
private:
    class Node{
    public:
        T _data;
        Node* _nxt;
        Node()
        {
            _data = T();
            _nxt = nullptr;
        }
    };

    Node* _head;
    Node* _tail;
    int _size;
public:
    LinkedList(){
        _head=_tail= nullptr;
        _size = 0;
    }
    void push_front(const T& val){
        Node* temp = new Node();
        temp->_data = val;
        temp->_nxt = _head;
        if(_head== nullptr) _tail= temp;
        _head = temp;
        _size++;
    }
    void push_back(const T& val){
        Node* temp = new Node();
        temp->data = val;
        temp->_nxt = nullptr;
        if(_tail!= nullptr) _tail->_nxt = temp;
        _tail = temp;
        if(_head== nullptr) _head= temp;
        _size++;
    }
    bool empty(){
        return _head == nullptr;
    }
    T front(){
        return _head->_data;
    }
    T back(){
        return _tail->_data;
    }
    void pop_front(const T& val){
        Node* temp = new Node();
       _head = _head->_nxt;
       if(_head== nullptr) _tail= nullptr;
        delete temp;
        _size--;
    }
    void insert(int idx, const T& val){
        if(idx == 0)push_front(val);
        else if (idx >= _size)push_back(val);
        else{
            Node* temp = new Node();
            temp->_data=val;
            Node* j = _head;
            for(int i = 0; i < idx-1 ; ++i)  j = j->_nxt;

            temp->_nxt = j->_nxt;
            j->_nxt = temp;
        }
        _size++;
    }
    void clear(){
        while (_head != nullptr){
            Node* temp = _head;
            _head = _head->_nxt;
            delete temp;
        }
        _size = 0;
    }


    virtual ~LinkedList() {
        clear();
    }

};





int main()
{

    LinkedList<int> ll;
    ll.push_front(10);
    ll.push_front(9);
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);

    cout<<ll.front()<<endl;
    cout<<ll.back()<<endl;






//    int n, reverse=0, rem;
//    cout<<"Enter a number: ";
//    cin>>n;
//    while(n!=0)
//    {
//        rem=n%10;
//        reverse=reverse*10+rem;
//        n/=10;
//    }


//    cout<<"Reversed Number: "<<invertNumber(n)<<endl;
    return 0;
}
