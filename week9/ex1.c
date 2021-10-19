#include <stdio.h>
#include <stdlib.h>

int main()
{
    // parse file
    int N = 1000;
    int *numbers = (int *)malloc(sizeof(int) * N);

    FILE *input = fopen("input.txt", "r");
    for (int i = 0; i < N; i++)
    {
        fscanf(input, "%d ", &numbers[i]);
    }
    int page_frames_amount;
    fscanf(stdin, "%d", &page_frames_amount);

    int *current_pages = (int *)malloc(page_frames_amount * sizeof(int));
    unsigned short *current_ages = (unsigned short *)malloc(page_frames_amount * sizeof(unsigned short));

    for (int i = 0; i < page_frames_amount; i++)
    {
        current_ages[i] = 0;
        current_pages[i] = -1;
    }

    int amount_of_hits = 0;
    int amount_of_misses = 0;

    for (int selected_page_idx = 0; selected_page_idx < N; selected_page_idx++)
    {
        // время идет, мы стареем
        for (int i = 0; i < page_frames_amount; i++)
        {
            current_ages[i] /= 2;
        }

        // check page in current pages
        int selected_page = numbers[selected_page_idx];
        int selected_page_exists = 0;
        for (int i = 0; i < page_frames_amount; i++)
        {
            if (current_pages[i] == selected_page)
                selected_page_exists = 1;
        }

        if (selected_page_exists)
        {
            amount_of_hits++;
        }
        else
        {
            int free_slot_exists = 0;
            for (int i = 0; i < page_frames_amount; i++)
            {
                if (current_pages[i] == -1)
                    free_slot_exists = 1;
            }

            if (free_slot_exists == 1)
            {
                // check free slots
                int free_slot_idx = 0;
                for (int i = 0; i < page_frames_amount; i++)
                {
                    if (current_pages[i] == -1)
                    {
                        free_slot_idx = i;
                        printf("found the slot %d\n", free_slot_idx);
                        break;
                    }
                }

                current_pages[free_slot_idx] = selected_page;
                current_ages[free_slot_idx] = 32768;
            }
            else
            {
                int minimum_age = current_pages[0];
                int minimum_age_slot = -1;
                for (int i = 0; i < page_frames_amount; i++)
                {
                    if (current_ages[i] < minimum_age)
                    {
                        minimum_age = current_ages[i];
                        minimum_age_slot = i;
                    }
                }
                current_pages[minimum_age_slot] = selected_page;
                current_ages[minimum_age_slot] = 32768;
            }
            amount_of_misses++;
        }

        printf("\n");
        for (int i = 0; i < page_frames_amount; i++)
        {
            printf("%d %d %d\n",i, current_pages[i], current_ages[i]);
        }
    }
    printf("\n\nHits: %d Misses: %d Ratio: %f\n", amount_of_hits, amount_of_misses, ((float)amount_of_hits / (float)amount_of_misses));
}