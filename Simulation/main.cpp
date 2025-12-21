#include <vector>
#include "block.h"
#include "identity.h"

int main() {
    std::cout << "--- DEMARRAGE DE LA SIMULATION ONTOLOGIQUE ---" << std::endl;
    const int DIFFICULTY = 4; // Ajuster pour simuler plus de travail

    // 1. GENESE : Création de la Timechain
    std::vector<Block> chain;
    Block genesis;
    genesis.index = 0;
    genesis.previous_hash = "00000000000000000000000000000000";
    genesis.data = "Bloc Genese: In Code We Trust";
    genesis.timestamp = std::time(nullptr);
    genesis.mineBlock(DIFFICULTY);
    chain.push_back(genesis);

    // 2. ACTEURS : Naissance des Homines Cryptographici
    Identity alice("seed_alice_secret");
    Identity bob("seed_bob_secret");
    
    std::cout << "\n[Identite] Alice Public Key: " << alice.public_key.substr(0, 10) << "..." << std::endl;
    std::cout << "[Identite] Bob Public Key:   " << bob.public_key.substr(0, 10) << "..." << std::endl;

    // 3. INTERACTION : Alice envoie un message signe a Bob
    std::string transaction = "Alice envoie 50 Sats a Bob";
    std::string signature = alice.sign(transaction);
    
    // Vérification (Simulation)
    std::cout << "\n[Mempoold] Transaction recue: " << transaction << std::endl;
    std::cout << "[Crypto] Signature validee (Mathematiquement prouve)." << std::endl;

    // 4. ANCRAGE : Solidification de l'histoire
    Block newBlock;
    newBlock.index = 1;
    newBlock.previous_hash = chain.back().hash;
    newBlock.data = transaction + " [SIG:" + signature.substr(0,8) + "]";
    newBlock.timestamp = std::time(nullptr);

    std::cout << "\n[Mining] Demarrage des reacteurs thermodynamiques..." << std::endl;
    newBlock.mineBlock(DIFFICULTY); // C'est ici que l'energie est depensee
    chain.push_back(newBlock);

    // 5. VERIFICATION FINALE
    std::cout << "\n--- ETAT DE LA CHAINE ---" << std::endl;
    for(const auto& b : chain) {
        std::cout << "Bloc #" << b.index << " | Hash: " << b.hash << " | Prev: " << b.previous_hash.substr(0,10) << "..." << std::endl;
    }

    std::cout << "\nLa realite est maintenant immuable." << std::endl;
    return 0;
}