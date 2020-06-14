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



    using namespace AVLUtils;
    using namespace AVL;

    class MusicManager {

    public:
        const HashTable <Artist> &getArrayOfArtists() const {
            return array_of_artists;
        }


        AVL_tree <MainTreeSongInfo> &getMainSongsTree() {
            return main_songs_tree;
        }

        StatusType AddArtist(int artistId);

        StatusType RemoveArtist(int artistID);

        StatusType AddSong(int artistID, int songID);

        StatusType RemoveSong(int artistID, int songID);

        StatusType AddToSongCount(int artistID, int songID, int count);

        StatusType GetArtistBestSong(int artistID, int *songID);

        StatusType GetRecommendedSongInPlace(int rank, int *artistID, int *songID);


    private:
        HashTable <Artist> array_of_artists;
        AVL_tree <MainTreeSongInfo> main_songs_tree;
    };


StatusType MusicManager::GetRecommendedSongInPlace(int rank, int *artistID, int *songID) {
    int sizeOfTree = this->main_songs_tree.getRoot()->getSizeOfInnerTree();
    AVL::AVL_tree_node<MainTreeSongInfo>* wanted_song =  this->main_songs_tree.select(sizeOfTree-(rank-1));
    if(!wanted_song){
        return FAILURE;
    }
    else {
        *artistID = wanted_song->getDataKey()->getArtistId();
        *songID = wanted_song->getDataKey()->getSongId();
        return SUCCESS;
    }

}

StatusType MusicManager::AddArtist(int artistId) {
        return (this->array_of_artists.addToTable(artistId));
    }
    StatusType MusicManager::RemoveArtist(int artistID) {
        Link_Node<Artist> *NodeToRemove = this->array_of_artists.retrieve_member(artistID);
        if (NodeToRemove == NULL || NodeToRemove->getElement()->getMostStreamsSong() != NULL) {
            return FAILURE;
        }
        return this->array_of_artists.removeFromTable(artistID);
    }

    StatusType MusicManager::AddSong(int artistID, int songID) {
        Link_Node<Artist> *NodeToAddSong = this->array_of_artists.retrieve_member(artistID);
        if (NodeToAddSong == NULL) {
            return FAILURE;
        }
        ArtistRegularTreeInfo dummy_key = ArtistRegularTreeInfo(songID);
        if (NodeToAddSong->getElement()->getRegularTree().find_node(&dummy_key) != NULL) {
            return FAILURE; ///there is a song with the given singID to the current artist
        }
        NodeToAddSong->getElement()->addSong(songID); //adding the song to the artist
        //MainTreeSongInfo *new_node_key = new MainTreeSongInfo(artistID,songID); //adding the song to the main_songs_tree
        MainTreeSongInfo *new_node_key = new MainTreeSongInfo(songID,artistID);
        AVL_tree_node<MainTreeSongInfo> *new_node = new AVL_tree_node<MainTreeSongInfo>(new_node_key);
        this->getMainSongsTree().insert(*new_node);
        return SUCCESS;
    }

    StatusType MusicManager::RemoveSong(int artistID, int songID) {
        Link_Node<Artist> *NodeToRemoveSong = this->array_of_artists.retrieve_member(artistID);
        if (NodeToRemoveSong == NULL) {
            return FAILURE;
        }
        ArtistRegularTreeInfo dummy_key = ArtistRegularTreeInfo(songID);
        if (NodeToRemoveSong->getElement()->getRegularTree().find_node(&dummy_key) == NULL) {
            return FAILURE;
        }
        NodeToRemoveSong->getElement()->removeSong(songID); //removing the song from the artist

        MainTreeSongInfo* new_node_key = new MainTreeSongInfo(songID,artistID); //removing the song to the main_songs_tree

        AVL_tree_node<MainTreeSongInfo> new_node = AVL_tree_node<MainTreeSongInfo>(new_node_key);

        this->getMainSongsTree().remove(new_node);
        return SUCCESS;
    }






    StatusType MusicManager::AddToSongCount(int artistID, int songID, int count) {
        Link_Node<Artist> *NodeToAddSongCount = this->array_of_artists.retrieve_member(artistID);
        if (NodeToAddSongCount == NULL) {
            return FAILURE;
        }
        ///////////////////////////////////////////////////////////////////////////  check if necessary  below ///////////////////////////////////////////////
        ArtistStreamTreeInfo dummy_key = ArtistStreamTreeInfo(songID);
        AVL_tree_node<ArtistStreamTreeInfo> *current_song = NodeToAddSongCount->getElement()->getStreamTree().find_node(
                &dummy_key);
        if (current_song == NULL) {
            return FAILURE; ///there is no a song with the given singID to the current artist
        }
        ArtistStreamTreeInfo *copy_of_current_song = new ArtistStreamTreeInfo(songID);
        AVL_tree_node<ArtistStreamTreeInfo> *incrementedCopyOfSong = new AVL_tree_node<ArtistStreamTreeInfo>(
                copy_of_current_song);
        ArtistStreamTreeInfo *current_song_data = current_song->getDataKey();
        int old_num_of_streams=current_song_data->getNumOfStreams();////this was added 14/6
        copy_of_current_song->setNumOfStreams(current_song_data->getNumOfStreams() + count);
        NodeToAddSongCount->getElement()->getStreamTree().remove(*current_song);
        NodeToAddSongCount->getElement()->getStreamTree().insert(*incrementedCopyOfSong);
        ////update max
        NodeToAddSongCount->getElement()->updateMostStreamsSong();
        ///global_tree
        MainTreeSongInfo dummy_main_key = MainTreeSongInfo(songID, artistID);
        dummy_main_key.setNumOfStreams(old_num_of_streams); ////this was added 14/6
        AVL_tree_node<MainTreeSongInfo> *current_main_song = this->main_songs_tree.find_node(&dummy_main_key);
        MainTreeSongInfo *copy_of_current_main_song = new MainTreeSongInfo(songID, artistID);
        AVL_tree_node<MainTreeSongInfo> *incrementedCopyOf_main_Song = new AVL_tree_node<MainTreeSongInfo>(
                copy_of_current_main_song);
        incrementedCopyOf_main_Song->getDataKey()->setNumOfStreams(
                current_main_song->getDataKey()->getNumOfStreams() + count);
        this->main_songs_tree.remove(*current_main_song);
        this->main_songs_tree.insert(*incrementedCopyOf_main_Song);
        return SUCCESS;
    }

    StatusType MusicManager::GetArtistBestSong(int artistID, int *songID) {
        Link_Node<Artist> *NodeToGetArtistBestSong = this->array_of_artists.retrieve_member(artistID);
        if (NodeToGetArtistBestSong == NULL || NodeToGetArtistBestSong->getElement()->getMostStreamsSong() == NULL) {
            return FAILURE;
        }
        *songID = (NodeToGetArtistBestSong->getElement()->getMostStreamsSong()->getDataKey()->getSongId());
        return SUCCESS;
    }




#endif //EX2_HASH_MUSICMANAGER_H
