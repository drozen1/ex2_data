//
// Created by Dor on 04/05/2020.
//

#ifndef EX1_DATASTRUCK_DOUBLY_LINKED_LIST_H
#define EX1_DATASTRUCK_DOUBLY_LINKED_LIST_H

#include "Link_node.h"

namespace AVL {

    using namespace AVLUtils;
    template<class T>
    class Doubly_Linked_List {
    private:
        Link_Node<T>* Head;
        Link_Node<T>* Last;
    public:
        Doubly_Linked_List();
        Link_Node<T> *searchForNode(int) const ;

        Doubly_Linked_List(Link_Node<T> *head);

        virtual ~Doubly_Linked_List();

        Link_Node<T> *getHead() const;

        void setHead(Link_Node<T> *head);

        Link_Node<T> *getLast() const;

        void setLast(Link_Node<T> *last);

       void setNewNodeAfterNode(Link_Node<T> *push_after_node,Link_Node<T>* newNode);

       void removeNodeFromList(Link_Node<T>* node_to_remove);
    };

    template<class T>
    Doubly_Linked_List<T>::Doubly_Linked_List():Head(NULL),Last(NULL) {

    }

    template<class T>
    Doubly_Linked_List<T>::Doubly_Linked_List(Link_Node<T> *head):Head(head) {}

    template<class T>
    Doubly_Linked_List<T>::~Doubly_Linked_List(){
        Link_Node<T>* current = this->getHead();
        Link_Node<T>* prev = NULL;
        while(current != NULL){
            delete(current->getElement());
            current->setElement(NULL);
            prev = current;
            current = current->getNext();
            delete (prev);

        }
        this->setHead(NULL);
        this->setLast(NULL);
    }

    template<class T>
    Link_Node<T> *Doubly_Linked_List<T>::getHead() const {
        return Head;
    }

    template<class T>
    void Doubly_Linked_List<T>::setHead(Link_Node<T> *head) {
        Head = head;
    }

    template<class T>
    Link_Node<T> *Doubly_Linked_List<T>::getLast() const {
        return Last;
    }

    template<class T>
    void Doubly_Linked_List<T>::setLast(Link_Node<T> *last) {
        Last = last;
    }

    /**
     * in case node==NULL we want to push in the head
     * @tparam T
     * @param push_after_node
     * @param newNode- the address of the new node..
     */
    template<class T>
    void Doubly_Linked_List<T>::setNewNodeAfterNode(Link_Node<T> *push_after_node,Link_Node<T>* newNode) {
        ///treat head is newNode
        if (push_after_node==NULL){
            if(this->getHead()!=NULL) {
                newNode->setNext(this->getHead());
                this->getHead()->setPrev(newNode);
                this->getHead()->setPrev(newNode);
            }
            else{
                setLast(newNode);
                newNode->setNext(NULL);                                ////////////////ADD THIS ONE ??
            }
            this->setHead(newNode);
            newNode->setPrev(NULL);                                ////////////////ADD THIS ONE ??
            return;

        }
        ///treat last
        if (push_after_node->getNum()==getLast()->getNum()){
            push_after_node->setNext(newNode);
            setLast(newNode);
            newNode->setPrev(push_after_node);
            newNode->setNext(NULL);                                ////////////////ADD THIS ONE ??
            return;
        }
        ///treat middle case
        Link_Node<T>* push_before_node=push_after_node->getNext();
        push_after_node->setNext(newNode);
        newNode->setPrev(push_after_node);
        push_before_node->setPrev(newNode);
        newNode->setNext(push_before_node);
        return;

    }

    template<class T>
    void Doubly_Linked_List<T>::removeNodeFromList(Link_Node<T> *node_to_remove) {
            if (node_to_remove->getElement()!= NULL) {
                delete (node_to_remove->getElement());
            }
            if (node_to_remove->getNum() == getHead()->getNum() && node_to_remove->getNum() == getLast()->getNum()){
                this->setHead(NULL);
                this->setLast(NULL);
                delete(node_to_remove);
                return;
            }
            if (node_to_remove->getNum() == getHead()->getNum()){
                setHead(node_to_remove->getNext());
                node_to_remove->getNext()->setPrev(NULL);
                delete(node_to_remove);
                return;
            }
            if (node_to_remove->getNum() == getLast()->getNum()){
                setLast(node_to_remove->getPrev());
                if (node_to_remove->getPrev()!=NULL) {
                    node_to_remove->getPrev()->setNext(NULL);
                }
                delete(node_to_remove);
                return;
            }
            Link_Node<T>* prev = node_to_remove->getPrev();
            Link_Node<T>* next = node_to_remove->getNext();
            if (prev!=NULL) {
                prev->setNext(next);
            }
            if (next!=NULL) {
                next->setPrev(prev);
            }
            delete(node_to_remove);
             return;


    }

    template<class T> //returns NULL if a node with the wanted ID wasn't found
    Link_Node<T> *Doubly_Linked_List<T>::searchForNode(int ID) const {
        for(Link_Node<T>* curr = getHead(); curr !=NULL; curr = curr->getNext()){
            if (curr->getNum() == ID){
                return curr;
            }
        }
        return NULL;
    }


}

#endif //EX1_DATASTRUCK_DOUBLY_LINKED_LIST_H
