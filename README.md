# Cryptage_Decryptage

Pour cette partie nous avons choisi de crypter des textes en français (sans les caractères accentués pour des raison d’affichage via QT). 
L’utilisateur pourra entrer son texte, puis crypter celui-ci. Une fois son texte crypté, apparaît le texte codé selon le code de Huffman.

Pour réaliser cela, nous avons défini une nouvelle classe nommée « Occurrence » ; cette classe permettra de contenir les caractères et leur fréquence associée.
A partir de cette classe nous allons construire au fur et à mesure un arbre binaire de cryptage. Et cela se fera avec l’algorithme de Huffman.

Enfin l’interface sera très complète, elle permettra à l’utilisateur de voir son texte entré, le texte codé correspondant et d’autres informations.
