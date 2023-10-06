#ifndef PLAYERSHEET_H
#define PLAYERSHEET_H

#include <QHash>
#include <QObject>

class QString;

class PlayerSheet : public QObject
{
    Q_OBJECT
public:
    enum class Color
    {
        Red,
        Blue,
        Purple,
        Yellow,
        Green,
    }; 
    explicit PlayerSheet(QObject* parent = nullptr);

    static QString getColorAsString(Color color);
    static QList<Color> getAllColor();

    void setPlaceNumber(Color color, int number);
    void setScoreDistrict(Color color, int number);
    void setStones(int number);

    int getScoreDistrict(Color color) const;
    int getPlaceNumber(Color color) const;
    int getStones() const;

    void reset();
signals:
    void stonesChanged();
    void placeNumberChanged(Color color, int number);
    void scoreDistrictChanged(Color color, int number);

private:
    QHash<Color,int> _places;
    QHash<Color,int> _scoreDistrict;
    int _stones = 0;
};

#endif // PLAYERSHEET_H
