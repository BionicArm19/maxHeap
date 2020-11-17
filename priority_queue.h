#include <iostream>
#include <vector>

using namespace std;

class priority_queue
{
private:
    vector<string> tree;
    int maxCapacity;
    int heap_size;

public:
    priority_queue(int max);

    int parent(int pos);
    int leftBoy(int pos);
    int rightBoy(int pos);
    bool isLeaf(int pos);

    void enqueue(string data);
    void dequeue(int pos);
    int Peek();
    bool isEmpty();
    int getSize();
};

priority_queue::priority_queue(int max)
{
    maxCapacity = max;
    heap_size = 0;
}

int priority_queue::parent(int pos)
{
    return (pos - 1) / 2;
}

int priority_queue::leftBoy(int pos)
{
    return 2 * pos + 1;
}

int priority_queue::rightBoy(int pos)
{
    return 2 * pos + 2;
}

bool priority_queue::isLeaf(int pos)
{
    if (pos > heap_size / 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Adds element to the heap
 * O(log n)
 * @param data 
 */
void priority_queue::enqueue(string data)
{
    if (tree.size() == maxCapacity)
    {
        cout << "No se puede insertar" << endl;
    }
    else
    {
        heap_size++;
        int pos = heap_size - 1;
        tree.push_back(data);
        while (pos != 0 && tree[parent(pos)] < tree[pos])
        {
            string temp = tree[parent(pos)];
            tree[parent(pos)] = tree[pos];
            tree[pos] = temp;
            pos = parent(pos);
        }
    }
}

/**
 * @brief deletes the content of the pisition given
 * O(log n)
 * @param pos 
 */
void priority_queue::dequeue(int pos)
{
    //Swap first and last
    tree[0] = tree[heap_size];
    tree.pop_back();

    int left = leftBoy(pos);
    int right = rightBoy(pos);

    while (isLeaf(pos) == false)
    {
        int largest = pos;

        if (left < tree.size() && tree[left] > tree[right])
        {
            largest = left;
        }
        if (right < tree.size() && tree[right] > tree[left])
        {
            largest = right;
        }
        if (tree[pos] < tree[largest])
        {
            swap(tree[pos], tree[largest]);
        }
        else
        {
            break;
        }
    }
    /*
    int largest = pos;

    if (left < tree.size() && tree[left] > tree[right])
    {
        largest = left;
    }
    if (right < tree.size() && tree[right] > tree[left])
    {
        largest = right;
    }
    if (largest != pos)
    {
        swap(tree[pos], tree[largest]);
        dequeue(largest);
    }*/
}

/**
 * @brief Returns root element
 * 0(1)
 * @return int 
 */
string priority_queue::Peek()
{
    return tree[0];
}

/**
 * @brief Returns true if heao is empty
 * O(1)
 * @return true 
 * @return false 
 */
bool priority_queue::isEmpty()
{
    return tree.empty();
}

/**
 * @brief Returns size of heap
 * O(1)
 * @return int 
 */
int priority_queue::getSize()
{
    return tree.size();
}
