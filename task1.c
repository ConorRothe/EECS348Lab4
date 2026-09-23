/*
 * EECS 348 Lab 4
 * Task 1 - Football Score Possibilities
 * Author: Conor Rothe
 *
 * This program takes an NFL score from the user and displays
 * every possible combination of scoring plays that can produce
 * that score. The program stops when the user enters 1.
 */

#include <stdio.h>

int main()
{
    // Stores the NFL score entered by the user
    int score;

    // Variables representing the number of each type of scoring play
    int td2;       // Touchdown + 2 point conversion = 8 points
    int td1;       // Touchdown + 1 point field goal = 7 points
    int td;        // Touchdown = 6 points
    int fg;        // Field goal = 3 points
    int safety;    // Safety = 2 points

    // Keep asking the user for scores until they enter 1
    while (1)
    {
        // Ask the user to enter an NFL score
        printf("Enter the NFL score (Enter 1 to stop): ");

        // Read the score from the user
        if (scanf("%d", &score) != 1)
        {
            // Tell the user if they entered something other than an integer
            printf("Invalid input. Please enter an integer.\n");

            // Clear the invalid input from the input buffer
            while (getchar() != '\n');

            // Go back to the beginning of the loop
            continue;
        }

        // Stop the program if the user enters 1
        if (score == 1)
        {
            break;
        }

        // Negative NFL scores are not valid
        if (score < 0)
        {
            printf("Invalid score. Please enter a non-negative score.\n");
            continue;
        }

        // Display a heading before printing the combinations
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Try every possible number of 8-point touchdowns
        for (td2 = 0; td2 <= score / 8; td2++)
        {
            // Try every possible number of 7-point touchdowns
            for (td1 = 0; td1 <= score / 7; td1++)
            {
                // Try every possible number of 6-point touchdowns
                for (td = 0; td <= score / 6; td++)
                {
                    // Try every possible number of field goals
                    for (fg = 0; fg <= score / 3; fg++)
                    {
                        // Try every possible number of safeties
                        for (safety = 0; safety <= score / 2; safety++)
                        {
                            // Check if this combination adds up to the entered score
                            if ((td2 * 8) + (td1 * 7) + (td * 6) +
                                (fg * 3) + (safety * 2) == score)
                            {
                                // Print the valid combination
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    // End the program successfully
    return 0;
}