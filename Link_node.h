//
// Created by Dor on 04/05/2020.
//

#ifndef EX1_DATASTRUCK_LINK_NODE_H
#define EX1_DATASTRUCK_LINK_NODE_H


#include <ostream>

namespace AVL {

    using namespace AVLUtils;
    template<class T>
    class Link_Node {
    public:
        Link_Node(int num) : num(num),next(NULL),prev(NULL) {}

        Link_Node(int num, T *element) :
        num(num), element(element),next(NULL),prev(NULL) {}

        int getNum() const {
            return num;
        }

        void setNum(int num) {
            Link_Node::num = num;
        }

        void setElement(T* element) {
            Link_Node::element = element;
        }

        void setNext(Link_Node<T> *next) {
            Link_Node::next = next;
        }

        void setPrev(Link_Node<T> *prev) {
            Link_Node::prev = prev;
        }

        T* getElement() const {
            return element;
        }

        Link_Node<T> *getNext() const {
            return next;
        }

        Link_Node<T> *getPrev() const {
            return prev;
        }


        virtual ~Link_Node() {
        }

        friend std::ostream &operator<<(std::ostream &os, const Link_Node &node) {
            os << "num: " << node.num;
            return os;
        }

    private:
        int num;
        T* element;
        Link_Node<T>* next;
        Link_Node<T>* prev;

    };


}



#endif //EX1_DATASTRUCK_LINK_NODE_H
