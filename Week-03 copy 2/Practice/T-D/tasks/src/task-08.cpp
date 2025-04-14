/*
    8. Надградете функционалността на задача 5 от предния практикум (практикум 2),
    като добавите възможност за записване на плейлистите в текстов файл и четене на плейлисти от текстов файл.
    Начинът на сериализация на данните зависи от вас.
*/

#include <fstream>
#include <iostream>

constexpr size_t MAX_TEXT = 101;
constexpr size_t MAX_SONGS = 64;

enum Genre
{
    ROCK,
    POP,
    THRASH_METAL,
    KPOP,
    CHALGA,
    GENRE_COUNT
};

const char* genreToStr(Genre g)
{
    switch (g)
    {
    case ROCK:
        return "Rock";
    case POP:
        return "Pop";
    case THRASH_METAL:
        return "Thrash Metal";
    case KPOP:
        return "K-pop";
    case CHALGA:
        return "Chalga";
    default:
        return "Unknown";
    }
}

Genre strToGenre(const char* str)
{
    if (strcmp(str, "Rock") == 0)
        return ROCK;
    if (strcmp(str, "Pop") == 0)
        return POP;
    if (strcmp(str, "Thrash Metal") == 0)
        return THRASH_METAL;
    if (strcmp(str, "K-pop") == 0)
        return KPOP;
    if (strcmp(str, "Chalga") == 0)
        return CHALGA;
    return GENRE_COUNT; // invalid genre
}

struct Song
{
    char title[MAX_TEXT];
    char artist[MAX_TEXT];
    Genre genre;
    float rating;
    unsigned int playCount;
};

struct Playlist
{
    Song songs[MAX_SONGS];
    size_t size = 0;
};

bool writePlaylistToFile(const char* outputFilename, const Playlist& playlist)
{
    if (!outputFilename)
        return false;
    std::ofstream outFile(outputFilename);
    if (!outFile.is_open())
        return false;

    for (size_t i = 0; i < playlist.size; ++i)
    {
        const Song& song = playlist.songs[i];

        outFile << song.title << '\n'
                << song.artist << '\n'
                << genreToStr(song.genre) << '\n'
                << song.rating << '\n'
                << song.playCount << '\n';
    }

    outFile.close();
    return true;
}

bool readPlaylistFromFile(const char* filename, Playlist& playlist)
{
    if (!filename)
        return false;
    std::ifstream inFile(filename);
    if (!inFile.is_open())
        return false;

    playlist.size = 0;

    while (inFile && playlist.size < MAX_SONGS)
    {
        Song& song = playlist.songs[playlist.size];

        inFile.getline(song.title, MAX_TEXT);
        inFile.getline(song.artist, MAX_TEXT);

        char genreBuffer[32];
        inFile.getline(genreBuffer, 32);
        song.genre = strToGenre(genreBuffer);

        inFile >> song.rating;
        inFile >> song.playCount;
        inFile.ignore(); // пропусни '\n' след playCount

        ++playlist.size;
    }

    inFile.close();
    return true;
}

int main()
{
    Playlist playlist;

    // Добавяме примерни песни
    strcpy(playlist.songs[0].title, "Sweet Child O' Mine");
    strcpy(playlist.songs[0].artist, "Guns N' Roses");
    playlist.songs[0].genre = ROCK;
    playlist.songs[0].rating = 4.8f;
    playlist.songs[0].playCount = 12345;

    strcpy(playlist.songs[1].title, "As If It's Your Last");
    strcpy(playlist.songs[1].artist, "BLACKPINK");
    playlist.songs[1].genre = KPOP;
    playlist.songs[1].rating = 4.6f;
    playlist.songs[1].playCount = 54321;

    playlist.size = 2;

    writePlaylistToFile("task08_playlist.txt", playlist);

    Playlist loaded;
    readPlaylistFromFile("task08_playlist.txt", loaded);

    std::cout << "Прочетени песни от файл:\n";
    for (size_t i = 0; i < loaded.size; ++i)
    {
        std::cout << loaded.songs[i].title << " | "
                  << loaded.songs[i].artist << " | "
                  << genreToStr(loaded.songs[i].genre) << " | "
                  << loaded.songs[i].rating << " | "
                  << loaded.songs[i].playCount << '\n';
    }

    return 0;
}