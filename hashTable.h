//
// Created by Dor on 09/06/2020.
//

#ifndef EX2_HASH_HASHTABLE_H
#define EX2_HASH_HASHTABLE_H

#include "Rank_tree.h"
#include "AVL_types.h"
#include "Doubly_linked_list.h"
#include <math.h>

namespace AVL {

    using namespace AVLUtils;

    template<class T>
    class HashTable{
    private:

        Doubly_Linked_List<T>** table;
        int size_of_array;
        int num_of_members;
        const int alpha_min=1;
        const int alpha_max=2;

    public:
        StatusType addToTable (int member_id);
        StatusType removeFromTable (int member_id);
        StatusType reHash();
        Link_Node<T>* retrieve_member(int member_id);
        StatusType multiply_size();
        StatusType divide_size();
        int hashFunction(int member_id);



        HashTable(int sizeOfArray=2) : size_of_array(sizeOfArray),num_of_members(0) {
            table= new Doubly_Linked_List<T>*[size_of_array];
            for (int i = 0; i <sizeOfArray ; ++i) {
                table[i]= new Doubly_Linked_List<T>();
            }
        }

        virtual ~HashTable() {
            for (int i = 0; i <size_of_array ; ++i) {
                delete table[i];
            }
            delete[] table;
        }

        int getSizeOfArray() const {
            return size_of_array;
        }

        void setSizeOfArray(int sizeOfArray) {
            size_of_array = sizeOfArray;
        }

        int getNumOfMembers() const {
            return num_of_members;
        }

        void setNumOfMembers(int numOfMembers) {
            num_of_members = numOfMembers;
        }



    };

    template<class T>
    StatusType HashTable<T>::reHash() {
        double alpha= double(num_of_members)/double(size_of_array);
        if (alpha>alpha_max){
            multiply_size();
        }
        else{
            if (alpha<alpha_min){
                if(size_of_array<=2){
                    return FAILURE;
                }
                divide_size();
            }
        }
        return SUCCESS;
    }

    template<class T>
    StatusType HashTable<T>::multiply_size() {
        int place;
        this->setSizeOfArray(size_of_array*2);
        Doubly_Linked_List<T>** new_table= new Doubly_Linked_List<T>*[size_of_array];
        for (int i = 0; i <size_of_array ; ++i) {
            new_table[i]= new Doubly_Linked_List<T>();
        }
        for (int i = 0; i < size_of_array/2 ; ++i) {
            Doubly_Linked_List<T>* current_list = table[i];
            while (current_list->getHead()!=NULL) {
                Link_Node<T>* node_to_copy=current_list->getHead();
                current_list->setHead(current_list->getHead()->getNext());
                place = hashFunction(node_to_copy->getNum());
                new_table[place]->setNewNodeAfterNode(NULL, node_to_copy);
            }
        }
        delete[] table;
        table=new_table;
        return SUCCESS;
    }

    template<class T>
    StatusType HashTable<T>::divide_size() {
        int place;
        this->setSizeOfArray(size_of_array/2);
        Doubly_Linked_List<T>** new_table= new Doubly_Linked_List<T>*[size_of_array];
        for (int i = 0; i <size_of_array ; ++i) {
            new_table[i]= new Doubly_Linked_List<T>();
        }
        for (int i = 0; i < size_of_array*2 ; ++i) {
            Doubly_Linked_List<T>* current_list = table[i];
            while (current_list->getHead()!=NULL) {
                Link_Node<T>* node_to_copy=current_list->getHead();
                current_list->setHead(current_list->getHead()->getNext());
                place = hashFunction(node_to_copy->getNum());
                new_table[place]->setNewNodeAfterNode(NULL, node_to_copy);
            }
        }
        delete[] table;
        table=new_table;
        return SUCCESS;
    }

    template<class T>
    StatusType HashTable<T>::addToTable(int member_id) {
        if(retrieve_member(member_id)!= NULL){
            return FAILURE; //a node with the given ID was found
        }
        Link_Node<T>* node_to_add= new Link_Node<T>(member_id);  ///insert memory check
        setNumOfMembers(num_of_members+1);
        reHash();
        int place = hashFunction(member_id);
        table[place]->setNewNodeAfterNode(NULL,node_to_add);
        return SUCCESS;
    }

    template<class T>
    int HashTable<T>::hashFunction(int member_id) {
        return (member_id % (size_of_array));
    }

    template<class T>
    Link_Node<T>* HashTable<T>::retrieve_member(int member_id) {
        int indexToSearchIn = hashFunction(member_id);
        Link_Node<T> *wantedNode = table[indexToSearchIn]->searchForNode(member_id);
        return wantedNode;
    }

    template<class T>
    StatusType HashTable<T>::removeFromTable(int member_id) {
        Link_Node<T>* NodeToRemove = retrieve_member(member_id);
        if (!NodeToRemove ){
            return FAILURE;
        }
        else{
            int indexOfFittingList = hashFunction(member_id);
            table[indexOfFittingList]->removeNodeFromList(NodeToRemove);
            setNumOfMembers(num_of_members-1);
            reHash();
            return SUCCESS;
        }
    }

}











#endif //EX2_HASH_HASHTABLE_H
