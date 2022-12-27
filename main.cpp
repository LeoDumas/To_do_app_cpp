#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "ToDo.cpp"

int main(){
    ToDoApp app;
    app.afficherTop();
    app.afficherMenuBase();

    system("pause");
    return 0;
}