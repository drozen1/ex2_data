//
// Created by Dor on 10/06/2020.
//

#ifndef EX2_HASH_RANK_TREE_H
#define EX2_HASH_RANK_TREE_H

//
// Created by Dor on 28/04/2020.
//

#ifndef UNTITLED_AVL_TREE_H
#define UNTITLED_AVL_TREE_H



#include "AVL_tree_node.h"
#include <ostream>
#include <math.h>

namespace AVL {

    using namespace AVLUtils;


    template<class Element>
    class AVL_tree {
    public:
        ~AVL_tree(){
            DestroyTree(this->getRoot());
            this->setRoot(NULL);
            this->setMinimum(NULL);

        }

        void DestroyTree(AVL_tree_node<Element> *p){
            if (p == NULL ){
                return;
            }
            DestroyTree(p->getLeftSon());
            DestroyTree(p->getRightSon());
            delete(p);
        }

        void fill_tree(AVL_tree_node <Element> *ptr, int *n);

        AVL_tree(int num_of_nodes);

        AVL_tree_node<Element>* CompleteTree(int h);

        void setRoot(AVL_tree_node<Element> *root);

        AVL_tree_node<Element>* handleLeafRemoval(AVL_tree_node<Element> *p);

        AVL_tree_node<Element>* handleRemovalOfVerWithOneKid(AVL_tree_node<Element> *p);

        AVL_tree_node<Element>* handleRemovalOfVerWithTwoKids(AVL_tree_node<Element> *p);

        void setMinimum(AVL_tree_node<Element> *minimum);

        void updateHeights( AVL_tree_node<Element>* v);

        AVL_tree(AVL_tree_node<Element> *root) : root(root),minimum(root) {}

        AVL_tree() : root(nullptr), minimum(nullptr) {}

        AVL_tree_node<Element> *find_node(Element* key);

        StatusType insert(AVL_tree_node<Element> &node_toadd);

        StatusType remove(AVL_tree_node<Element> &node_to_remove);

        AVL_tree_node<Element> *getRoot() const;

        void updateTree(AVL_tree_node<Element> *start_node);

        Roll2_Perform checkTypeOfRoll(AVL_tree_node<Element> *p);

        void Perform_RR_Roll(AVL_tree_node<Element> *p);

        void Perform_LL_Roll(AVL_tree_node<Element> *p);

        void Perform_LR_Roll(AVL_tree_node<Element> *p);

        void Perform_RL_Roll(AVL_tree_node<Element> *p);

        void PerformRoll(AVL_tree_node<Element> *p, Roll2_Perform roll_needed);

        void inOrder(AVL_tree_node<Element> *p);

        void print_from_min(AVL_tree_node<Element> *cur,AVL_tree_node<Element> *last);

        AVL_tree_node<Element>* searchTreeRemoval(AVL_tree_node<Element> &node_to_remove, int& foundGivenNode);

        AVL_tree_node<Element>* retrieveMax();



        AVL_tree_node<Element>* select(int rank);

    private:
        AVL_tree_node<Element> *root;
        AVL_tree_node<Element>* minimum;

    public:
        AVL_tree_node<Element> *getMinimum() ;

    };

    template<class Element>
    AVL_tree_node<Element> *AVL_tree<Element>::getRoot() const {
        return root;
    }

    template<class Element>
    void AVL_tree<Element>::setRoot(AVL_tree_node<Element> *root) {
        AVL_tree::root = root;
    }

    template<class Element>
    void AVL_tree<Element>::setMinimum(AVL_tree_node<Element> *minimum) {
        AVL_tree::minimum = minimum;
    }


/**
 *
 * @tparam Element
 * @param key
 * @return pointer to the node we want. nullptr- in case the key doesn't exists
 */
    template<class Element>
    AVL_tree_node<Element> *AVL_tree<Element>::find_node(Element* key) {
        AVL_tree_node<Element> *curr = root;
        while (curr != nullptr && (curr->getLeftSon() != nullptr or curr->getRightSon() != nullptr)) {
            if (*(curr->getDataKey()) == *key)
                return curr;

            if ( *(curr->getDataKey()) > *key) {
                curr = curr->getLeftSon();
            } else {
                curr = curr->getRightSon();
            }
        }
        if (curr != NULL && *(curr->getDataKey()) == *key) {
            return curr;
        }
        return nullptr;
    }


