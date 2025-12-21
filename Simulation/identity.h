#ifndef IDENTITY_H
#define IDENTITY_H

#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <iostream>
#include "crypto.h"

class Identity {
private:
    // La conscience (Secret) - NE JAMAIS PARTAGER
    // Dans une vraie implémentation, utiliser EC_KEY (secp256k1)
    std::string private_key_sim; 

public:
    std::string public_key; // Le visage (Public)

    Identity(std::string seed) {
        // Simulation d'une génération de clés déterministe
        private_key_sim = sha256(seed + "_private");
        public_key = sha256(private_key_sim + "_public_derivation");
    }

    // "Je pense donc je signe"
    std::string sign(std::string message) {
        // Signature simplifiée : Hash(Message + CléPrivée)
        return sha256(message + private_key_sim);
    }
};

#endif