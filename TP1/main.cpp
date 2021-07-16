/**
* Programme cryptage TP1
* But : Permet de crypter un message et de le décrypter
* Author : Romain
* Date : 15/11/2019
**/

#include <iostream>
#include <string>

using namespace std;

int main()
{
// Déclaration
string message, msgcryp, cle;
unsigned int milieu;
char decalage = '-';

// Saisie de la clé de cryptage
cout << "Saisir la cl\x82 de cryptage : ";
cin >> cle;

// Saisie du message à crypter
cout << "Entrez un message : ";
cin >> message;

// Découpage en 2 du message et inversion
milieu = (message.size() / 2);
message = message.substr (milieu, message.size()- milieu) + message.substr(0, milieu);

// Echange des caractères du message avec la clé
msgcryp = "";
    for (unsigned int k = 0; k < message.size(); k++)
    {
        // ou exclusif entre le keme caractère du message et de la clé
        msgcryp += (message[k] ^ cle[k%cle.size()]) + decalage;
    }
    // Affichage message crypté
    cout << "Message crypt\x82 : " << msgcryp;
// Décryptage
message = "";
    for (unsigned int k = 0; k < msgcryp.size(); k++)
    {
        // ou exclusif entre le keme caractère du message crypté et de la clé
        message += ((msgcryp[k] - decalage) ^ cle[k%cle.size()]);
    }
    // Découpage en 2 du message et inversion
    // Si la longueur du message est impair
    if (message.size()%2 != 0)
    {
        milieu++;
    }
message = message.substr(milieu, message.size() - milieu) + message.substr(0, milieu);

// Affichage du message décrypté
cout << endl << "Message d'origine : " << message;
return 0;
}