    template<class Element>
    StatusType AVL_tree<Element>::insert(AVL_tree_node<Element> &node_toadd) {
        Element* key = node_toadd.getDataKey();
        if (this->root == NULL){
            setMinimum(&node_toadd);
        }
        else{
            if (minimum!=NULL && *key < *(minimum->getDataKey())){
                setMinimum(&node_toadd);
            }
        }

        if (find_node(key) != nullptr)
            return FAILURE;
        AVL_tree_node<Element> *curr = root;
        AVL_tree_node<Element> *last = root;
        ///root==NULL
        if (curr == nullptr) {
            setRoot(&node_toadd);
            node_toadd.update_size_of_inner_tree();
            return SUCCESS;
        }
        while (curr != nullptr) {
            if (*(curr->getDataKey()) > *key) {
                last = curr;
                curr = curr->getLeftSon();
            } else {
                last = curr;
                curr = curr->getRightSon();
            }
        }
        if (*key > *(last->getDataKey())) {
            last->setRightSon(&node_toadd);
        } else {
            last->setLeftSon(&node_toadd);
        }
        node_toadd.setParent(last);
        node_toadd.update_size_of_inner_tree();
        updateTree(&node_toadd);
        return SUCCESS;
    }

    template<class Element>
    StatusType AVL_tree<Element>::remove(AVL_tree_node<Element> &node_to_remove) {
        int nodeWasFound = 0;
        AVL_tree_node<Element>* parentOfVBeforeRoll = NULL;
        AVL_tree_node<Element>* nodeToStartFrom = searchTreeRemoval(node_to_remove,nodeWasFound);
        if(nodeWasFound == 0){
            return FAILURE;
        }
        AVL_tree_node<Element> *v = nodeToStartFrom;
        while (v != NULL) {
            parentOfVBeforeRoll = v->getParent();
            v->updateHeight();
            v->setSizeOfInnerTree(v->calcNumOfSons()+1); //this was added
            Roll2_Perform roll_needed = checkTypeOfRoll(v);
            PerformRoll(v, roll_needed);
            v= parentOfVBeforeRoll;
        }
        AVL_tree_node<Element> *new_minimum = this->getRoot();
        if (this->getRoot()!=NULL) {
            while (new_minimum->getLeftSon() != NULL) {
                new_minimum = new_minimum->getLeftSon();
            }
            this->setMinimum(new_minimum);
        }
        return SUCCESS;
    }


    template<class Element>
    Roll2_Perform AVL_tree<Element>::checkTypeOfRoll(AVL_tree_node<Element> *p) {
        if (p->calcBalnceFactor() == -2) {
            if (p->getRightSon()->calcBalnceFactor() == 1) {
                return RL;
            }
            return RR;
        }
        if (p->calcBalnceFactor() == 2) {
            if (p->getLeftSon()->calcBalnceFactor() == -1) {
                return LR;
            }
            return LL;
        }
        return No_Roll_Needed;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_RR_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }
        AVL_tree_node <Element> *OriginalParentOfP = p->getParent(); ///can be NULL
        AVL_tree_node <Element> *leftSonOfRightSonOfP = p->getRightSon()->getLeftSon();
        AVL_tree_node <Element> *RightSonOfP = p->getRightSon();
        RightSonOfP->setLeftSon(p);
        p->setParent(RightSonOfP);
        RightSonOfP->setParent(OriginalParentOfP);
        p->setRightSon(leftSonOfRightSonOfP);
        if (leftSonOfRightSonOfP != NULL) {
            leftSonOfRightSonOfP->setParent(p);
        }
        if (OriginalParentOfP != NULL) {
            if(OriginalParentOfP->getTypeOfSon(p) == RIGHT){
                OriginalParentOfP->setRightSon(RightSonOfP);
            }
            else{
                OriginalParentOfP->setLeftSon(RightSonOfP);
            }
        }
        ///update the new height
        RightSonOfP->getRightSon()->updateHeight();
        RightSonOfP->getLeftSon()->updateHeight();
        RightSonOfP->updateHeight();

