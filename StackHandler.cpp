#include <iostream>
#include <stack>
#include <ctime>

using namespace std;

void fillStack(stack <int>* emptyStack)
{
    srand((int)time(0));

    for (int index = 0; index < 20; index++)
    {
        int number = rand() % 19 - 9;
        emptyStack->push(number);
    }
}

void interateStack(stack <int> numbersStack)
{
    while (!numbersStack.empty())
    {
        int number = numbersStack.top();
        cout << number << endl;
        numbersStack.pop();
    }
}

void removeEven(stack <int>* numbersSatack)
{
    stack <int> tempStack;

    while (!numbersSatack->empty())
    {
        int number = numbersSatack->top();
        if (number % 2 != 0) {
            tempStack.push(number);
        }
        numbersSatack->pop();
    }

    while (!tempStack.empty())
    {
        numbersSatack->push(tempStack.top());
        tempStack.pop();
    }
}

void sort(stack <int>* numbersSatack)
{
    int size = numbersSatack->size();
    stack <int> tempStack1;
    while (!numbersSatack->empty())
    {
        tempStack1.push(numbersSatack->top());
        numbersSatack->pop();
    }

    stack <int> tempStack2;

    for (int index = 0; index < size; index++)
    {
        if (index % 2 == 0)
        {
            while (!tempStack1.empty())
            {
                int temp1 = tempStack1.top();
                tempStack1.pop();

                if (tempStack2.empty())
                {
                    tempStack2.push(temp1);
                }
                else
                {
                    int temp2 = tempStack2.top();
                    if (temp2 > temp1)
                    {
                        tempStack2.pop();
                        tempStack2.push(temp1);
                        tempStack2.push(temp2);
                    }
                    else
                    {
                        tempStack2.push(temp1);
                    }
                }
            }

            numbersSatack->push(tempStack2.top());
            tempStack2.pop();
        }
        else
        {
            while (!tempStack2.empty())
            {
                int temp1 = tempStack2.top();
                tempStack2.pop();

                if (tempStack1.empty())
                {
                    tempStack1.push(temp1);
                }
                else
                {
                    int temp2 = tempStack1.top();
                    if (temp2 > temp1)
                    {
                        tempStack1.pop();
                        tempStack1.push(temp1);
                        tempStack1.push(temp2);
                    }
                    else
                    {
                        tempStack1.push(temp1);
                    }
                }
            }

            numbersSatack->push(tempStack1.top());
            tempStack1.pop();
        }
    }
}

int main()
{
    stack <int> numbersStack;
    fillStack(&numbersStack);
    interateStack(numbersStack);

    cout << endl << "-----------------------------------------" << endl << endl;

    sort(&numbersStack);
    interateStack(numbersStack);

    cout << endl << "-----------------------------------------" << endl << endl;

    removeEven(&numbersStack);
    interateStack(numbersStack);
}
