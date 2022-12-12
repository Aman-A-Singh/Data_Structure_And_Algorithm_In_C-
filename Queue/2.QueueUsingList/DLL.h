#pragma once

#include <memory>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>

namespace myLib
{
    template <typename T>
    class DoubleLinearList
    {
    private:
        struct Node
        {
            T element;                  // record to be stored in the list node
            std::shared_ptr<Node> next; // pointer to the next node
            std::weak_ptr<Node> prev;   // pointer to the previous node
            /*Default No-Arg Ctor for Node*/
            Node();
            /*sets the next and previous pointers to nullptr*/
            void reset_node();
            /*Parameterized Ctor*/
            Node(const T &other);
            // Copy Ctor
            Node(const Node &other) = default;
            /*Node Destructor*/
            ~Node();
        };
        std::shared_ptr<Node> head;
        std::weak_ptr<Node> tail;
        size_t number_of_nodes;

    public:
        /*Default No-Arg Constructor*/
        DoubleLinearList();
        /*Destructor*/
        virtual ~DoubleLinearList();
        /*Append (add to end ) the Node to the List*/
        void push_back(const T &);
        /* Insert new node at the begining of the list*/
        void push_front(const T &);
        /*Prints the Nodes from the List in forward direction*/
        void printForward();
        /*Prints the Nodes from the List in reverse direction*/
        void printReverse();
        /*Returns true if the list is empty otherwise returns false*/
        bool isEmpty();
        /*Delete the Node from the List by Position*/
        bool remove(size_t position);
        /*Delete the Node from the List by comparing the record*/
        bool remove(T &record);
        /*Search for the record in the list. On success returns shared_ptr
        Pointing to the book and on failure returns nullptr*/
        auto search(T &record);
        /*Reset the List making it empty*/
        void resetList();
        /*Remove a element (record) from the begining of the DLL list*/
        T pop_front();
        /*Remove a element (record) from the end of the DLL list*/
        T pop_back();
        /* Return a copy of the first element in the DLL*/
        T front();
        /*Return a copy of the last element in the DLL*/
        T back();
        /*Returns the number of nodes in the List*/
        size_t count_nodes();
    };

    /*Parameterized Ctor for Node*/
    template <typename T>
    DoubleLinearList<T>::Node::Node(const T &other)
    {
        this->element = other;
        reset_node();
    }

    /*Node Destructor*/
    template <typename T>
    DoubleLinearList<T>::Node::~Node()
    {
        reset_node();
    }

    /*Default No-Arg Ctor for Node*/
    template <typename T>
    DoubleLinearList<T>::Node::Node()
    {
        reset_node();
    }

    template <typename T>
    void DoubleLinearList<T>::Node::reset_node()
    {
        next.reset(); // shared pointer to the next node
        prev.reset(); // weak pointer to the previous node
    }

    template <typename T>
    DoubleLinearList<T>::DoubleLinearList()
    {
        number_of_nodes = 0;
    }

    template <typename T>
    DoubleLinearList<T>::~DoubleLinearList()
    {
        resetList();
        number_of_nodes = 0;
    }

    template <typename T>
    void DoubleLinearList<T>::push_back(const T &record)
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(record);

