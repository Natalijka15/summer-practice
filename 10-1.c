#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct country {
  char name[45];
  char official_language[45];
  float area;
  float population;
  char currency[5];
  char capital[45];
} TCountry;

void printCountry(TCountry country) {
  printf("Country: %s\n", country.name);
  printf("Official language: %s\n", country.official_language);
  printf("Area: %.2f\n", country.area);
  printf("Population: %.2f\n", country.population);
  printf("Currency: %s\n", country.currency);
  printf("Capital: %s\n", country.capital);
}

int main(int argc, char *argv[]) {
  TCountry *countries;
  int n = 1, i;
  float max_population;
  int count, id_country;

  countries = malloc(n * (sizeof *countries));
  if (!countries) return 1;

  setlocale(LC_ALL, 0);
  i = 0;
  do {
    printf("Enter info or press 'enter' to end....\n\n");
    printf("Name: ");
    fflush(stdin);
    gets(countries[i].name);
    if (strcmp(countries[i].name, "") == 0) {
      n--;
      if (n == 0) return 1;
      countries = realloc(countries, n * (sizeof *countries));
      if (!countries) return 1;
      break;
    }

    printf("Official Language: ");
    fflush(stdin);
    gets(countries[i].official_language);
    
    printf("Area: ");
    scanf("%f", &countries[i].area);

    printf("Population: ");
    scanf("%f", &countries[i].population);

    printf("Currency: ");
    fflush(stdin);
    scanf("%s", countries[i].currency);

    printf("Capital: ");
    fflush(stdin);
    gets(countries[i].capital);

    n++; i++;
    countries = realloc(countries, n * (sizeof *countries));
    if (!countries) return 1;
  } while (1);
  
  count = 0;
  max_population = countries[0].population;
  id_country = 0;
  for (i = 0; i < n; i++) {
    if (max_population < countries[i].population) {
      max_population = countries[i].population;
      id_country = i;
    }
    if (strcmp(countries[i].official_language, "English") == 0) count++;
    printCountry(countries[i]);
  }

  printf("\nMax population:\n");
  printCountry(countries[id_country]);
  printf("\nEnglish countries - %d\n", count);

  system("pause");
  return 0;
}