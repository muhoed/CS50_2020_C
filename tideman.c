#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char name[], int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void record(int r, int ranks[]);
void sort(int left, int right);
void merge(int left, int middle, int right);
void lock(int n, pair graph[]);
bool circle(int i, int n, pair graph[]);

int main(int argc, char *argv[])
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
    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[50];
            printf("Rank %i: ", j + 1);
            scanf("%s", name);

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
bool vote(int rank, char name[], int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(candidates[i], name))
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int r = candidate_count + 1;
    record(r, ranks);
    return;
}

// Recursive record of a given voter's preferenses
void record(int r, int ranks[])
{
    if (r == 2)
    {
        return;
    }
    r = r - 1;
    record(r, ranks);
    for (int i = candidate_count - r; i < candidate_count - 1; i++)
    {
        preferences[ranks[candidate_count - r]][ranks[i + 1]]++;
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int p = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[p].winner = i;
                pairs[p].loser = j;
                p++;
            }
        }
    }
    pair_count = p++;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int left = 0;
    int right = pair_count - 1;
    sort(left, right);
    return;
}

// Sort pairs using recursive merge sort
void sort(int left, int right)
{
    if (left == right)
    {
        return;
    }
    int middle = left + right / 2;
    // sort left part
    sort(left, middle);
    // sort right part
    sort(middle + 1, right);
    // merge sorted parts
    merge(left, middle, right);

}

// Merge sorted parts of an array
void merge(int left, int middle, int right)
{
    // create temporary variables and arrays
    int size = right - left + 1;
    pair m[size];
    int count = 0;
    pair temp[1];
    // merge two parts
    for (int i = left; i < middle + 1; i++)
    {
        for (int j = middle + 1; j < size; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                m[count].winner = pairs[j].winner;
                m[count].loser = pairs[j].loser;
                temp[0].winner = pairs[i].winner;
                temp[0].loser = pairs[i].loser;
                count++;
            }
            else
            {
                m[count].winner = pairs[i].winner;
                m[count].loser = pairs[i].loser;
                temp[0].winner = pairs[j].winner;
                temp[0].loser = pairs[j].loser;
                count++;
            }
        }
    }
    // add the remaining element
    m[count].winner = temp[0].winner;
    m[count].loser = temp[0].loser;
    // insert to pairs
    int j = 0;
    for (int i = left; i < size; i++)
    {
        pairs[i].winner = m[j].winner;
        pairs[i].loser = m[j].loser;
        j++;
    }
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int n = pair_count + 1;
    pair graph[n];
    lock(n, graph);
    return;
}

void lock(int n, pair graph[])
{
    if (n == 1)
    {
        return;
    }
    n = n - 1;
    lock(n, graph);
    for (int i = 0; i < n; i++)
    {
        if (pairs[n - 1].winner == graph[i].loser && circle(i, n, graph))
        {
            return;
        }
    }
    locked[pairs[n - 1].winner][pairs[n - 1].loser] = true;
    graph[n - 1].winner = pairs[n - 1].winner;
    graph[n - 1].loser = pairs[n - 1].loser;
    return;
}

bool circle(int i, int n, pair graph[])
{
    for (int j = 0; j < i; j++)
    {
        if (pairs[n - 1].loser == graph[j].winner)
        {
            return true;
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    bool check[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                check[i] = true;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (!check[i])
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}

