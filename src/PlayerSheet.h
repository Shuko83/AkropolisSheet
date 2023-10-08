#ifndef PLAYERSHEET_H
#define PLAYERSHEET_H

#include <QHash>
#include <QObject>

class QString;

class PlayerSheet
{
public:
    enum class Color
    {
        Red,
        Blue,
        Purple,
        Yellow,
        Green,
    }; 

    explicit PlayerSheet() = default;
    explicit PlayerSheet(const PlayerSheet& other) = default;
    explicit PlayerSheet(PlayerSheet&& other) noexcept = default;

    PlayerSheet& operator= (const PlayerSheet& playerSheet);
    PlayerSheet& operator= (PlayerSheet&& playerSheet) noexcept;
    bool operator== (const PlayerSheet& other) const;
    bool operator> (const PlayerSheet& other) const;
    bool operator< (const PlayerSheet& other) const;

    void swap(PlayerSheet& playerSheet) noexcept;

    static QList<Color> getAllColor();

    void setStarsNumber(Color color, unsigned int number);
    void setScoreDistrict(Color color, unsigned int number);
    void setStones(unsigned int number);

    unsigned int getScoreDistrict(Color color) const;
    unsigned int getStars(Color color) const;
    unsigned int getStones() const;

    unsigned int getTotalScore() const;

    void reset();

private:
    QHash<Color, unsigned int> _stars;
    QHash<Color, unsigned int> _scoreDistrict;
    unsigned int _stones = 0;
};

#endif // PLAYERSHEET_H
