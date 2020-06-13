//
// Created by Dor on 07/06/2020.
//

#include <iostream>
//#include "hashTable.h"
#include "Rank_tree.h"
//#include "MusicManager.h"
//#include "Artist.h"
//#include "library2.h"
///
int main() {

    using namespace AVL;

        int p1=1;
    int p3=3;
    int p5=5;
    int p7=7;
    int p9=9;
    int p11=11;
    int p13=13;
    int p15=15;
    int p17=17;
    int p19=19;
    int p21=21;
    int p23=23;

    AVL::AVL_tree<int>* tree= new AVL::AVL_tree<int>();
    AVL::AVL_tree_node<int> q9=  AVL::AVL_tree_node<int>(&p9);
    AVL::AVL_tree_node<int> q3=  AVL::AVL_tree_node<int>(&p3);
    AVL::AVL_tree_node<int> q15=  AVL::AVL_tree_node<int>(&p15);
    AVL::AVL_tree_node<int> q1=  AVL::AVL_tree_node<int>(&p1);
    AVL::AVL_tree_node<int> q7=  AVL::AVL_tree_node<int>(&p7);
    AVL::AVL_tree_node<int> q13=  AVL::AVL_tree_node<int>(&p13);
    AVL::AVL_tree_node<int> q19=  AVL::AVL_tree_node<int>(&p19);
    AVL::AVL_tree_node<int> q5=  AVL::AVL_tree_node<int>(&p5);
    AVL::AVL_tree_node<int> q11=  AVL::AVL_tree_node<int>(&p11);
    AVL::AVL_tree_node<int> q17=  AVL::AVL_tree_node<int>(&p17);
    AVL::AVL_tree_node<int> q21=  AVL::AVL_tree_node<int>(&p21);
    AVL::AVL_tree_node<int> q23=  AVL::AVL_tree_node<int>(&p23);


    tree->insert(q9);
    tree->insert(q3);
    tree->insert(q15);
    tree->insert(q1);
    tree->insert(q7);
    tree->insert(q13);
    tree->insert(q19);
    tree->insert(q5);
    tree->insert(q11);
    tree->insert(q17);
    tree->insert(q21);
    tree->insert(q23);

    AVL::AVL_tree_node<int>* rank1= tree->select(1);
    AVL::AVL_tree_node<int>* rank2= tree->select(2);
    AVL::AVL_tree_node<int>* rank3= tree->select(3);
    AVL::AVL_tree_node<int>* rank4= tree->select(4);
    AVL::AVL_tree_node<int>* rank5= tree->select(5);
    AVL::AVL_tree_node<int>* rank6= tree->select(6);
    AVL::AVL_tree_node<int>* rank7= tree->select(7);
    AVL::AVL_tree_node<int>* rank8= tree->select(8);
    AVL::AVL_tree_node<int>* rank9= tree->select(9);
    AVL::AVL_tree_node<int>* rank10= tree->select(10);
    AVL::AVL_tree_node<int>* rank11= tree->select(11);
    AVL::AVL_tree_node<int>* rank12= tree->select(12);
    AVL::AVL_tree_node<int>* rank13= tree->select(13);
    AVL::AVL_tree_node<int>* rank14= tree->select(14);





//    AVL::MusicManager* m = new AVL::MusicManager();
//    m->AddArtist(123);
//    m->AddArtist(2222);
//    m->AddArtist(246);
//    m->AddSong(123,1);
//    m->AddSong(123,2);
//    m->AddSong(123,3);
//    m->AddSong(246,2);
//    m->AddSong(2222,1);
//    m->AddToSongCount(123,1,200);
//    m->AddToSongCount(123,2,200);
//    m->AddToSongCount(123,2,200);
//    m->AddToSongCount(2222,1,200);
//    int best=0;
//    m->GetArtistBestSong(123,&best);
//    AVL::MusicManager** mm= &m;
//    Quit((void**)mm);
//
//    int p1=1;
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
//    tree->remove(q1);
//
//
//    Artist artist= Artist();
//    artist.addSong(123);
//    artist.addSong(123);
//    artist.addSong(789);
//    artist.addSong(111);
//    artist.removeSong(111);
//    artist.removeSong(123);
//
//
//    MainTreeSongInfo* z1= new MainTreeSongInfo(123,0);
//    MainTreeSongInfo* z2= new MainTreeSongInfo(456,0);
//    MainTreeSongInfo* z3= new MainTreeSongInfo(789,0);
//
//    AVL::AVL_tree_node<MainTreeSongInfo> nodeZ1= AVL::AVL_tree_node<MainTreeSongInfo>(z1);
//    AVL::AVL_tree_node<MainTreeSongInfo> nodeZ2= AVL::AVL_tree_node<MainTreeSongInfo>(z2);
//    AVL::AVL_tree_node<MainTreeSongInfo> nodeZ3= AVL::AVL_tree_node<MainTreeSongInfo>(z3);
//
//    AVL::AVL_tree<MainTreeSongInfo> example_main_tree = AVL::AVL_tree<MainTreeSongInfo>();
//
//    example_main_tree.insert(nodeZ1);
//    example_main_tree.insert(nodeZ2);
//    example_main_tree.insert(nodeZ3);
//
//    example_main_tree.remove(nodeZ1);
//
//
//    ArtistStreamTreeInfo* y1= new ArtistStreamTreeInfo(1);
//    ArtistStreamTreeInfo* y2= new ArtistStreamTreeInfo(2);
//    ArtistStreamTreeInfo* y3= new ArtistStreamTreeInfo(3);
//    ArtistStreamTreeInfo* y4= new ArtistStreamTreeInfo(4);
//    ArtistStreamTreeInfo* y5= new ArtistStreamTreeInfo(5);
//    ArtistStreamTreeInfo* y6= new ArtistStreamTreeInfo(6);
//    ArtistStreamTreeInfo* y7= new ArtistStreamTreeInfo(7);
//
//    y1->incrementNumberOfStreams(4);
//    y3->incrementNumberOfStreams(2);
//
//    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY1= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y1);
//    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY2= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y2);
//    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY3= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y3);
//    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY4= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y4);
//    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY5= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y5);
//    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY6= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y6);
//    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY7= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y7);
//
//    AVL::AVL_tree<ArtistStreamTreeInfo> example_tree_streams = AVL::AVL_tree<ArtistStreamTreeInfo>();
//
//    example_tree_streams.insert(nodeY1);
//    example_tree_streams.insert(nodeY2);
//    example_tree_streams.insert(nodeY3);
//    example_tree_streams.insert(nodeY4);
//    example_tree_streams.insert(nodeY5);
//
//
//    example_tree_streams.remove(nodeY5);
//
//
//
//    ArtistRegularTreeInfo* x1= new ArtistRegularTreeInfo(1);
//    ArtistRegularTreeInfo* x2= new ArtistRegularTreeInfo(2);
//    ArtistRegularTreeInfo* x3= new ArtistRegularTreeInfo(3);
//    ArtistRegularTreeInfo* x4= new ArtistRegularTreeInfo(4);
//    ArtistRegularTreeInfo* x5= new ArtistRegularTreeInfo(5);
//    ArtistRegularTreeInfo* x6= new ArtistRegularTreeInfo(6);
//    ArtistRegularTreeInfo* x7= new ArtistRegularTreeInfo(7);
//    ArtistRegularTreeInfo* x8= new ArtistRegularTreeInfo(8);
//
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node1=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x1);
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node2=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x2);
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node3=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x3);
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node4=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x4);
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node5=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x5);
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node6=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x6);
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node7=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x7);
//    AVL::AVL_tree_node<ArtistRegularTreeInfo> node8=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x8);
//
//    AVL::AVL_tree<ArtistRegularTreeInfo> example_tree_regular = AVL::AVL_tree<ArtistRegularTreeInfo>();
//
//    example_tree_regular.insert(node3);
//    example_tree_regular.insert(node1);
//    example_tree_regular.insert(node2);
//    example_tree_regular.insert(node4);
//    example_tree_regular.insert(node5);
//    example_tree_regular.insert(node6);
//    example_tree_regular.insert(node7);
//    example_tree_regular.insert(node8);
//
//
//
//    AVL::HashTable<int>* example= new AVL::HashTable<int>(2);
//    example->addToTable(1);
//    example->addToTable(2);
//    example->addToTable(3);
//    example->addToTable(4);
//    example->addToTable(5);
//    example->addToTable(6);
//    example->addToTable(7);
//    example->addToTable(8);
//    example->addToTable(9);
//
//    example->removeFromTable(1);
//    example->removeFromTable(2);
//    std::cout <<example->removeFromTable(2)<<  std::endl;;
//    example->removeFromTable(3);
//    example->removeFromTable(4);
//    example->removeFromTable(5);
//    example->removeFromTable(6);
//    example->removeFromTable(7);


    std::cout <<"d"<<  std::endl;
   // delete example;
    return 0;
}
