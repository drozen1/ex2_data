//
// Created by Dor on 12/06/2020.
//

#include "library2.h"
#include "MusicManager.h"

////////////////////////////////////insert memory check---------------------------------------

void *Init() {
    MusicManager *DS = new MusicManager();
    return (void *)DS;
}
StatusType AddArtist(void *DS, int artistID) {
    if (artistID<=0 || DS==NULL){
        return INVALID_INPUT
    }

    return ((MusicManager *)DS)-> AddArtist(artistID);
}

StatusType RemoveArtist(void *DS, int artistID){
    if (artistID<=0 || DS==NULL){
        return INVALID_INPUT
    }
    return ((MusicManager *)DS)-> RemoveArtist(artistID);
}
StatusType AddSong(void *DS, int artistID, int songID){
    if (artistID<=0 || DS==NULL||songID<=0){
        return INVALID_INPUT
    }
    return ((MusicManager *)DS)-> AddSong(artistID,songID);
}

StatusType RemoveSong(void *DS, int artistID, int songID){
    if (artistID<=0 || DS==NULL||songID<=0){
        return INVALID_INPUT
    }
    return ((MusicManager *)DS)-> RemoveSong(artistID,songID);

}
StatusType AddToSongCount(void *DS, int artistID, int songID, int count){
    if (artistID<=0 || DS==NULL||songID<=0|| count<=0){
        return INVALID_INPUT
    }
    return ((MusicManager *)DS)-> AddToSongCount(artistID,songID,count);
}
