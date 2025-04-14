// Create a structure about a `Song`
#include <iostream>

constexpr size_t MAX_TITLE_LENGTH = 100;
constexpr size_t MAX_ARTIST_LENGTH = 100;
constexpr size_t MAX_GENRE_LENGTH = 20;
constexpr float MIN_RATING = 0.0f;
constexpr float MAX_RATING = 5.0f;

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

int main()
{
    Song song;
    song.readSong();
    song.printSong();
}