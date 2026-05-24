#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");
    if (fp == NULL) return;
    
    char line[128];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "Options=%d", &config_ptr->Options);
        sscanf(line, "InputFileName=%s", config_ptr->InputFileName);
        sscanf(line, "SectionName=%s", config_ptr->SectionName);
        sscanf(line, "Address=%lli", &config_ptr->Address); 
    }
    
    fclose(fp);
}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