        if (isEmpty())
        {
            head = newNode; // Make the newnode the first Node if the list is empty
        }
        else
        {
            /*Next of current last node is pointing to newnode*/
            tail.lock()->next = newNode;
            /*New node's previous is made to point to Current last node*/
            newNode->prev = tail;
        }
        // Tail always points to the last node (newNode)
        tail = std::weak_ptr<Node>(newNode); // New node becomes the new last node
        number_of_nodes++;
    }

    template <typename T>
    inline void DoubleLinearList<T>::push_front(const T &record)
    {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(record);

        if (isEmpty())
        {
            // Make the new node the last node
            tail = std::weak_ptr<Node>(newNode);
        }
        else
        {
            /*Current first nodes prev is pointing to newnode*/
            head->prev = std::weak_ptr<Node>(newNode);
            /*New node's next is made to point to Current first node*/
            newNode->next = head;
        }
        // Head always points to the new node (newNode)
        head = newNode;
        number_of_nodes++;
    }

    template <typename T>
    void DoubleLinearList<T>::printForward()
    {
        if (isEmpty())
        {
            std::cout << "List is empty!" << std::endl;
        }
        else
        {
            std::shared_ptr<Node> ptr = head;
            while (ptr)
            {
                std::cout << ptr->element << ", ";
                ptr = ptr->next;
            }
        }
    }

    template <typename T>
    void DoubleLinearList<T>::printReverse()
    {
        if (isEmpty())
        {
            std::cout << "List is empty!" << std::endl;
        }
        else
        {
            std::shared_ptr<Node> ptr = tail.lock();
            while (ptr)
            {
                std::cout << ptr->element << ", ";
                ptr = ptr->prev.lock();
            }
        }
    }

    template <typename T>
    bool DoubleLinearList<T>::isEmpty()
    {
        return !(head && tail.lock());

        // return number_of_nodes == 0;
    }

    template <typename T>
    inline bool DoubleLinearList<T>::remove(size_t position)
    {
        if (position > number_of_nodes)
        {
            std::ostringstream msg{};
            msg << "The Position is out of range, the List containg only " << number_of_nodes << " nodes\n";
            throw std::out_of_range(msg.str());
        }

        /*If the node to be deleted is the first node*/
        if (position == 1)
        {
            /*if the list contains only one node*/
            if (head == tail.lock())
            {
                /*head = nullptr;
                tail = nullptr;*/
                resetList();
            }
            else
            {
                /*Make second node in the list the first node*/
                head = head->next;
            }
        }
        else
        {
            /* Make pointer point to the first node */
            std::shared_ptr<Node> ptr = head;
            /*Traverse the pointer to the position of the node to be deleted*/
            for (size_t counter{1}; counter < position; ++counter)
            {
                ptr = ptr->next;
            }
            if (ptr == tail.lock())
            {
                /*Penultimate node is made the last node*/
                tail = tail.lock()->prev;
            }
            else
            {
                /*The next nodes previous is made to point to the previous of the node to be deleted*/
                ptr->next->prev = ptr->prev;
            }
            // Previous nodes next is made to point to next node of the node to be deleted*/
            (ptr->prev.lock())->next = ptr->next;
        }
        number_of_nodes--;
        return true;
    }

    template <typename T>
    inline bool DoubleLinearList<T>::remove(T &record)
    {
        if (isEmpty())
        {
            throw std::out_of_range("The List is empty!");
        }
        // Executes if the list is not empty
        auto ptr = search(record);
        if (!ptr)
        { // if the record is not found
            return false;
        }

        if (head == tail.lock())
        { // if the list contains only single record
            resetList();
        }
        else
        {
            // if the node to be deleted is the first node in the list
            if (head == ptr)
            {
                head = head->next; // make head point the the second node
                // reset second node's prev
                head->prev.reset();
            }
            else
            {
                // if the node to be deleted is the last node in the list
                if (tail.lock() == ptr)
                {
                    // make tail point to the penultamate node
                    tail = tail.lock()->prev;
                    // reset tail's next
                    tail.lock()->next.reset();
                }
                else
                {
                    // if the node to be deleted is a node in between
                    (ptr->prev).lock()->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }
            }
        }
        /*Not necessary : Since ptr is local shared pointer which will go out of scope */
        // ptr.reset();
        number_of_nodes--;

        return true;
    }

    template <typename T>
    inline auto DoubleLinearList<T>::search(T &record)
    {
        std::shared_ptr<Node> ptr = nullptr;
        if (!isEmpty())
        {

            ptr = head;
            while (ptr != nullptr)
            {
                if (ptr->element == record)
                {
                    return ptr;
                }
                ptr = ptr->next;
            }
        }
        return ptr;
    }

    template <typename T>
    inline void DoubleLinearList<T>::resetList()
    {
        head.reset();
        tail.reset();
    }

    template <typename T>
    inline T DoubleLinearList<T>::pop_front()
    {
        if (isEmpty())
        {
            throw std::underflow_error("The List is empty!");
        }

        std::shared_ptr<Node> ptr = head;
        /* The list constains only one node*/
        if (head == tail.lock())
        {
            resetList();
        }
        else
        {
            /*Set the current second nodes prev as nullptr*/
            head->next->prev.reset();
            /* Make the second node the first node*/
            head = head->next;
        }
        number_of_nodes--;
        return ptr->element;
    }

    template <typename T>
    inline T DoubleLinearList<T>::pop_back()
    {
        if (isEmpty())
        {
            throw new std::underflow_error("The List is empty!");
        }

        /*Make ptr point to last node's element*/
        std::shared_ptr<Node> ptr = tail.lock();
        /* The list constains only one node*/
        if (head == tail.lock())
        {
            resetList();
        }
        else
        {
            /*Set the current secondlast node's next to nullptr */
            tail.lock()->prev.lock()->next = nullptr;
            /* Make the secondlast node the last node*/
            tail = tail.lock()->prev;
        }
        number_of_nodes--;
        return ptr->element;
    }

    template <typename T>
    inline T DoubleLinearList<T>::front()
    {
        if (isEmpty())
        {
            throw std::underflow_error("List is empty!");
        }
        return head->element;
    }

    template <typename T>
    inline T DoubleLinearList<T>::back()
    {
        if (isEmpty())
        {
            throw std::underflow_error("List is empty!");
        }
        return tail.lock()->element;
    }

    template <typename T>
    inline size_t DoubleLinearList<T>::count_nodes()
    {
        return number_of_nodes;
    }
}