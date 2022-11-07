#include <iostream>

class Node
{
public:
    std::string data;
    Node *left;
    Node *right;
    int counter = 1;

    Node(std::string data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    void add(std::string value)
    {
        if (value < this->data)
        {
            if (left == NULL)
            {
                left = new Node(value);
            }
            else
            {
                left->add(value);
            }
        }
        else if (value > this->data)
        {
            if (right == NULL)
            {
                right = new Node(value);
            }
            else
            {
                right->add(value);
            }
        }
        else
        {
            counter++;
        }
    }

    void printInOrder()
    {
        if (left != NULL)
        {
            left->printInOrder();
        }
        for (int i = 0; i < counter; i++)
        {
            std::cout << data << "\n";
        }
        if (right != NULL)
        {
            right->printInOrder();
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int nrOfOperations = 0;
    std::string word;
    //std::cout << "Enter number of operations: ";
    std::cin >> nrOfOperations;
    //std::cout << "Enter root word: ";
    std::cin >> word;
    Node tree = Node(word);
    for (int i = 0; i < nrOfOperations-1; i++)
    {
        std::cin >> word;
        tree.add(word);
    }
    tree.printInOrder(); // Should recursevly print the tree in order
    return 0;
}