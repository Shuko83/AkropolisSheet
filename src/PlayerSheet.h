#ifndef PLAYERSHEET_H
#define PLAYERSHEET_H

#include <QHash>
#include <QObject>

class QString;

/// <summary>
/// Cette classe repr�sente une feuille de score Akropolis attribu� � un joueur.
/// </summary>
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
    ~PlayerSheet() = default;

    /// <summary>
    /// Constucteur d'affectation.
    /// </summary>
    /// <param name="playerSheet"></param>
    /// <returns></returns>
    PlayerSheet& operator= (const PlayerSheet& playerSheet);
    /// <summary>
    /// Constructeur par d�placement.
    /// </summary>
    /// <param name="playerSheet"></param>
    /// <returns></returns>
    PlayerSheet& operator= (PlayerSheet&& playerSheet) noexcept;
    /// <summary>
    /// Cette m�thode permet de comparer le score total d'une feuille de score � la feuille de score courante pour savoir si il sont �gaux.
    /// </summary>
    /// <param name="other">L'aurtre feuille de score.</param>
    /// <returns>Return vrai si la valeur du score total est �gal au score total de l'autre feuille de score @other. Return faux sinon.</returns>
    bool operator== (const PlayerSheet& other) const;
    /// <summary>

    /// Cette m�thode permet de comparer le score total d'une feuille de score � la feuille de score courante pour savoir si il est sup�rieur.
    /// </summary>
    /// <param name="other">L'aurtre feuille de score.</param>
    /// <returns>Vrai si le score total de la feuille de score est sup�rieur au score total de l'autre feuille @other. Return faux sinon.</returns>
    bool operator> (const PlayerSheet& other) const;
    /// <summary>
    /// Cette m�thode permet de comparer le score total d'une feuille de score � la feuille de score courante pour savoir si il est inf�rieur.
    /// </summary>
    /// <param name="other">L'aurtre feuille de score.</param>
    /// <returns>Vrai si le score total de la feuille de score est inf�rieur au score total de l'autre feuille @other. Return faux sinon.</returns>
    bool operator< (const PlayerSheet& other) const;

    /// <summary>
    /// Cette m�thode permet d'�changer le contenu entre 2 feuille de score.
    /// </summary>
    /// <param name="playerSheet"></param>
    void swap(PlayerSheet& playerSheet) noexcept;

    /// <summary>
    /// Cette m�thode permet d'acc�der � la liste des couleurs d�fini dans une feuille de score.
    /// </summary>
    /// <returns>La liste de toutes les couleurs qui existent dans la feuille de score.</returns>
    static QList<Color> getAllColor();

    /// <summary>
    /// Cette m�thode permet de modifier le nombre d'�toiles sauvegard� pour une couleur.
    /// </summary>
    /// <param name="color">Repr�sente la cat�gorie de la couleur � modifier.</param>
    /// <param name="number">Repr�sente le nombre d'�toile � sauvegarder.</param>
    void setStarsNumber(Color color, unsigned int number);
    /// <summary>
    /// Cette m�thode permet de modifier le score de quartier sauvegard� pour une couleur.
    /// </summary>
    /// <param name="color">Repr�sente la cat�gorie de la couleur � modifier.</param>
    /// <param name="number">Repr�sente le score de quartier � sauvegarder.</param>
    void setScoreDistrict(Color color, unsigned int number);
    /// <summary>
    /// Cette m�thode permet de modifier le nombre de caillou sauvegarder.
    /// </summary>
    /// <param name="number">Le nouveau nombre de caillou � sauvegarder.</param>
    void setStones(unsigned int number);

    /// <summary>
    /// Cette m�thode retourne le score d'une couleur.
    /// </summary>
    /// <param name="color">La couleur.</param>
    /// <returns>Le score pour la couleur @color</returns>
    unsigned int getScoreDistrict(Color color) const;
    /// <summary>
    /// Cette m�thode retourne le nombre d'�toiles pour une couleur.
    /// </summary>
    /// <param name="color">La couleur.</param>
    /// <returns>Le nombre d'�toile pour la couleur @color</returns>
    unsigned int getStars(Color color) const;
    /// <summary>
    /// 
    /// </summary>
    /// <returns>Le nombre de caillou en m�moire.</returns>
    unsigned int getStones() const;

    /// <summary>
    /// Cette m�thode calcul le score total d�fini le score total obtenu par le joueur au vu des donn�e sauvegard�s.
    /// </summary>
    /// <returns>Le score total de la feuille.</returns>
    unsigned int getTotalScore() const;

    /// <summary>
    /// Cette m�thode permet de r�initialiser la feuille. Le nombre d'�toiles, de cailloux et de point de districte sont remis � z�ro.
    /// </summary>
    void reset();

private:
    QHash<Color, unsigned int> _stars;
    QHash<Color, unsigned int> _scoreDistrict;
    unsigned int _stones = 0;

};

#endif // PLAYERSHEET_H
