#ifndef BLOCK_H
#define BLOCK_H

#include <ctime>
#include <iostream>
#include "crypto.h"

struct Block {
    int index;
    std::string previous_hash;
    std::string data;
    long timestamp;
    int nonce;       // Le nombre aléatoire cherché
    std::string hash;

    // Calculer l'empreinte du bloc
    std::string calculateHash() const {
        return sha256(std::to_string(index) + previous_hash + 
                      data + std::to_string(timestamp) + std::to_string(nonce));
    }

    // Le Minage : Convertir des Joules en Vérité
    // difficulty : nombre de zéros requis au début du hash
    void mineBlock(int difficulty) {
        std::string target(difficulty, '0'); // Ex: "0000"
        
        // Boucle thermodynamique
        while (hash.substr(0, difficulty) != target) {
            nonce++;
            hash = calculateHash();
        }
        std::cout << ">> BLOC MINE : " << hash << " (Nonce: " << nonce << ")" << std::endl;
    }
};

#endif