#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "lexer.h"
#include "parser.h"
#include "da.h"

int main(int argc, char* argv[])
{
     // Check if the file name is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Load the file content
    char *input_buffer = loadFile(argv[1]);
    if (input_buffer == NULL) {
        return 1;
    }
    puts(input_buffer);


    Token *tokens = tokenize(input_buffer);
    showTokens(tokens);

    // domain analysis
    pushDomain(); // creaza domeniul global in tabela de simboluri

    // sintactic analyzer
    parse(tokens);

    // afisare domeniu
    showDomain(symTable); // afisare domeniu
    dropDomain(); // sterge domeniul global

    free(input_buffer);



    return 0;
}