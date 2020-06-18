//
// Created by Dor on 12/06/2020.
//

#include "library2.h"
#include "MusicManager.h"

////////////////////////////////////insert memory check---------------------------------------
using namespace AVL;

void *Init() {
    try {
        MusicManager *DS = new MusicManager();
        return (void *) DS;
    }
    catch (std::bad_alloc& ba){
        return NULL;
    }
}
StatusType AddArtist(void *DS, int artistID) {
    if (artistID<=0 || DS==NULL){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->AddArtist(artistID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}

StatusType RemoveArtist(void *DS, int artistID){
    if (artistID<=0 || DS==NULL){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->RemoveArtist(artistID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}
StatusType AddSong(void *DS, int artistID, int songID){
    if (artistID<=0 || DS==NULL||songID<=0){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->AddSong(artistID, songID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}

StatusType RemoveSong(void *DS, int artistID, int songID){
    if (artistID<=0 || DS==NULL||songID<=0){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->RemoveSong(artistID, songID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }

}
StatusType AddToSongCount(void *DS, int artistID, int songID, int count){
    if (artistID<=0 || DS==NULL||songID<=0|| count<=0){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->AddToSongCount(artistID, songID, count);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}
StatusType GetArtistBestSong(void *DS, int artistID, int *songID){
    if (artistID<=0 || DS==NULL ||songID==NULL){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->GetArtistBestSong(artistID, songID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}

StatusType GetRecommendedSongInPlace(void *DS, int rank, int *artistID, int *songID){
    if ( DS ==NULL || rank <=0 || artistID==NULL || songID==NULL ){
        return INVALID_INPUT;
    }
    try {
        return ((MusicManager *) DS)->GetRecommendedSongInPlace(rank, artistID, songID);
    }
    catch (std::bad_alloc& ba){
        return ALLOCATION_ERROR;
    }
}



void Quit(void** DS){
        if (DS == NULL){
            return;
        }
        else{
            delete ((MusicManager *)*DS);
            *DS = NULL;
        }
    return;
    }

