#include <iostream>
#include "queue.hpp"

using namespace std;

Queue::Queue(){
    size = 0;
    last = nullptr;
    first = nullptr;
}

Queue::Queue(int el)
{
    Item* new_unit = new Item;
    new_unit->data = el;
    new_unit->prev = last;
    first = new_unit;
    last = nullptr;
    size = 1;
}

Queue::Queue(const Queue& Queue_copy) : size(Queue_copy.size)
{
    int* buff = new int[Queue_copy.size]; // буфферный массив, в к-ом хранятся числа новой очереди
    Item* el_queue = Queue_copy.last;

    for (int i = 0; i <= Queue_copy.size - 1; i++)
    {
        buff[i] = el_queue->data;
        el_queue = el_queue->prev;
    }

    for (int i = 0; i < Queue_copy.size; i++)
        this->push(buff[i]);
    delete[] buff;
}

Queue::~Queue(){
    while (size > 0){
        Item* temp = last;
        last = temp->prev;
        delete temp;
        size--;
    }
}

Item* Queue::get_last() { return last; }

void Queue::print(){
    if (size == 1 ) { cout << first->data << endl; return; }

    Item* tmp = last;
    
    while (tmp->prev != first)
    {
        cout << tmp->data << " -> ";
        tmp = tmp->prev;
    }
    cout << tmp->data << " -> ";
    cout << first->data << endl;
}

bool Queue::operator!() const {
    if ( size == 0 ){
        return true;
    }
    else{
        return false;
    }
}

void Queue::push(int el) {
    Item* new_unit = new Item;
    if (size == 1)
    {
        new_unit->data = el;
        new_unit->prev = first;
        last = new_unit;
        size++;
        return;
    }
    new_unit->prev = last;
    last = new_unit;
    last->data = el;
    first->prev = last;
    size++;
}



int Queue::pop() {
    Item* tmp = first;
    int deldata;
    deldata = tmp->data;
    if (size == 1)
    {
        last = nullptr;
        first = nullptr;
        size = 0;
        return deldata;
    }
    tmp = last;
    while (tmp->prev != first)
    {
        tmp = tmp->prev;
    }

    delete tmp->prev;
    tmp->prev = last;
    first = tmp;
    push(deldata);
    size--;
    return deldata;
}

int Queue::del(){
    Item* tmp = first;
    int deldata;
    deldata = tmp->data;
    if (size == 1)
    {
        last = nullptr;
        first = nullptr;
        size = 0;
        return deldata;
    }
    tmp = last;
    while (tmp->prev != first)
    {
        tmp = tmp->prev;
    }

    delete tmp->prev;
    tmp->prev = last;
    first = tmp;
    push(deldata);
    size--;
    return deldata;
}

Queue& Queue::operator++() {
    int tmp;
    cout << "Enter value" << endl;
    cin >> tmp;
    push(tmp);
    return *this;
}

void operator-- (Queue& Q){
    if (Q.size == 0)
    {
        cout << "queue is empty" << endl;
    }
    cout << Q.pop() << endl;
}

Queue& Queue::operator--(int){
    if (size == 0)
    {
        cout << "queue is empty" << endl;
    }
    cout << del() << " -> " << del() << endl;
    return *this;
}

void operator++ (Queue& Q, int){
    int a,b;
    cout << "Enter values" << endl;
    cin >> a >> b;
    Q.push(a);
    Q.push(b);
    Q.print();
}
