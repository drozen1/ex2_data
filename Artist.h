//
// Created by Dor on 12/06/2020.
//

#ifndef EX2_HASH_ARTIST_H
#define EX2_HASH_ARTIST_H
#include "hashTable.h"
#include "Rank_tree.h"
#include "AVL_types.h"

using namespace AVLUtils;

class ArtistRegularTreeInfo {
public:
    ArtistRegularTreeInfo(int songId, int numOfStreams=0) : songId(songId),numOfStreams(numOfStreams) {}

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
    int numOfStreams;
public:
    int getNumOfStreams() const;

    void setNumOfStreams(int numOfStreams);
};

ArtistRegularTreeInfo &ArtistRegularTreeInfo::operator=(const ArtistRegularTreeInfo &rhs) {
    this->songId=rhs.getSongId();
    return *this;
}

int ArtistRegularTreeInfo::getNumOfStreams() const {
    return numOfStreams;
}

void ArtistRegularTreeInfo::setNumOfStreams(int numOfStreams) {
    ArtistRegularTreeInfo::numOfStreams = numOfStreams;
}

class ArtistStreamTreeInfo{
public:
    ArtistStreamTreeInfo(int songId, int numOfStreams=0) :  songId(songId),numOfStreams(numOfStreams) {}

    int getNumOfStreams()  {
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

    int getSongId()  {
        return songId;
    }

    void setSongId(int songId) {
        ArtistStreamTreeInfo::songId = songId;
    }

    void incrementNumberOfStreams(int count){
        this->setNumOfStreams(numOfStreams + count);
    }

private:
    int songId;
    int numOfStreams;

};


class MainTreeSongInfo{

public:

    MainTreeSongInfo(int songId, int artistId,int numOfStreams=0) : songId(songId), artistId(artistId),numOfStreams(numOfStreams) {}


    int getNumOfStreams() {
        return numOfStreams;
    }

    void setNumOfStreams(int numOfStreams) {
        MainTreeSongInfo::numOfStreams = numOfStreams;
    }

    int getSongId()  {
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
        return songId == rhs.songId &&
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
    int songId;
    int artistId;
    int numOfStreams;
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

    StatusType removeSong(int song_id,int num_of_streams);

public:
     AVL::AVL_tree<ArtistRegularTreeInfo> &getRegularTree() ;

     AVL::AVL_tree<ArtistStreamTreeInfo> &getStreamTree();

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


StatusType Artist::removeSong(int song_id,int num_of_streams) {

    ArtistRegularTreeInfo* dummy_regular_key= new ArtistRegularTreeInfo(song_id);


    AVL::AVL_tree_node<ArtistRegularTreeInfo>* dummy_regular_node = new AVL::AVL_tree_node<ArtistRegularTreeInfo>(dummy_regular_key);
    if(this->regular_tree.remove(*dummy_regular_node)==FAILURE){
        return FAILURE;
    }

    ArtistStreamTreeInfo* dummy_stream_key= new  ArtistStreamTreeInfo(song_id,num_of_streams);
    AVL::AVL_tree_node<ArtistStreamTreeInfo>* dummy_stream_node =  new AVL::AVL_tree_node<ArtistStreamTreeInfo>(dummy_stream_key);

    stream_tree.remove(*dummy_stream_node);
    delete dummy_stream_node;
    delete dummy_regular_node;
    this->updateMostStreamsSong();
    return SUCCESS;
}

AVL::AVL_tree<ArtistRegularTreeInfo> &Artist::getRegularTree() {
    return regular_tree;
}

 AVL::AVL_tree<ArtistStreamTreeInfo> &Artist::getStreamTree()  {
    return stream_tree;
}

#endif //EX2_HASH_ARTIST_H
