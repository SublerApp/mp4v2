///////////////////////////////////////////////////////////////////////////////
//
//  The contents of this file are subject to the Mozilla Public License
//  Version 1.1 (the "License"); you may not use this file except in
//  compliance with the License. You may obtain a copy of the License at
//  http://www.mozilla.org/MPL/
//
//  Software distributed under the License is distributed on an "AS IS"
//  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
//  License for the specific language governing rights and limitations
//  under the License.
// 
//  The Original Code is MP4v2.
// 
//  The Initial Developer of the Original Code is Kona Blend.
//  Portions created by Kona Blend are Copyright (C) 2008.
//  Portions created by David Byron are Copyright (C) 2011.
//  All Rights Reserved.
//
//  Contributors:
//      Kona Blend, kona8lend@gmail.com
//      Rouven Wessling, mp4v2@rouvenwessling.de
//      David Byron, dbyron@dbyron.com
//
///////////////////////////////////////////////////////////////////////////////

#ifndef MP4V2_IMPL_ITMF_TAGS_H
#define MP4V2_IMPL_ITMF_TAGS_H

namespace mp4v2 { namespace impl { namespace itmf {

///////////////////////////////////////////////////////////////////////////////

class Tags
{
public:
    static const string CODE_NAME;
    static const string CODE_ARTIST;
    static const string CODE_ALBUMARTIST;
    static const string CODE_ALBUM;
    static const string CODE_GROUPING;
    static const string CODE_COMPOSER;
    static const string CODE_COMMENTS;
    static const string CODE_GENRE;
    static const string CODE_GENRETYPE;
    static const string CODE_RELEASEDATE;
    static const string CODE_TRACK;
    static const string CODE_DISK;
    static const string CODE_TEMPO;
    static const string CODE_COMPILATION;

    static const string CODE_TRACKSUBTITLE;
    static const string CODE_SONGDESCRIPTION;
    static const string CODE_DIRECTOR;
    static const string CODE_ARTDIRECTOR;
    static const string CODE_ARRANGER;
    static const string CODE_LYRICIST;
    static const string CODE_ACKNOWLEDGEMENT;
    static const string CODE_CONDUCTOR;

    static const string CODE_WORK_NAME;
    static const string CODE_MOVEMENT_NAME;
    static const string CODE_MOVEMENT_NUMBER;
    static const string CODE_MOVEMENT_COUNT;
    static const string CODE_SHOW_WORK_AND_MOVEMENT;

    static const string CODE_LINEARNOTES;
    static const string CODE_RECORDCOMPANY;
    static const string CODE_ORIGINALARTIST;
    static const string CODE_PHONOGRAMRIGHTS;
    static const string CODE_PRODUCER;
    static const string CODE_PERFORMER;
    static const string CODE_PUBLISHER;
    static const string CODE_SOUNDENGINEER;
    static const string CODE_SOLOIST;
    static const string CODE_CREDITS;
    static const string CODE_THANKS;
    static const string CODE_ONLINEEXTRAS;
    static const string CODE_EXECUTIVEPRODUCER;

    static const string CODE_TVSHOW;
    static const string CODE_TVNETWORK;
    static const string CODE_TVEPISODEID;
    static const string CODE_TVSEASON;
    static const string CODE_TVEPISODE;

    static const string CODE_DESCRIPTION;
    static const string CODE_LONGDESCRIPTION;
    static const string CODE_SERIESDESCRIPTION;
    static const string CODE_LYRICS;

    static const string CODE_SORTNAME;
    static const string CODE_SORTARTIST;
    static const string CODE_SORTALBUMARTIST;
    static const string CODE_SORTALBUM;
    static const string CODE_SORTCOMPOSER;
    static const string CODE_SORTTVSHOW;

    static const string CODE_COPYRIGHT;
    static const string CODE_ENCODINGTOOL;   
    static const string CODE_ENCODEDBY;
    static const string CODE_PURCHASEDATE;

    static const string CODE_ITUNESU;
    static const string CODE_PODCAST;
    static const string CODE_KEYWORDS;
    static const string CODE_CATEGORY;

    static const string CODE_HDVIDEO;
    static const string CODE_MEDIATYPE;
    static const string CODE_CONTENTRATING;
    static const string CODE_GAPLESS;

    static const string CODE_ITUNESACCOUNT;
    static const string CODE_ITUNESACCOUNTTYPE;
    static const string CODE_ITUNESCOUNTRY;
    static const string CODE_CONTENTID;
    static const string CODE_ARTISTID;
    static const string CODE_PLAYLISTID;
    static const string CODE_GENREID;
    static const string CODE_COMPOSERID;
    static const string CODE_XID;

public:
    string      name;
    string      artist;
    string      albumArtist;
    string      album;
    string      grouping;
    string      composer;
    string      comments;
    string      genre;
    uint16_t    genreType;
    string      releaseDate;
    MP4TagTrack track;
    MP4TagDisk  disk;
    uint16_t    tempo;
    uint8_t     compilation;

