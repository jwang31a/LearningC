#include <stdio.h>

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = {
    {"Afghanistan", 93},
    {"Algeria", 213},
    {"Angola", 244},
    {"Argentina", 54},
    {"Australia", 61},
    {"Austria", 43},
    {"Bangladesh", 880},
    {"Belgium", 32},
    {"Brazil", 55},
    {"Canada", 1},
    {"China", 86},
    {"Colombia", 57},
    {"Congo, Dem. Rep. of", 243},
    {"Congo, Rep. of", 242},
    {"Egypt", 20},
    {"Ethiopia", 251},
    {"France", 33},
    {"Germany", 49},
    {"Ghana", 233},
    {"India", 91},
    {"Indonesia", 62}, 
    {"Iran", 98},
    {"Iraq", 964}, 
    {"Italy", 39}, 
    {"Japan", 81}, 
    {"Kenya", 254}, 
    {"Mexico", 52}, 
    {"Morocco", 212},
    {"Argentina", 54},
    {"Bangladesh", 880},
    {"Brazil", 55},
    {"Burma (Myanmar)", 95},
    {"China", 86},
    {"Colombia", 57},
    {"Congo, Dem. Rep. of", 243},
    {"Egypt", 20},
    {"Ethiopia", 251},
    {"France", 33},
    {"Germany", 49},
    {"India", 91},
    {"Indonesia", 62}, 
    {"Iran", 98},
    {"Italy", 39}, 
    {"Japan", 81},
    {"Mexico", 52}, 
    {"Nigeria", 234},
    {"Pakistan", 92}, 
    {"Philippines", 63},
    {"Poland", 48}, 
    {"Russia", 7},
    {"South Africa", 27}, 
    {"South Korea", 82},
    {"Spain", 34}, 
    {"Sudan", 249},
    {"Thailand", 66}, 
    {"Turkey", 90},
    {"Ukraine", 380}, 
    {"United Kingdom", 44},
    {"United States", 1}, 
    {"Vietnam", 84}
};

int main(void) {
    int code;
    printf("Look up international dialing code: ");
    scanf("%d", &code);
    for (int i = 0; i < sizeof(country_codes) / sizeof(country_codes[0]); i++) {
        if (country_codes[i].code == code) {
            puts(country_codes[i].country);
            return 0;
        }
    }
    printf("Error: Invalid dialing code entered.\n");
    return 0;
}