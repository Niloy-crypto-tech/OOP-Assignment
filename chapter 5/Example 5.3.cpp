#include <bits/stdc++.h>
using namespace std;
const int M = 50;

class items
{
    int itemCode[M];
    float itemPrice[M];
    int count;

public:
    void cnt()
    {
        count = 0;
    }

    void getItem()
    {
        cout << "Enter item code: ";
        cin >> itemCode[count];

        cout << "Enter item cost: ";
        cin >> itemPrice[count];
        count++;
    }

    void displaySum()
    {
        float sum = 0;
        for (int i = 0; i < count; i++)
        {
            sum += itemPrice[i];
        }
        cout << "Total value: " << sum << endl;
    }

    void remove()
    {
        int a;
        cout << "enter item code : ";
        cin >> a;

        for (int i = 0; i < count; i++)
        {
            if (itemCode[i] == a)
                itemPrice[i] = 0;
        }
    }

    void displayItems()
    {
        cout << "Code\tPrice" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << itemCode[i] << "\t" << itemPrice[i] << endl;
        }
    }
};

int main()
{
    items order;
    order.cnt();
    int x;

    do
    {
        cout << "\nYou can do the following:" << endl;
        cout << "1 : Add an item" << endl;
        cout << "2 : Display total value" << endl;
        cout << "3 : Remove an item" << endl;
        cout << "4 : Display all items" << endl;
        cout << "5 : Quit" << endl;

        cin >> x;

        switch (x)
        {
        case 1:
            order.getItem();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displayItems();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Error: Invalid choice!" << endl;
        }

    } while (x != 5);

    return 0;
}
