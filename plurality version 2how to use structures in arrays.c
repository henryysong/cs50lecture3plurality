#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        //I wanted to do argv[i], but "name" will cover everyone in the set of ARRAYS
        if (strcmp(candidates[i].name, name) == 0)
        {
            //Add 1 anytime the name is recalled for the vote
            candidates[i].votes = candidates[i].votes + 1;
            // Tested using this code w success:
            // printf("Test: %d\n", candidates[i].votes);
        }

    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    //We want j to go through each integer individually and identify
    //the largest values
    for ( int j = 0; j < candidate_count; j++)
    {
        //check each value of the array, when [j] is bigger than [0], [0] is now [highest value]
        if (candidates[0].votes < candidates[j].votes)
        {
            //1. When it finds a higher integer, [0] is now replaced by the highest integer
            //2. Replace the name of [0] from the 1st person to the corresponding array
            candidates[0].votes = candidates[j].votes;
            candidates[0].name = candidates[j].name;
        }
        for (int k = j + 1; k < candidate_count; k++)
        {
            if (candidates[1].votes == candidates[0].votes)
            {
                printf("Tie votes: %i %s\n", candidates[1].votes, candidates[1].name);
            }
        }
    }
    //SUCCESS for 1st winner! printf("Largest # of votes: %i %s\n", candidates[0].votes, candidates[0].name);
    //PROBLEM: I can't create multiple winners :(
    printf("Largest # of votes: %i %s\n", candidates[0].votes, candidates[0].name);

    return;
}