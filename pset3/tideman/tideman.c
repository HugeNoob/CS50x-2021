#include <cs50.h>
#include <stdio.h>
#include <string.h>






//completed... sigh










// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    int index = -1;
    for(int i = 0; i < candidate_count; i++){
        if(strcmp(name, candidates[i]) == 0){
           index = i;
           break;
        }
    }
    
    //invalid vote
    if(index == -1){
        return false;
    }
    
    //valid vote
    ranks[rank] = index;
    return true;
    
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for(int i = 0; i < candidate_count; i++){

        for(int j = i + 1; j < candidate_count; j++){       //since ranks is sorted, +1 for preferences down the ranks
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
        for(int i = 0; i < candidate_count; i++){
            
            for(int j = i + 1; j < candidate_count; j++){
                if(preferences[i][j] - preferences[j][i] > 0){         //if i over j
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
                else if(preferences[i][j] - preferences[j][i] < 0){         //if j over i
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    pair_count++;
                }
            }
        }
        return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    //bubble sort
    pair temp;
    for(int i = 0; i < pair_count; i++){
        int min = i;
        for(int j = i + 1; j < pair_count-1; j++){
            if(preferences[pairs[min].winner][pairs[min].loser] < preferences[pairs[j].winner][pairs[j].loser]){
                temp.winner = pairs[i].winner;
                temp.loser = pairs[i].loser;
            
                pairs[i].winner = pairs[i+1].winner;
                pairs[i].loser = pairs[i+1].loser;
            
                pairs[i+1].winner = temp.winner;
                pairs[i+1].loser = temp.loser;
            }
            else if(preferences[pairs[min].winner][pairs[min].loser] > preferences[pairs[j].winner][pairs[j].loser]){
                min = j;
            }
            
        }    
    
    }
    return;
}

//checks for whether the edge to be created will form a cycle
bool isCycle(int winner, int loser)
{
    
    while(winner != -1 && winner != loser){
        bool found = false;     //is there anyone locked above you?
        
        for(int i = 0; i < candidate_count; i++){
            if(locked[i][winner]){
                winner = i;     //i is locked above winner
                found = true; 
            }
        }
        
        if(!found){             //nobody is found above, hence breaks the loop and forms edge
            winner = -1;
        }
    }
    
    
    if(winner == loser){
        return true;
    }
    
    return false;
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    
    for(int i = 0; i < pair_count; i++){
        if(!isCycle(pairs[i].winner, pairs[i].loser)){      //if the edge to be created will not form cycle, create edge
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
    
    
    
}

// Print the winner of the election
//aim: since there is no cycle, the goal is to find a candidate with nobody locked above them. no edges above = start of graph = winner
void print_winner(void)
{
    // TODO
    for(int winner = 0; winner < candidate_count; winner++){            
        bool found_winner = true;
        
        for(int loser = 0; loser < candidate_count; loser++){
            if(winner != loser && locked[loser][winner]){
                found_winner = false;
                break;
            }
        }
        
        if(found_winner){
            printf("%s\n", candidates[winner]);
            return;
        }
        
    }
    

}

