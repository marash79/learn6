
#include <iostream>
#include "Queue.h"

void loop()
{
    Queue myq;
    int choice;
    
    while (true)
    {
        int tmp;
        printf("Choose 1- add element;2-remove element;3-exit;4-Clear\n");
        do
        {
            scanf_s("%i", &choice);
        } while (choice < 1 || choice>4);

        switch (choice)
        {
        case 1:
            printf("Enter the valuez");
            scanf_s("%i", &tmp);
            push(myq, tmp);
            break;

        case 2:
            tmp = pull(myq);
            printf("removed element %i\n", tmp);
            break;
        case 4:
            clearQueue(myq);
            break;
        case 3:
            return;
       
        }
        print(myq);
    }   

}

int main()
{
    loop();
    system("pause");
    return 0;
}
