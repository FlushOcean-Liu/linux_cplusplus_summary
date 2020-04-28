#include <stdio.h>
#include <iostream>

namespace A{
    int x=10;
    void print(){
        printf("A::x=%d\n",x);
    }
}

namespace B{
    int x=20;
    void print(){
        printf("B::x=%d\n",x);
    }
}

int x=30;
void print(){
    printf("x=%d\n",x);
}

int main()
{
    int x=40;
    printf("main:x=%d\n",x);
    printf("È«¾Ö:x=%d\n",::x);
    printf("ÃüÃû¿Õ¼äA:x=%d\n",A::x);
    printf("ÃüÃû¿Õ¼äB:x=%d\n",B::x);
    A::print();
    B::print();
    
    return 0;
}
