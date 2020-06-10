//
// Created by Dor on 10/06/2020.
//
#include <ostream>
#include "hashTable.h"
#include "Rank_tree.h"


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

    class ArtistRegularTreeInfo {
    public:
        ArtistRegularTreeInfo(int songId) : songId(songId) {}

        virtual ~ArtistRegularTreeInfo() {

        }
        int getSongId() const {
            return songId;
        }

        void setSongId(int songId) {
            ArtistRegularTreeInfo::songId = songId;
        }

        ArtistRegularTreeInfo& operator=(const ArtistRegularTreeInfo& rhs);

        bool operator==(const ArtistRegularTreeInfo &rhs) const {
            return songId == rhs.songId;
        }

        bool operator!=(const ArtistRegularTreeInfo &rhs) const {
            return !(rhs == *this);
        }

        bool operator<(const ArtistRegularTreeInfo &rhs) const {
            return songId < rhs.songId;
        }

        bool operator>(const ArtistRegularTreeInfo &rhs) const {
            return rhs < *this;
        }

        bool operator<=(const ArtistRegularTreeInfo &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const ArtistRegularTreeInfo &rhs) const {
            return !(*this < rhs);
        }
        friend std::ostream &operator<<(std::ostream &os, const ArtistRegularTreeInfo &info) {
            os << "songId: " << info.songId;
            return os;
        }

    private:
        int songId;
    };

ArtistRegularTreeInfo &ArtistRegularTreeInfo::operator=(const ArtistRegularTreeInfo &rhs) {
    this->songId=rhs.getSongId();
    return *this;
}

class ArtistStreamTreeInfo{
public:
    ArtistStreamTreeInfo(int songId) : numOfStreams(0), songId(songId) {}

    int getNumOfStreams() const {
        return numOfStreams;
    }

    bool operator==(const ArtistStreamTreeInfo &rhs) const {
        return songId == rhs.songId;
    }

    bool operator<(const ArtistStreamTreeInfo &rhs) const {
        if(numOfStreams==rhs.numOfStreams){
            return this->songId > rhs.songId;
        }
        return numOfStreams < rhs.numOfStreams;
    }

    friend std::ostream &operator<<(std::ostream &os, const ArtistStreamTreeInfo &info) {
        os << "numOfStreams: " << info.numOfStreams << " songId: " << info.songId;
        return os;
    }

    bool operator>(const ArtistStreamTreeInfo &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const ArtistStreamTreeInfo &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const ArtistStreamTreeInfo &rhs) const {
        return !(*this < rhs);
    }

    bool operator!=(const ArtistStreamTreeInfo &rhs) const {
        return !(rhs == *this);
    }

    void setNumOfStreams(int numOfStreams) {
        ArtistStreamTreeInfo::numOfStreams = numOfStreams;
    }

    int getSongId() const {
        return songId;
    }

    void setSongId(int songId) {
        ArtistStreamTreeInfo::songId = songId;
    }

    void incrementNumberOfStreams(int count){
        this->setNumOfStreams(numOfStreams + count);
    }

private:
    int numOfStreams;
    int songId;
};


class MainTreeSongInfo{

public:

    MainTreeSongInfo(int artistId, int songId) : songId(songId), artistId(artistId),numOfStreams(0) {}


    int getNumOfStreams() const {
        return numOfStreams;
    }

    void setNumOfStreams(int numOfStreams) {
        MainTreeSongInfo::numOfStreams = numOfStreams;
    }

    int getSongId() const {
        return songId;
    }

    void setSongId(int songId) {
        MainTreeSongInfo::songId = songId;
    }

    int getArtistId() const {
        return artistId;
    }

    void setArtistId(int artistId) {
        MainTreeSongInfo::artistId = artistId;
    }



    bool operator==(const MainTreeSongInfo &rhs) const {
        return numOfStreams == rhs.numOfStreams &&
               songId == rhs.songId &&
               artistId == rhs.artistId;
    }

    bool operator!=(const MainTreeSongInfo &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const MainTreeSongInfo &rhs) const {
        if (numOfStreams < rhs.numOfStreams)
            return true;
        if (numOfStreams>rhs.numOfStreams){
            return false;
        }

        if (artistId > rhs.artistId)
            return true;
        if (artistId < rhs.artistId)
            return false;

        if (songId > rhs.songId){
            return true;
        }
        return false;
    }

    bool operator>(const MainTreeSongInfo &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const MainTreeSongInfo &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const MainTreeSongInfo &rhs) const {
        return !(*this < rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const MainTreeSongInfo &info) {
        os << "numOfStreams: " << info.numOfStreams << " songId: " << info.songId << " artistId: " << info.artistId;
        return os;
    }

private:
    int numOfStreams;
    int songId;
    int artistId;


};


class Artist{

public:

    AVL::AVL_tree_node<ArtistStreamTreeInfo> *getMostStreamsSong() const {
        return most_streams_song;
    }

    void updateMostStreamsSong() {
        most_streams_song = this->stream_tree.retrieveMax();
    }

    Artist(): most_streams_song(NULL) {
    }

    StatusType addSong(int song_id);

    StatusType removeSong(int song_id);

private:
    AVL::AVL_tree<ArtistRegularTreeInfo> regular_tree;
    AVL::AVL_tree<ArtistStreamTreeInfo> stream_tree;
    AVL::AVL_tree_node<ArtistStreamTreeInfo>* most_streams_song;

};

StatusType Artist::addSong(int song_id) {
    ArtistRegularTreeInfo* regular_key= new ArtistRegularTreeInfo(song_id);
    if (regular_tree.find_node(regular_key)!=NULL){
        delete regular_key;
        return FAILURE;
    }
    AVL::AVL_tree_node<ArtistRegularTreeInfo>* regular_node=  new AVL::AVL_tree_node<ArtistRegularTreeInfo>(regular_key);
    regular_tree.insert(*regular_node);
    ArtistStreamTreeInfo* stream_key= new ArtistStreamTreeInfo(song_id);
    AVL::AVL_tree_node<ArtistStreamTreeInfo>* stream_node=  new AVL::AVL_tree_node<ArtistStreamTreeInfo>(stream_key);
    stream_tree.insert(*stream_node);
    this->updateMostStreamsSong();
    return SUCCESS;
}

StatusType Artist::removeSong(int song_id) {
    ArtistRegularTreeInfo dummy_regular_key= ArtistRegularTreeInfo(song_id);
    AVL::AVL_tree_node<ArtistRegularTreeInfo> dummy_regular_node =  AVL::AVL_tree_node<ArtistRegularTreeInfo>(&dummy_regular_key);
    if(this->regular_tree.remove(dummy_regular_node)==FAILURE){
        return FAILURE;
    }
    ArtistStreamTreeInfo dummy_stream_key=  ArtistStreamTreeInfo(song_id);
    AVL::AVL_tree_node<ArtistStreamTreeInfo> dummy_stream_node =  AVL::AVL_tree_node<ArtistStreamTreeInfo>(&dummy_stream_key);
    stream_tree.remove(dummy_stream_node);
    this->updateMostStreamsSong();
    return SUCCESS;
}


#endif //EX2_HASH_MUSICMANAGER_H
