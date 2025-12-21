# Détection du chemin d'OpenSSL via Homebrew
OPENSSL_DIR = $(shell brew --prefix openssl@3)

# Drapeaux de compilation (Où sont les fichiers .h ?)
CXXFLAGS = -I$(OPENSSL_DIR)/include -std=c++17

# Drapeaux de l'éditeur de liens (Où sont les fichiers .dylib ?)
LDFLAGS = -L$(OPENSSL_DIR)/lib -lssl -lcrypto

all:
	clang++ main.cpp -v -o simulation \
	-I/Library/Developer/CommandLineTools/SDKs/MacOSX15.2.sdk/usr/include/c++/v1 \
	$(CXXFLAGS) $(LDFLAGS)

run: all
	./simulation

clean:
	rm -f simulation