#include <stdio.h>
#include <stdlib.h>

int find_max_perk(int* cartridge, int * dollars, int * recyclerewards, int * perkcost)
{
    int perk_num = 0;

    int x = (*cartridge * *perkcost - *dollars) / (*recyclerewards + *perkcost);
    *cartridge -= x;
    *dollars += x * *recyclerewards;
    
    if (*cartridge < *dollars / *perkcost)
    {
        perk_num = *cartridge;
    }
    else
    {
        perk_num = *dollars / *perkcost;
    }
    *cartridge -= perk_num;
    *dollars -= perk_num * *perkcost;

    return perk_num;
}

int main()
{
    int cartridge, dollars, recyclerewards, perkcost;
    int max_sol = 0;

    printf("Input:\n");
    printf("Cartridge:");
    scanf("%d", &cartridge);
    printf("Dollars:");
    scanf("%d", &dollars);
    printf("Recycle Rewards:");
    scanf("%d", &recyclerewards);
    printf("Perk Cost:");
    scanf("%d", &perkcost);

    max_sol = find_max_perk(&cartridge, &dollars, &recyclerewards, &perkcost);

    printf("Max Sol: %d\n", max_sol);
    printf("Cartridge left: %d\n", cartridge);
    printf("Dollars: %d\n", dollars);

    return 0;
}