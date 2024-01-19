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
    // Construire le chemin du fichier à partir du nom du compte
    std::string filePath = "BankAccount/" + accountName + ".txt";

    // Ouvrir le fichier
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        // Si le fichier n'est pas trouvé, lancer une exception
        throw std::runtime_error("File not found: " + filePath);
    }

    float balance = 0.0f;
    std::string line;

    // Lire chaque ligne du fichier
    while (std::getline(file, line))
    {
        // Utiliser un flux de chaînes pour extraire l'opération (+ ou -) et le montant
        std::istringstream iss(line);
        char operation;
        float amount;

        // Essayer d'extraire l'opération et le montant
        if (iss >> operation >> amount)
        {
            // Mettre à jour le solde en fonction de l'opération
            if (operation == '+')
            {
                balance += amount;
            }
            else if (operation == '-')
            {
                balance -= amount;
            }
            else
            {
                // Si l'opération n'est ni + ni -, lancer une exception
                file.close();
                throw std::runtime_error("Invalid operation in file: " + filePath);
            }
        }
        else
        {
            // Si la ligne ne contient pas correctement une opération et un montant, lancer une exception
            file.close();
            throw std::runtime_error("Invalid line format in file: " + filePath);
        }
    }

    // Fermer le fichier après lecture
    file.close();

    // Retourner le solde calculé
    return balance;
}

#endif
