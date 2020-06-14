//
// Created by Dor on 07/06/2020.
//

#include <iostream>
//#include "hashTable.h"
#include "Rank_tree.h"
#include "MusicManager.h"
//#include "Artist.h"
#include "library2.h"
///
int main() {

    using namespace AVL;

//        int p1=1;
//    int p3=3;
//    int p5=5;
//    int p7=7;
//    int p9=9;
//    int p11=11;
//    int p13=13;
//    int p15=15;
//    int p17=17;
//    int p19=19;
//    int p21=21;
//    int p23=23;
//
//    AVL::AVL_tree<int>* tree= new AVL::AVL_tree<int>();
//    AVL::AVL_tree_node<int> q9=  AVL::AVL_tree_node<int>(&p9);
//    AVL::AVL_tree_node<int> q3=  AVL::AVL_tree_node<int>(&p3);
//    AVL::AVL_tree_node<int> q15=  AVL::AVL_tree_node<int>(&p15);
//    AVL::AVL_tree_node<int> q1=  AVL::AVL_tree_node<int>(&p1);
//    AVL::AVL_tree_node<int> q7=  AVL::AVL_tree_node<int>(&p7);
//    AVL::AVL_tree_node<int> q13=  AVL::AVL_tree_node<int>(&p13);
//    AVL::AVL_tree_node<int> q19=  AVL::AVL_tree_node<int>(&p19);
//    AVL::AVL_tree_node<int> q5=  AVL::AVL_tree_node<int>(&p5);
//    AVL::AVL_tree_node<int> q11=  AVL::AVL_tree_node<int>(&p11);
//    AVL::AVL_tree_node<int> q17=  AVL::AVL_tree_node<int>(&p17);
//    AVL::AVL_tree_node<int> q21=  AVL::AVL_tree_node<int>(&p21);
//    AVL::AVL_tree_node<int> q23=  AVL::AVL_tree_node<int>(&p23);
//
//
//    tree->insert(q9);
//    tree->insert(q3);
//    tree->insert(q15);
//    tree->insert(q1);
//    tree->insert(q7);
//    tree->insert(q13);
//    tree->insert(q19);
//    tree->insert(q5);
//    tree->insert(q11);
//    tree->insert(q17);
//    tree->insert(q21);
//    tree->insert(q23);
//
//    AVL::AVL_tree_node<int>* rank1= tree->select(1);
//    AVL::AVL_tree_node<int>* rank2= tree->select(2);
//    AVL::AVL_tree_node<int>* rank3= tree->select(3);
//    AVL::AVL_tree_node<int>* rank4= tree->select(4);
//    AVL::AVL_tree_node<int>* rank5= tree->select(5);
//    AVL::AVL_tree_node<int>* rank6= tree->select(6);
//    AVL::AVL_tree_node<int>* rank7= tree->select(7);
//    AVL::AVL_tree_node<int>* rank8= tree->select(8);
//    AVL::AVL_tree_node<int>* rank9= tree->select(9);
//    AVL::AVL_tree_node<int>* rank10= tree->select(10);
//    AVL::AVL_tree_node<int>* rank11= tree->select(11);
//    AVL::AVL_tree_node<int>* rank12= tree->select(12);
//    AVL::AVL_tree_node<int>* rank13= tree->select(13);
//    AVL::AVL_tree_node<int>* rank14= tree->select(14);
//
//



   MusicManager* m = new MusicManager();
    m->AddArtist(1);
    m->AddArtist(2);
    m->AddArtist(3);
    m->AddSong(1,1);
    m->AddSong(2,1);
    m->AddSong(3,1);
    int artistID=0;
    int songID = 0;
    m->GetRecommendedSongInPlace(2,&artistID,&songID);




    std::cout <<"d"<<  std::endl;
   // delete example;
    return 0;
}
