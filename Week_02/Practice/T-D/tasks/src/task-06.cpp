// Create a structure about a `Playlist`, described with at most 64 `Songs`
#include <iostream>

constexpr size_t MAX_TITLE_LENGTH = 100;
constexpr size_t MAX_ARTIST_LENGTH = 100;
constexpr size_t MAX_GENRE_LENGTH = 20;
constexpr float MIN_RATING = 0.0f;
constexpr float MAX_RATING = 5.0f;
constexpr size_t MAX_SONGS_IN_PLAYLIST = 64;

enum class Genre
{
    Rock,
    Pop,
    ThrashMetal,
    KPop,
    Chalga,
    Unknown
};

// Helper functions
Genre getGenreFromString(const char* genreStr)
{
    if (genreStr[0] == 'R')
        return Genre::Rock;
    if (genreStr[0] == 'P')
        return Genre::Pop;
    if (genreStr[0] == 'T')
        return Genre::ThrashMetal;
    if (genreStr[0] == 'K')
        return Genre::KPop;
    if (genreStr[0] == 'C')
        return Genre::Chalga;
    return Genre::Unknown;
}

const char* convertGenreToString(Genre genre)
{
    switch (genre)
    {
    case Genre::Rock:
        return "Rock";
    case Genre::Pop:
        return "Pop";
    case Genre::ThrashMetal:
        return "Thrash Metal";
    case Genre::KPop:
        return "K-pop";
    case Genre::Chalga:
        return "Chalga";
    default:
        return "Unknown";
    }
}

struct Song
{
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    Genre genre;
    float rating; // From 0.0 to 5.0
    unsigned int playCount;

    void readSong()
    {
        char genreStr[MAX_GENRE_LENGTH];

        std::cout << "Enter song title: ";
        // std::cin.ignore();
        std::cin.getline(title, MAX_TITLE_LENGTH);

        std::cout << "Enter artist name: ";
        std::cin.getline(artist, MAX_ARTIST_LENGTH);

        std::cout << "Enter genre: ";
        std::cin.getline(genreStr, MAX_GENRE_LENGTH);
        genre = getGenreFromString(genreStr);

        std::cout << "Enter rating: ";
        std::cin >> rating;
        if (rating < MIN_RATING)
            rating = MIN_RATING;
        if (rating > MAX_RATING)
            rating = MAX_RATING;

        std::cout << "Enter number of listens: ";
        std::cin >> playCount;
        if (playCount < 0)
            playCount = 0;
    }

    void printSong() const
    {
        std::cout << "\n(" << this->title
                  << ", " << this->artist
                  << ", " << convertGenreToString(genre)
                  << ", " << this->rating
                  << " / 5, " << this->playCount
                  << ")\n";
    }
};

struct Playlist
{
    Song songs[MAX_SONGS_IN_PLAYLIST];
    int songCount = 0;

    // Add a song to the playlist
    void addSong(const Song& songToAdd)
    {
        if (songCount >= MAX_SONGS_IN_PLAYLIST)
        {
            std::cout << "Maximum number of songs reached in this playlist!\n";
            return;
        }
        songs[songCount++] = songToAdd;
        std::cout << "Song added successfully! Currently the playlist has "
                  << songCount << " songs.\n";
    }

    Song* findSongInPlaylistByTitle(const Song& songToFind)
    {
        for (size_t i = 0; i < songCount; i++)
        {
            bool isMatched = true;
            for (size_t j = 0; songToFind.title[j] != '\0' || songs[i].title[j] != '\0'; j++)
            {
                if (songToFind.title[j] != songs[i].title[j])
                {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched)
            {
                return &songs[i];
            }
        }
        return nullptr;
    }

    // Сортиране на песните по подаден предикат, приемащ като аргументи 2 песни
    void sortSongsByPred(bool (*compare)(const Song&, const Song&))
    {
        for (size_t i = 0; i < songCount - 1; i++)
        {
            for (size_t j = 0; j < songCount - 1 - i; j++)
            {
                if (!compare(songs[j], songs[j + 1]))
                {
                    Song temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            }
        }
    }

    // Print all songs in the playlist
    void printSongsInPlaylist() const
    {
        if (songCount == 0)
        {
            std::cout << "Playlist is empty, nothing to print!";
            return;
        }
        std::cout << "\nPlaylist:\n";
        for (size_t i = 0; i < songCount; ++i)
        {
            songs[i].printSong();
        }
        std::cout << std::endl;
    }
};

// Comparison functions for sorting
bool sortPlaylistByRatingDescending(const Song& first, const Song& second)
{
    return first.rating > second.rating;
}

bool sortPlaylistByPlayCountDescending(const Song& first, const Song& second)
{
    return first.playCount > second.playCount;
}

bool sortPlaylistByTitleAscending(const Song& first, const Song& second)
{
    for (size_t i = 0; first.title[i] != '\0' || second.title[i] != '\0'; ++i)
    {
        if (first.title[i] != second.title[i])
            return first.title[i] < second.title[i];
    }
    return false;
}

int main()
{
    Playlist myPlaylist;

    // Manually adding test songs
    Song song1 = {"Thunderstruck", "AC/DC", Genre::Rock, 4.8, 500000};
    Song song2 = {"Bohemian Rhapsody", "Queen", Genre::Rock, 5.0, 1000000};
    Song song3 = {"Enter Sandman", "Metallica", Genre::ThrashMetal, 4.6, 750000};

    myPlaylist.addSong(song1);
    myPlaylist.addSong(song2);
    myPlaylist.addSong(song3);

    std::cout << "\nOriginal Playlist:\n";
    myPlaylist.printSongsInPlaylist();

    std::cout << "\nSorting by Rating (Descending):\n";
    myPlaylist.sortSongsByPred(sortPlaylistByRatingDescending);
    myPlaylist.printSongsInPlaylist();

    std::cout << "\nSorting by Play Count (Descending):\n";
    myPlaylist.sortSongsByPred(sortPlaylistByPlayCountDescending);
    myPlaylist.printSongsInPlaylist();

    std::cout << "\nSorting by Title (Alphabetical Order):\n";
    myPlaylist.sortSongsByPred(sortPlaylistByTitleAscending);
    myPlaylist.printSongsInPlaylist();
}