        ///this was added !
        if(RightSonOfP->getRightSon()!=NULL){
            RightSonOfP->getRightSon()->setSizeOfInnerTree(RightSonOfP->getRightSon()->calcNumOfSons()+1);
        }
        if(RightSonOfP->getLeftSon()!=NULL){
            RightSonOfP->getLeftSon()->setSizeOfInnerTree(RightSonOfP->getLeftSon()->calcNumOfSons()+1);
        }
        RightSonOfP->setSizeOfInnerTree(RightSonOfP->calcNumOfSons()+1);
        if (updateRoot) {
            this->setRoot(RightSonOfP);
        }
        return;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_LL_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }

        AVL_tree_node<Element> *OriginalParentOfP = p->getParent(); ///can be NULL

        AVL_tree_node<Element> *RightSonOfLeftSonOfP = p->getLeftSon()->getRightSon();
        AVL_tree_node<Element> *LeftSonOfP = p->getLeftSon();
        LeftSonOfP->setRightSon(p);
        p->setParent(LeftSonOfP);
        LeftSonOfP->setParent(OriginalParentOfP);
        p->setLeftSon(RightSonOfLeftSonOfP);
        if (RightSonOfLeftSonOfP != NULL) {
            RightSonOfLeftSonOfP->setParent(p);
        }
        if (OriginalParentOfP != NULL) {
            if (OriginalParentOfP->getTypeOfSon(p) == RIGHT) {
                OriginalParentOfP->setRightSon(LeftSonOfP);
            } else {
                OriginalParentOfP->setLeftSon(LeftSonOfP);
            }
        }
        ///update the new height
        LeftSonOfP->getRightSon()->updateHeight();
        LeftSonOfP->getLeftSon()->updateHeight();
        LeftSonOfP->updateHeight();

        ///this was added !
        if(LeftSonOfP->getRightSon()!=NULL){
            LeftSonOfP->getRightSon()->setSizeOfInnerTree(LeftSonOfP->getRightSon()->calcNumOfSons()+1);
        }
        if (LeftSonOfP->getLeftSon()!=NULL){
            LeftSonOfP->getLeftSon()->setSizeOfInnerTree(LeftSonOfP->getLeftSon()->calcNumOfSons()+1);
        }
        LeftSonOfP->setSizeOfInnerTree(LeftSonOfP->calcNumOfSons()+1);


        if (updateRoot) {
            this->setRoot(LeftSonOfP);
        }
        return;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_LR_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }
        AVL_tree_node <Element> *LeftSonOfP = p->getLeftSon();
        AVL_tree_node <Element> *RightSonOfLeftSonOfP = p->getLeftSon()->getRightSon();
        AVL_tree_node <Element> *OriginalParent = p->getParent();
        AVL_tree_node <Element> *RightTreeOfA = RightSonOfLeftSonOfP->getRightSon(); ///can be NULL
        RightSonOfLeftSonOfP->setRightSon(p);
        p->setParent(RightSonOfLeftSonOfP);
        p->setLeftSon(RightTreeOfA);
        if (RightTreeOfA != NULL) {
            RightTreeOfA->setParent(p);
        }
        LeftSonOfP->setRightSon(RightSonOfLeftSonOfP->getLeftSon());
        if (RightSonOfLeftSonOfP->getLeftSon() != NULL) {
            RightSonOfLeftSonOfP->getLeftSon()->setParent(LeftSonOfP);
        }
        RightSonOfLeftSonOfP->setLeftSon(LeftSonOfP);
        LeftSonOfP->setParent(RightSonOfLeftSonOfP);
        RightSonOfLeftSonOfP->setParent(OriginalParent);
        if (OriginalParent != NULL) {
            if(OriginalParent->getTypeOfSon(p)==LEFT){
                OriginalParent->setLeftSon(RightSonOfLeftSonOfP);
            }
            else {
                OriginalParent->setRightSon(RightSonOfLeftSonOfP);
            }
        }
        ///update the new height
        p->updateHeight();
        LeftSonOfP->updateHeight();
        RightSonOfLeftSonOfP->updateHeight();

        ///this was added
        p->setSizeOfInnerTree(p->calcNumOfSons()+1);
        LeftSonOfP->setSizeOfInnerTree(LeftSonOfP->calcNumOfSons()+1);
        RightSonOfLeftSonOfP->setSizeOfInnerTree(RightSonOfLeftSonOfP->calcNumOfSons()+1);

        if (updateRoot) {
            this->setRoot(RightSonOfLeftSonOfP);
        }

        return;
    }

    template<class Element>
    void AVL_tree<Element>::Perform_RL_Roll(AVL_tree_node<Element> *p) {
        bool updateRoot = false;
        if (p->getParent() == NULL) {
            updateRoot = true;
        }
        AVL_tree_node <Element> *RightSonOfP = p->getRightSon();

        AVL_tree_node <Element> *LeftSonOfRightSonOfP = p->getRightSon()->getLeftSon();
        AVL_tree_node <Element> *OriginalParent = p->getParent();
        AVL_tree_node <Element> *LeftTreeOfA = LeftSonOfRightSonOfP->getLeftSon(); ///can be NULL
        LeftSonOfRightSonOfP->setLeftSon(p);
        p->setParent(LeftSonOfRightSonOfP);
        p->setRightSon(LeftTreeOfA);
        if (LeftTreeOfA != NULL) {
            LeftTreeOfA->setParent(p);
        }
        RightSonOfP->setLeftSon(LeftSonOfRightSonOfP->getRightSon());
        if (LeftSonOfRightSonOfP->getRightSon() != NULL) {
            LeftSonOfRightSonOfP->getRightSon()->setParent(RightSonOfP);
        }
        LeftSonOfRightSonOfP->setRightSon(RightSonOfP);
        RightSonOfP->setParent(LeftSonOfRightSonOfP);
        LeftSonOfRightSonOfP->setParent(OriginalParent);
        if (OriginalParent != NULL) {
            if(OriginalParent->getTypeOfSon(p)==LEFT){
                OriginalParent->setLeftSon(LeftSonOfRightSonOfP);
            }
            else {
                OriginalParent->setRightSon(LeftSonOfRightSonOfP);
            }
        }
        ///update the new height
        p->updateHeight();
        RightSonOfP->updateHeight();
        LeftSonOfRightSonOfP->updateHeight();

        ///this was added
        p->setSizeOfInnerTree(p->calcNumOfSons()+1);
        RightSonOfP->setSizeOfInnerTree(RightSonOfP->calcNumOfSons()+1);
        LeftSonOfRightSonOfP->setSizeOfInnerTree(LeftSonOfRightSonOfP->calcNumOfSons()+1);

        if (updateRoot) {
            this->setRoot(LeftSonOfRightSonOfP);
        }
        return;
    }

    template<class Element>
    void AVL_tree<Element>::PerformRoll(AVL_tree_node<Element> *p, Roll2_Perform roll_needed) {
        if(roll_needed==No_Roll_Needed){
            return;
        }
        if (roll_needed == RR) {
            Perform_RR_Roll(p);
            return;
        }
        if (roll_needed == LL) {
            Perform_LL_Roll(p);
            return;
        }
        if (roll_needed == LR) {
            Perform_LR_Roll(p);
            return;
        }
        if (roll_needed == RL) {
            Perform_RL_Roll(p);
            return;
        }
        return;
    }

