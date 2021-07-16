/**
* Programme cryptage TP1
* But : Permet de crypter un message et de le d�crypter
* Author : Romain
* Date : 15/11/2019
**/

#include <iostream>
#include <string>

using namespace std;

int main()
{
// D�claration
string message, msgcryp, cle;
unsigned int milieu;
char decalage = '-';

// Saisie de la cl� de cryptage
cout << "Saisir la cl\x82 de cryptage : ";
cin >> cle;

// Saisie du message � crypter
cout << "Entrez un message : ";
cin >> message;

// D�coupage en 2 du message et inversion
milieu = (message.size() / 2);
message = message.substr (milieu, message.size()- milieu) + message.substr(0, milieu);

// Echange des caract�res du message avec la cl�
msgcryp = "";
    for (unsigned int k = 0; k < message.size(); k++)
    {
        // ou exclusif entre le keme caract�re du message et de la cl�
        msgcryp += (message[k] ^ cle[k%cle.size()]) + decalage;
    }
    // Affichage message crypt�
    cout << "Message crypt\x82 : " << msgcryp;
// D�cryptage
message = "";
    for (unsigned int k = 0; k < msgcryp.size(); k++)
    {
        // ou exclusif entre le keme caract�re du message crypt� et de la cl�
        message += ((msgcryp[k] - decalage) ^ cle[k%cle.size()]);
    }
    // D�coupage en 2 du message et inversion
    // Si la longueur du message est impair
    if (message.size()%2 != 0)
    {
        milieu++;
    }
message = message.substr(milieu, message.size() - milieu) + message.substr(0, milieu);

// Affichage du message d�crypt�
cout << endl << "Message d'origine : " << message;
return 0;
}
