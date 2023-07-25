
#include "module.h"
#include<iostream>
Stack::Stack(int _size):size(_size){

// ...

// std::cout<<_size+size+3;
Buffer=new int(size);
top=0;
}

int Stack::push(int element){
    if(top!=size){
        Buffer[top++]=element;
        temp=top;
        
    }
    else{
        return -1;
    }
        return 1;
}

int Stack::pop(int & element){
    if(top==0){
    return -1;
    }
    else{

        element=Buffer[--top];
        temp=top;
        // std::cout<<"The element is "<<Buffer[top-1]<<std::endl;
        return 1;
    }
}

bool Stack::is_empty(){
    if(top!=0)
        return false;
    return true;
}
bool Stack::is_full(){
    if(top==size)
    {
        return true;
    }

return false;
}