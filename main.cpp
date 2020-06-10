//
// Created by Dor on 07/06/2020.
//

#include <iostream>
#include "hashTable.h"
#include "AVL_tree_node.h"
#include "MusicManager.h"
///
int main() {

    Artist artist= Artist();
    artist.addSong(123);
    artist.addSong(456);
    artist.addSong(789);
    artist.addSong(111);
    artist.removeSong(111);
    artist.removeSong(123);


    MainTreeSongInfo* z1= new MainTreeSongInfo(123,0);
    MainTreeSongInfo* z2= new MainTreeSongInfo(456,0);
    MainTreeSongInfo* z3= new MainTreeSongInfo(789,0);

    AVL::AVL_tree_node<MainTreeSongInfo> nodeZ1= AVL::AVL_tree_node<MainTreeSongInfo>(z1);
    AVL::AVL_tree_node<MainTreeSongInfo> nodeZ2= AVL::AVL_tree_node<MainTreeSongInfo>(z2);
    AVL::AVL_tree_node<MainTreeSongInfo> nodeZ3= AVL::AVL_tree_node<MainTreeSongInfo>(z3);

    AVL::AVL_tree<MainTreeSongInfo> example_main_tree = AVL::AVL_tree<MainTreeSongInfo>();

    example_main_tree.insert(nodeZ1);
    example_main_tree.insert(nodeZ2);
    example_main_tree.insert(nodeZ3);

    example_main_tree.remove(nodeZ1);


    ArtistStreamTreeInfo* y1= new ArtistStreamTreeInfo(1);
    ArtistStreamTreeInfo* y2= new ArtistStreamTreeInfo(2);
    ArtistStreamTreeInfo* y3= new ArtistStreamTreeInfo(3);
    ArtistStreamTreeInfo* y4= new ArtistStreamTreeInfo(4);
    ArtistStreamTreeInfo* y5= new ArtistStreamTreeInfo(5);
    ArtistStreamTreeInfo* y6= new ArtistStreamTreeInfo(6);
    ArtistStreamTreeInfo* y7= new ArtistStreamTreeInfo(7);

    y1->incrementNumberOfStreams(4);
    y3->incrementNumberOfStreams(2);

    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY1= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y1);
    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY2= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y2);
    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY3= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y3);
    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY4= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y4);
    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY5= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y5);
    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY6= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y6);
    AVL::AVL_tree_node<ArtistStreamTreeInfo> nodeY7= AVL::AVL_tree_node<ArtistStreamTreeInfo>(y7);

    AVL::AVL_tree<ArtistStreamTreeInfo> example_tree_streams = AVL::AVL_tree<ArtistStreamTreeInfo>();

    example_tree_streams.insert(nodeY1);
    example_tree_streams.insert(nodeY2);
    example_tree_streams.insert(nodeY3);
    example_tree_streams.insert(nodeY4);
    example_tree_streams.insert(nodeY5);


    example_tree_streams.remove(nodeY5);



    ArtistRegularTreeInfo* x1= new ArtistRegularTreeInfo(1);
    ArtistRegularTreeInfo* x2= new ArtistRegularTreeInfo(2);
    ArtistRegularTreeInfo* x3= new ArtistRegularTreeInfo(3);
    ArtistRegularTreeInfo* x4= new ArtistRegularTreeInfo(4);
    ArtistRegularTreeInfo* x5= new ArtistRegularTreeInfo(5);
    ArtistRegularTreeInfo* x6= new ArtistRegularTreeInfo(6);
    ArtistRegularTreeInfo* x7= new ArtistRegularTreeInfo(7);
    ArtistRegularTreeInfo* x8= new ArtistRegularTreeInfo(8);

    AVL::AVL_tree_node<ArtistRegularTreeInfo> node1=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x1);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> node2=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x2);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> node3=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x3);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> node4=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x4);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> node5=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x5);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> node6=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x6);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> node7=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x7);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> node8=  AVL::AVL_tree_node<ArtistRegularTreeInfo>(x8);

    AVL::AVL_tree<ArtistRegularTreeInfo> example_tree_regular = AVL::AVL_tree<ArtistRegularTreeInfo>();

    example_tree_regular.insert(node3);
    example_tree_regular.insert(node1);
    example_tree_regular.insert(node2);
    example_tree_regular.insert(node4);
    example_tree_regular.insert(node5);
    example_tree_regular.insert(node6);
    example_tree_regular.insert(node7);
    example_tree_regular.insert(node8);






    AVL::HashTable<int>* example= new AVL::HashTable<int>(2);
    example->addToTable(1);
    example->addToTable(2);
    example->addToTable(3);
    example->addToTable(4);
    example->addToTable(5);
    example->addToTable(6);
    example->addToTable(7);
    example->addToTable(8);
    example->addToTable(9);

    example->removeFromTable(1);
    example->removeFromTable(2);
    std::cout <<example->removeFromTable(2)<<  std::endl;;
    example->removeFromTable(3);
    example->removeFromTable(4);
    example->removeFromTable(5);
    example->removeFromTable(6);
    example->removeFromTable(7);


    std::cout <<"d"<<  std::endl;
    delete example;
    return 0;
}
