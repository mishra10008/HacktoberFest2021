#include <iostream>
using namespace std;

class CQueue
{
private:
    int *arr;
    int size, front, rear;

public:
    CQueue()
    {
        size = 3;
        arr = new int[size];
        front = rear = -1;
    }

    CQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        return false;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "\nCircular Queue Overflow" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear=(rear+1)%size;
            arr[rear] = val;
            cout << "\n"<< val << " is Enqueued to the Queue" << endl;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "\nQueue Underflow" << endl;
            return -1;
        }
        else
        {
            int val = arr[front];
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{
                front = (front + 1) % size;
            }
            cout << "\n"<< val << " is Dequeued from the Queue" << endl;
            return val;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nQueue Underflow. \nNo elements present to display." << endl;
        }
        else
        {
            cout << "\nPrinting all the elements of the Queue: " << endl;
            int it = front;
            while (it != rear)
            {
                cout << "\t>> " << arr[it] << endl;
                it = (it + 1) % size;
            }
            cout << "\t>> " << arr[it] << endl;
        }
    }

    int count()
    {
        if (isEmpty())
        {
            return 0;
        }
        int it = front, counter = 0;
        while (it != rear)
        {
            it=(it+1)%size;
            counter++;
        }
        counter++; // this last increment is for rear element
        return counter;
    }
};

int main()
{

    CQueue q1;
    int value, op;

    while (1)
    {
        cout << "\n\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> op;

        switch (op)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            if (q1.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;
        case 5:
            cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper option number " << endl;
        }
    }

    return 0;
}