/**
 *
 *the following function updates all the parents of a given node not including the node himself
 * @tparam Element
 * @param start_node
 */
    template<class Element>
    void AVL_tree<Element>::updateTree(AVL_tree_node<Element> *start_node) {
        AVL_tree_node <Element> *p = nullptr;
        AVL_tree_node <Element> *v = start_node;
        while (v != this->getRoot()) {
            p = v->getParent();
            if (p->getHeight() >= 1 + v->getHeight()) {
                return;
            }
            p->setHeight(1 + v->getHeight());
            Roll2_Perform roll_needed = checkTypeOfRoll(p);
            if (roll_needed == No_Roll_Needed) {
                v = p;
            } else {
                PerformRoll(p, roll_needed);
                return;
            }
        }
    }

    template<class Element>
    void AVL_tree<Element>::updateHeights(AVL::AVL_tree_node<Element> *v) {
        while(v!=NULL){
            v->updateHeight();
            v=v->getParent();
        }
    }

    template<class Element>
    void AVL_tree<Element>::fill_tree(AVL_tree_node<Element>*ptr ,int* n) {
        if(*n<0||ptr==NULL){
            return;
        }
        fill_tree(ptr->getRightSon(),n);
        ptr->setKey(*n);
        *n=*n-1;
        fill_tree(ptr->getLeftSon(),n);
    }

    template<class Element>
    void AVL_tree<Element>::inOrder(AVL_tree_node<Element> *p) {

        if (p == NULL) {
            return;
        }
        inOrder(p->getLeftSon());
        p->Print_node();
        inOrder(p->getRightSon());
    }


    /**
     *
     *
     * @tparam Element
     * @param cur - send me the minmum
     * @param last - send me NULL
     */
    template<class Element>
    void AVL_tree<Element>::print_from_min(AVL_tree_node<Element> *cur,AVL_tree_node<Element> *last) {
        if(cur==NULL){
            if(last->getRightSon()==NULL &&last->getParent()!=NULL){
                print_from_min(last->getParent(),last);
            }
            return;
        }else{
            ///travel left
            if(cur->getLeftSon()!=NULL && last!=NULL && cur->getParent()!=NULL
               && cur->getParent()->getKey()==last->getKey()) {
                print_from_min(cur->getLeftSon(), cur);
                return;
            }

        }
        ///finish to travel left
        if(((cur->getLeftSon()==NULL && last==NULL) ||(last!=NULL&&
                                                       cur->getLeftSon()!=NULL&& cur->getLeftSon()->getKey()==last->getKey()))){
            cur->Print_node();
            last = cur;
            cur = cur->getRightSon();
            print_from_min(cur, last);
            return;
        }
        else {
            if (cur->isLeaf()){
                cur->Print_node();
                last=cur;
                cur = cur->getParent();
                print_from_min(cur,last);
                return;
            }
        }
        if(cur->getLeftSon()==NULL&&cur->getRightSon()!=NULL&&
           last!=NULL&&cur->getParent()!=NULL&&
           cur->getParent()->getKey()==last->getKey()){
            cur->Print_node();
        }
        ///travel right
        if(cur->getRightSon()!=NULL && last!=NULL && cur->getRightSon()->getKey()!=last->getKey()) {
            print_from_min(cur->getRightSon(), cur);
            return;
        }
        ///finish to travel right
        if( (cur->getRightSon()==NULL&&last==NULL)||
            (cur->getRightSon()!=NULL&& cur->getRightSon()->getKey()==last->getKey())){
            last=cur;
            cur=cur->getParent();
            print_from_min(cur,last);
        }
        return;
    }



    /**
     *
     * @tparam Element
     * @param node_toremove
     * @return Null if the node was not found or if he is the only node
     */
    template<class Element>
    AVL_tree_node<Element> *AVL_tree<Element>::searchTreeRemoval(AVL_tree_node<Element> &node_to_remove,int& foundGivenNode) {
        AVL_tree_node <Element> *p = find_node(node_to_remove.getDataKey());
        AVL_tree_node<Element>* nodeToReturnToAVLRemoval = NULL;
        if (p == NULL) {
            foundGivenNode = 0;
            return NULL;
        }
        foundGivenNode = 1;
        if (p->isLeaf()) {
            nodeToReturnToAVLRemoval = handleLeafRemoval(p);
            return nodeToReturnToAVLRemoval;
        }
        if (p->numOfchildren() == 1) {
            nodeToReturnToAVLRemoval = handleRemovalOfVerWithOneKid(p);
            return nodeToReturnToAVLRemoval;
        }
        nodeToReturnToAVLRemoval = handleRemovalOfVerWithTwoKids(p);
        return nodeToReturnToAVLRemoval;;
    }

    template<class Element>
    AVL_tree_node<Element>* AVL_tree<Element>::handleRemovalOfVerWithTwoKids(AVL_tree_node<Element> *p) { //need to update heights
        AVL_tree_node <Element> *parentOfp = p->getParent();
        bool shouldResetRoot = false;
        if (parentOfp == NULL) {
            shouldResetRoot = true;
        }
        AVL_tree_node <Element> *followingVerInorder = p->retreiveFollowingVertexInorder();
        if (*(followingVerInorder->getDataKey()) == *(p->getRightSon()->getDataKey())) {
            AVL_tree_node <Element> *leftSonOfp = p->getLeftSon();
            followingVerInorder->setLeftSon(leftSonOfp);
            leftSonOfp->setParent(followingVerInorder);
            if (shouldResetRoot) {
                followingVerInorder->setParent(NULL);
                setRoot(followingVerInorder);
            } else {
                followingVerInorder->setParent(parentOfp);
                if (parentOfp->getTypeOfSon(p) == RIGHT) {
                    parentOfp->setRightSon(followingVerInorder);
                } else {
                    parentOfp->setLeftSon(followingVerInorder);
                }
            }
            delete (p);
            updateHeights(followingVerInorder);
            followingVerInorder->update_size_of_inner_tree();
            return followingVerInorder;
        }
        AVL_tree_node <Element> *parentOfFollowingVer = followingVerInorder->getParent();
        if (followingVerInorder->isLeaf()) { //handle the case the following vertex is a leaf
            if (*(parentOfFollowingVer->getDataKey()) != *(p->getDataKey())) {
                if (parentOfFollowingVer->getTypeOfSon(followingVerInorder) == RIGHT) {
                    parentOfFollowingVer->setRightSon(NULL);
                } else {
                    parentOfFollowingVer->setLeftSon(NULL);
                }
            }
        }
        AVL_tree_node <Element> *rightSonOfFollowingVer = followingVerInorder->getRightSon();
        if (followingVerInorder->numOfchildren() == 1) { //surely a right son of the given vertex, if there's one
            parentOfFollowingVer->setLeftSon(rightSonOfFollowingVer);
            rightSonOfFollowingVer->setParent(parentOfFollowingVer);
        }
        if ((*p->getLeftSon()->getDataKey()) != (*followingVerInorder->getDataKey())) {
            followingVerInorder->setLeftSon(p->getLeftSon());
            p->getLeftSon()->setParent(followingVerInorder);
        }
        if ((*p->getRightSon()->getDataKey()) != (*followingVerInorder->getDataKey())) {
            followingVerInorder->setRightSon(p->getRightSon());
            p->getRightSon()->setParent(followingVerInorder);
        }

        if (shouldResetRoot) {
            setRoot(followingVerInorder);
            followingVerInorder->setParent(NULL);
        } else {
            followingVerInorder->setParent(parentOfp);
            if (parentOfp->getTypeOfSon(p) == RIGHT) {
                parentOfp->setRightSon(followingVerInorder);
            } else {
                parentOfp->setLeftSon(followingVerInorder);
            }
        }
        delete (p);
        updateHeights(parentOfFollowingVer); //this should reach to an update of the followingVerInorder too
        parentOfFollowingVer->update_size_of_inner_tree();
        return followingVerInorder;
    }


    template<class Element>
    AVL_tree_node<Element>* AVL_tree<Element>::handleLeafRemoval(AVL_tree_node<Element> *p) {
        AVL_tree_node <Element> *parentOfp = p->getParent();
        bool shouldResetRoot = false;
        if (parentOfp == NULL) {
            shouldResetRoot = true;
        }
        if (shouldResetRoot) { //handle root case
            setRoot(NULL);
            delete (p);
            return parentOfp;
        }
        if (parentOfp->getTypeOfSon(p) == RIGHT) {
            parentOfp->setRightSon(NULL);
        }
        if (parentOfp->getTypeOfSon(p) == LEFT) {
            parentOfp->setLeftSon(NULL);
        }
        delete (p);
        updateHeights(parentOfp);
        parentOfp->update_size_of_inner_tree(); ///add 15/6
        return parentOfp;
    }

    template<class Element>
    AVL_tree_node<Element>* AVL_tree<Element>::handleRemovalOfVerWithOneKid(AVL_tree_node<Element> *p) {
        AVL_tree_node<Element>* nodeToReturn = NULL;
        bool shouldResetRoot = false;
        if (p->getParent() == NULL) {
            shouldResetRoot = true;
        }
        if (shouldResetRoot) { // Handle the root removal case
            if (p->getLeftSon() != NULL) {
                setRoot(p->getLeftSon());
                p->getLeftSon()->setParent(NULL);
            } else {
                setRoot(p->getRightSon()); // the son of p is surely it's right one
                p->getRightSon()->setParent(NULL);
            }
            delete (p);
            updateHeights(root);
            root->update_size_of_inner_tree();
            return root;
        }
        AVL_tree_node <Element> *parentOfp = p->getParent();
        if (parentOfp->getTypeOfSon(p) == LEFT) {
            if (p->getLeftSon() != NULL) {
                nodeToReturn = p->getLeftSon();
                parentOfp->setLeftSon(p->getLeftSon());
                p->getLeftSon()->setParent(parentOfp);
            } else {
                nodeToReturn = p->getRightSon();
                parentOfp->setLeftSon(p->getRightSon());
                p->getRightSon()->setParent(parentOfp);
            }
        } else { //p is the right son of his parent
            if (p->getLeftSon() != NULL) {
                parentOfp->setRightSon(p->getLeftSon());
                p->getLeftSon()->setParent(parentOfp);
            } else {
                parentOfp->setRightSon(p->getRightSon());
                p->getRightSon()->setParent(parentOfp);
            }
        }
        delete (p);
        updateHeights(parentOfp);
        parentOfp->update_size_of_inner_tree();
        return nodeToReturn;
    }



    template<class Element>
    AVL_tree<Element>::AVL_tree(int num_of_nodes):root(NULL),minimum(NULL) {
        int h=log2(num_of_nodes)+1;
        if (num_of_nodes!=0) {
            this->setRoot(CompleteTree(h));
        } else{
            this->setRoot(NULL);
            return;
        }
        int num_of_full_nodes=pow(2,h)-1;
        int nodes_to_delete=(num_of_full_nodes-num_of_nodes);
        this->getRoot()->delete_redudants_nodes(&nodes_to_delete);
        int x=num_of_nodes-1;
        this->fill_tree(this->getRoot(),&x);
        this->setMinimum(this->find_node(0));
    }

    template<class Element>
    AVL_tree_node<Element> *AVL_tree<Element>::CompleteTree(int h) {
        if( h==0){
            return nullptr;
        }
        AVL_tree_node<Element>* temp_root_node = new AVL_tree_node<Element>(-1);

        AVL_tree_node<Element>* leftson=CompleteTree(h-1);
        temp_root_node->setLeftSon(leftson);
        if (leftson!=NULL) {
            leftson->setParent(temp_root_node);
        }
        AVL_tree_node<Element>* rightson=CompleteTree(h-1);
        temp_root_node->setRightSon(rightson);
        if (rightson!=NULL) {
            rightson->setParent(temp_root_node);
        }
        temp_root_node->setHeight(h-1);
        return  temp_root_node;
    }

    template<class Element>
    AVL_tree_node<Element>* AVL_tree<Element>::getMinimum()  {
        return minimum;
    }

    template<class Element>
    AVL_tree_node<Element> *AVL_tree<Element>::retrieveMax() {
        if (this->root==NULL){
            return NULL;
        }
        AVL_tree_node<Element> * cur=this->root;
        while(cur->getRightSon()!=NULL){
            cur=cur->getRightSon();
        }
        return cur;
    }



    template<class Element>
    AVL_tree_node<Element> *AVL_tree<Element>::select(int rank) {

        if(this->root==NULL||rank>this->root->getSizeOfInnerTree()){
            return NULL;
        }
        return this->root->select(rank);
    }




}


#endif //UNTITLED_AVL_TREE_H



#endif //EX2_HASH_RANK_TREE_H
