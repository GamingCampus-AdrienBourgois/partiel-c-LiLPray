// Solution2.cpp

#include "Solution2.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// Don't forget to enable the exercise in the StudentConfiguration.h file!
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

float Solution2::GetBalance(const std::string& accountName)
{
    // Construire le chemin du fichier � partir du nom du compte
    std::string filePath = "BankAccount/" + accountName + ".txt";

    // Ouvrir le fichier
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        // Si le fichier n'est pas trouv�, lancer une exception
        throw std::runtime_error("File not found: " + filePath);
    }

    float balance = 0.0f;
    std::string line;

    // Lire chaque ligne du fichier
    while (std::getline(file, line))
    {
        // Utiliser un flux de cha�nes pour extraire l'op�ration (WITHDRAW ou DEPOSIT) et le montant
        std::istringstream iss(line);
        std::string operation;
        float amount;

        if (iss >> operation >> amount)
        {
            // Mettre � jour le solde en fonction de l'op�ration
            if (operation == "DEPOSIT")
            {
                balance += amount;
            }
            else if (operation == "WITHDRAW")
            {
                balance -= amount;
            }
            else
            {
                // Si l'op�ration n'est ni DEPOSIT ni WITHDRAW, lancer une exception
                throw std::runtime_error("Invalid operation in file: " + filePath);
            }
        }
        else
        {
            // Si la ligne ne contient pas correctement une op�ration et un montant, lancer une exception
            throw std::runtime_error("Invalid line format in file: " + filePath);
        }
    }

    // Fermer le fichier apr�s lecture
    file.close();

    // Retourner le solde calcul�
    return balance;
}

#endif
