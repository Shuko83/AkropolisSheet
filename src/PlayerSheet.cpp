#include "PlayerSheet.h"

PlayerSheet::PlayerSheet(QObject * parent)
    :  QObject(parent)
{
}

QString PlayerSheet::getColorAsString(Color color)
{
    QString val;
    switch (color)
    {
    case PlayerSheet::Color::Red:
        val = tr("Red");
        break;
    case PlayerSheet::Color::Blue:
        val = tr("Blue");
        break;
    case PlayerSheet::Color::Purple:
        val = tr("Purple");
        break;
    case PlayerSheet::Color::Yellow:
        val = tr("Yellow");
        break;
    case PlayerSheet::Color::Green:
        val = tr("Green");
        break;
    default:
        break;
    }
    return val;
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

void PlayerSheet::setPlaceNumber(PlayerSheet::Color color, int number)
{
    if(_places.value(color,0) != number)
    {
        _places[color] = number;
        emit placeNumberChanged(color,number);
    }
}

void PlayerSheet::setScoreDistrict(PlayerSheet::Color color, int number)
{
    if(_scoreDistrict.value(color,0) != number)
    {
        _scoreDistrict[color] = number;
        emit scoreDistrictChanged(color, number);
    }
}

void PlayerSheet::setStones(int number)
{
    if(_stones != number)
    {
        _stones = number;
        emit stonesChanged();
    }
}

int PlayerSheet::getScoreDistrict(PlayerSheet::Color color) const
{
    return _scoreDistrict.value(color,0);
}

int PlayerSheet::getPlaceNumber(PlayerSheet::Color color) const
{
    return _places.value(color,0);
}

int PlayerSheet::getStones() const
{
    return _stones;
}

void PlayerSheet::reset()
{
    setStones(0);
    for(Color color : {Color::Blue, Color::Green, Color::Purple, Color::Red, Color::Yellow})
    {
        setPlaceNumber(color,0);
        setScoreDistrict(color,0);
    }
}
