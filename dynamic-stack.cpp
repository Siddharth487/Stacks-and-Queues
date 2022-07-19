#include "dynamic-stack.h"
//
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    size_ = 0;
    capacity_ = 16;
    items_ = new int[capacity_];
    init_capacity_ = capacity_;
}

DynamicStack::DynamicStack(unsigned int capacity){
    size_ = 0;
    capacity_ = capacity;
    items_ = new int[capacity_];
    init_capacity_ = capacity_;
}

DynamicStack::~DynamicStack() {
    delete [] items_;
    items_ = nullptr;
}


unsigned int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    if(size_ == 0)
        return true;
    return false;
}

DynamicStack::StackItem DynamicStack::peek() const {
    if(size_ == 0){
        cout <<"stack is empty! nothing to peek." <<endl;
        return EMPTY_STACK;  // EMPTY STACK return constant
    }
    else{//Step 2: just return the top value data
        return items_[size_-1];
    }
}

void DynamicStack::push(StackItem value) {
        if(size_ == capacity_){
            cout<<"stack cap is reached, double its size." <<endl;
            StackItem *newItems = new StackItem [2*capacity_];
            capacity_ = 2*capacity_;
            for(int i = 0; i < size_; i++){
                newItems[i] = items_[i];
            }
            int *temp = items_;
            items_ = newItems;
            newItems[size_] = value;
            delete [] temp;
        }

        items_[size_] = value;
        size_++;



}

DynamicStack::StackItem DynamicStack::pop() {
    DynamicStack::StackItem element;
    if(size_ <= 0){
        cout<<"stack is empty! cannot pop." <<endl;
        return EMPTY_STACK;  //EMPTY STACK return constant
    }
    else{
        element = items_[size_-1];
       //items_[size_-1] = EMPTY_STACK;
       size_--;
    }
    if(size_ <= capacity_/4 && capacity_/2 >= init_capacity_)
    {

        StackItem* newItems = new int[capacity_/2];
        for(int i = 0; i < size_; i++)
        {
            newItems[i] = items_[i];
        }
        delete[] items_;
        items_ = newItems;


    }

    return element;

}

void DynamicStack::print() const {
    if(empty()){
        cout<<"stack is empty! nothing to print." <<endl;
        return;
    }
    else{
        for(unsigned int i=size_; i > 0; i--)
        {
            cout << items_[i] << ", ";
        }
        }
        cout<<endl;
    }

