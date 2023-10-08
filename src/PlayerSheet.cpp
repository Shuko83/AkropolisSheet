#include "PlayerSheet.h"

#include <algorithm>

PlayerSheet& PlayerSheet::operator=(const PlayerSheet& playerSheet)
{
    if (this != &playerSheet)
    {
        _scoreDistrict = playerSheet._scoreDistrict;
        _stars = playerSheet._stars;
        _stones = playerSheet._stones;
    }
    return *this;
}

PlayerSheet& PlayerSheet::operator=(PlayerSheet&& playerSheet) noexcept
{
    _scoreDistrict = std::move(playerSheet._scoreDistrict);
    _stars = std::move(playerSheet._stars);
    _stones = playerSheet._stones;

    return *this;
}

bool PlayerSheet::operator==(const PlayerSheet& other) const
{
    return _stones == other._stones && _scoreDistrict == other._scoreDistrict && _stars == other._stars;
}

bool PlayerSheet::operator>(const PlayerSheet& other) const
{
    return getTotalScore() > other.getTotalScore();
}

bool PlayerSheet::operator<(const PlayerSheet& other) const
{
    return !(this>&other);
}

void PlayerSheet::swap(PlayerSheet& playerSheet) noexcept
{
    std::swap(_stones, playerSheet._stones);
    std::swap(_stars, playerSheet._stars);
    std::swap(_scoreDistrict, playerSheet._scoreDistrict);
}

QList<PlayerSheet::Color> PlayerSheet::getAllColor()
{
    QList<Color> colors;
    colors.append(Color::Blue);
    colors.append(Color::Red);
    colors.append(Color::Green);
    colors.append(Color::Yellow);
    colors.append(Color::Purple);

    return colors;
}

void PlayerSheet::setStarsNumber(PlayerSheet::Color color, unsigned int number)
{
    _stars[color] = number;
}

void PlayerSheet::setScoreDistrict(PlayerSheet::Color color, unsigned int number)
{
    _scoreDistrict[color] = number;
}

void PlayerSheet::setStones(unsigned int number)
{
    _stones = number;
}

unsigned int PlayerSheet::getScoreDistrict(PlayerSheet::Color color) const
{
    return _scoreDistrict.value(color,0);
}

unsigned int PlayerSheet::getStars(PlayerSheet::Color color) const
{
    return _stars.value(color,0);
}

unsigned int PlayerSheet::getStones() const
{
    return _stones;
}

unsigned int PlayerSheet::getTotalScore() const
{
    unsigned int score = _stones;
    for (auto color : getAllColor())
    {
        score += _stars.value(color) * _scoreDistrict.value(color);
    }
    return score;
}

void PlayerSheet::reset()
{
    setStones(0);
    for(Color color : {Color::Blue, Color::Green, Color::Purple, Color::Red, Color::Yellow})
    {
        setStarsNumber(color,0);
        setScoreDistrict(color,0);
    }
}
