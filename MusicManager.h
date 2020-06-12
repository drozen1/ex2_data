//
// Created by Dor on 10/06/2020.
//
#include <ostream>
#include "Artist.h"
#include "hashTable.h"
#include "AVL_types.h"

#ifndef EX2_HASH_MUSICMANAGER_H
#define EX2_HASH_MUSICMANAGER_H


/**
 *      ERRRRRRORRRRRRRR
 *
 * before inserting into the streams tree check there isnt already a node with the given id.
 *
 *
 */

namespace AVL {

    using namespace AVLUtils;

    class MusicManager {

    public:
        const HashTable <Artist> &getArrayOfArtists() const {
            return array_of_artists;
        }


        AVL_tree <MainTreeSongInfo> &getMainSongsTree()  {
            return main_songs_tree;
        }

        StatusType AddArtist(int artistId);
        StatusType RemoveArtist(int artistID);
        StatusType AddSong(int artistID,int songID);
        StatusType  RemoveSong(int artistID,int songID);
    private:
        HashTable<Artist> array_of_artists;
        AVL_tree<MainTreeSongInfo> main_songs_tree;
    };

    StatusType MusicManager::AddArtist(int artistId) {
        return (this->array_of_artists.addToTable(artistId));
    }

    StatusType MusicManager::RemoveArtist(int artistID) {
        Link_Node<Artist> *NodeToRemove=this->array_of_artists.retrieve_member(artistID);
        if (NodeToRemove==NULL || NodeToRemove->getElement()->getMostStreamsSong()!=NULL){
            return FAILURE;
        }
        return this->array_of_artists.removeFromTable(artistID);
    }

    StatusType MusicManager::AddSong(int artistID, int songID) {
        Link_Node<Artist> *NodeToAddSong=this->array_of_artists.retrieve_member(artistID);
        if (NodeToAddSong==NULL ){
            return FAILURE;
        }
        ArtistRegularTreeInfo dummy_key = ArtistRegularTreeInfo(songID);
        if(NodeToAddSong->getElement()->getRegularTree().find_node(&dummy_key) !=NULL){
            return FAILURE; ///there is a song with the given singID to the current artist
        }
        NodeToAddSong->getElement()->addSong(songID); //adding the song to the artist
        MainTreeSongInfo* new_node_key= new MainTreeSongInfo(artistID,songID); //adding the song to the main_songs_tree
        AVL_tree_node<MainTreeSongInfo>* new_node = new AVL_tree_node<MainTreeSongInfo>(new_node_key);
        this->getMainSongsTree().insert(*new_node);
        return SUCCESS;
    }

    StatusType MusicManager::RemoveSong(int artistID, int songID) {
        Link_Node<Artist> *NodeToRemoveSong=this->array_of_artists.retrieve_member(artistID);
        if (NodeToRemoveSong==NULL ){
            return FAILURE;
        }
        ArtistRegularTreeInfo dummy_key = ArtistRegularTreeInfo(songID);
        if(NodeToRemoveSong->getElement()->getRegularTree().find_node(&dummy_key) ==NULL){
            return FAILURE; ///there is a song with the given singID to the current artist
        }
        NodeToRemoveSong->getElement()->removeSong(songID); //removing the song to the artist
        MainTreeSongInfo new_node_key= MainTreeSongInfo(artistID,songID); //adding the song to the main_songs_tree
        AVL_tree_node<MainTreeSongInfo> new_node = AVL_tree_node<MainTreeSongInfo>(&new_node_key);
        this->getMainSongsTree().remove(new_node);

        return SUCCESS;
    }


}




#endif //EX2_HASH_MUSICMANAGER_H
