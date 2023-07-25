#ifndef _MODULE_H
#define _MODULE_H

class Stack

{

public:
  
    int size;
    int temp;

    Stack() = default;
    Stack(int size);
    int push(int element);
    int pop(int &element);
    bool is_empty();
    bool is_full();

private:
  int *Buffer;
    int top;

};
#endif