    string trackSubTitle;
    string songDescription;
    string director;
    string artDirector;
    string arranger;
    string lyricist;
    string acknowledgement;
    string conductor;

    string   workName;
    string   movementName;
    uint16_t movementNumber;
    uint16_t movementCount;
    uint8_t  showWorkAndMovement;

    string linearNotes;
    string recordCompany;
    string originalArtist;
    string phonogramRights;
    string producer;
    string performer;
    string publisher;
    string soundEngineer;
    string soloist;
    string credits;
    string thanks;
    string onlineExtras;
    string executiveProducer;

    string   tvShow;
    string   tvEpisodeID;
    uint32_t tvSeason;
    uint32_t tvEpisode;
    string   tvNetwork;

    string description;
    string longDescription;
    string seriesDescription;
    string lyrics;

    string sortName;
    string sortArtist;
    string sortAlbumArtist;
    string sortAlbum;
    string sortComposer;
    string sortTVShow;

    CoverArtBox::ItemList artwork;

    string copyright;
    string encodingTool;  
    string encodedBy;
    string purchaseDate;

    uint8_t itunesu;
    uint8_t podcast;
    string  keywords;
    string  category;

    uint8_t hdVideo;
    uint8_t mediaType;
    uint8_t contentRating;
    uint8_t gapless;

    string   iTunesAccount;
    uint8_t  iTunesAccountType;
    uint32_t iTunesCountry;
    uint32_t contentID;
    uint32_t artistID;
    uint64_t playlistID;
    uint32_t genreID;
    uint32_t composerID;
    string   xid;

    bool     hasMetadata;

public:
    Tags();
    ~Tags();

    void c_alloc ( MP4Tags*& );
    void c_fetch ( MP4Tags*&, MP4FileHandle );
    void c_store ( MP4Tags*&, MP4FileHandle );
    void c_free  ( MP4Tags*& );

    void c_addArtwork    ( MP4Tags*&, MP4TagArtwork& );
    void c_setArtwork    ( MP4Tags*&, uint32_t, MP4TagArtwork& );
    void c_removeArtwork ( MP4Tags*&, uint32_t );

    void c_setString  ( const char*, string&, const char*& );
    void c_setInteger ( const uint8_t*,  uint8_t&,  const uint8_t*& );
    void c_setInteger ( const uint16_t*, uint16_t&, const uint16_t*& );
    void c_setInteger ( const uint32_t*, uint32_t&, const uint32_t*& );
    void c_setInteger ( const uint64_t*, uint64_t&, const uint64_t*& );

    void c_setTrack ( const MP4TagTrack*, MP4TagTrack&, const MP4TagTrack*& );
    void c_setDisk  ( const MP4TagDisk*, MP4TagDisk&, const MP4TagDisk*& );

private:
    typedef map<string,MP4ItmfItem*> CodeItemMap;

private:
    void fetchString  ( const CodeItemMap&, const string&, string&, const char*& );
    void fetchInteger ( const CodeItemMap&, const string&, uint8_t&,  const uint8_t*& );
    void fetchInteger ( const CodeItemMap&, const string&, uint16_t&, const uint16_t*& );
    void fetchInteger ( const CodeItemMap&, const string&, uint32_t&, const uint32_t*& );
    void fetchInteger ( const CodeItemMap&, const string&, uint64_t&, const uint64_t*& );

    void fetchGenre ( const CodeItemMap&, uint16_t&, const uint16_t*& );
    void fetchTrack ( const CodeItemMap&, MP4TagTrack&, const MP4TagTrack*& );
    void fetchDisk  ( const CodeItemMap&, MP4TagDisk&, const MP4TagDisk*& );

    void storeString  ( MP4File&, const string&, const string&, const char* );
    void storeInteger ( MP4File&, const string&, uint8_t,  const uint8_t* );
    void storeInteger ( MP4File&, const string&, uint16_t, const uint16_t* );
    void storeInteger ( MP4File&, const string&, uint32_t, const uint32_t* );
    void storeInteger ( MP4File&, const string&, uint64_t, const uint64_t* );

    void storeGenre ( MP4File&, uint16_t, const uint16_t* );
    void storeTrack ( MP4File&, const MP4TagTrack&, const MP4TagTrack* );
    void storeDisk  ( MP4File&, const MP4TagDisk&, const MP4TagDisk* );

    void remove ( MP4File&, const string& );
    void store  ( MP4File&, const string&, MP4ItmfBasicType, const void*, uint32_t );

    void updateArtworkShadow( MP4Tags*& );
};

///////////////////////////////////////////////////////////////////////////////

}}} // namespace mp4v2::impl::itmf

#endif // MP4V2_IMPL_ITMF_TAGS_H
