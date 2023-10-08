#ifndef PLAYERSHEET_H
#define PLAYERSHEET_H

#include <QHash>
#include <QObject>

class QString;

/// <summary>
/// Cette classe représente une feuille de score Akropolis attribué à un joueur.
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
    /// Constructeur par déplacement.
    /// </summary>
    /// <param name="playerSheet"></param>
    /// <returns></returns>
    PlayerSheet& operator= (PlayerSheet&& playerSheet) noexcept;
    /// <summary>
    /// Cette méthode permet de comparer le score total d'une feuille de score à la feuille de score courante pour savoir si il sont égaux.
    /// </summary>
    /// <param name="other">L'aurtre feuille de score.</param>
    /// <returns>Return vrai si la valeur du score total est égal au score total de l'autre feuille de score @other. Return faux sinon.</returns>
    bool operator== (const PlayerSheet& other) const;
    /// <summary>

    /// Cette méthode permet de comparer le score total d'une feuille de score à la feuille de score courante pour savoir si il est supérieur.
    /// </summary>
    /// <param name="other">L'aurtre feuille de score.</param>
    /// <returns>Vrai si le score total de la feuille de score est supérieur au score total de l'autre feuille @other. Return faux sinon.</returns>
    bool operator> (const PlayerSheet& other) const;
    /// <summary>
    /// Cette méthode permet de comparer le score total d'une feuille de score à la feuille de score courante pour savoir si il est inférieur.
    /// </summary>
    /// <param name="other">L'aurtre feuille de score.</param>
    /// <returns>Vrai si le score total de la feuille de score est inférieur au score total de l'autre feuille @other. Return faux sinon.</returns>
    bool operator< (const PlayerSheet& other) const;

    /// <summary>
    /// Cette méthode permet d'échanger le contenu entre 2 feuille de score.
    /// </summary>
    /// <param name="playerSheet"></param>
    void swap(PlayerSheet& playerSheet) noexcept;

    /// <summary>
    /// Cette méthode permet d'accéder à la liste des couleurs défini dans une feuille de score.
    /// </summary>
    /// <returns>La liste de toutes les couleurs qui existent dans la feuille de score.</returns>
    static QList<Color> getAllColor();

    /// <summary>
    /// Cette méthode permet de modifier le nombre d'étoiles sauvegardé pour une couleur.
    /// </summary>
    /// <param name="color">Représente la catégorie de la couleur à modifier.</param>
    /// <param name="number">Représente le nombre d'étoile à sauvegarder.</param>
    void setStarsNumber(Color color, unsigned int number);
    /// <summary>
    /// Cette méthode permet de modifier le score de quartier sauvegardé pour une couleur.
    /// </summary>
    /// <param name="color">Représente la catégorie de la couleur à modifier.</param>
    /// <param name="number">Représente le score de quartier à sauvegarder.</param>
    void setScoreDistrict(Color color, unsigned int number);
    /// <summary>
    /// Cette méthode permet de modifier le nombre de caillou sauvegarder.
    /// </summary>
    /// <param name="number">Le nouveau nombre de caillou à sauvegarder.</param>
    void setStones(unsigned int number);

    /// <summary>
    /// Cette méthode retourne le score d'une couleur.
    /// </summary>
    /// <param name="color">La couleur.</param>
    /// <returns>Le score pour la couleur @color</returns>
    unsigned int getScoreDistrict(Color color) const;
    /// <summary>
    /// Cette méthode retourne le nombre d'étoiles pour une couleur.
    /// </summary>
    /// <param name="color">La couleur.</param>
    /// <returns>Le nombre d'étoile pour la couleur @color</returns>
    unsigned int getStars(Color color) const;
    /// <summary>
    /// 
    /// </summary>
    /// <returns>Le nombre de caillou en mémoire.</returns>
    unsigned int getStones() const;

    /// <summary>
    /// Cette méthode calcul le score total défini le score total obtenu par le joueur au vu des donnée sauvegardés.
    /// </summary>
    /// <returns>Le score total de la feuille.</returns>
    unsigned int getTotalScore() const;

    /// <summary>
    /// Cette méthode permet de réinitialiser la feuille. Le nombre d'étoiles, de cailloux et de point de districte sont remis à zéro.
    /// </summary>
    void reset();

private:
    QHash<Color, unsigned int> _stars;
    QHash<Color, unsigned int> _scoreDistrict;
    unsigned int _stones = 0;

};

#endif // PLAYERSHEET_H
