#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100

struct node {
    long long sap_id;
    int vote;
    struct node* link;
} *head = NULL;

long long allowed_sap_ids[MAX_VOTERS];
int allowed_count = 0;

/* Check valid 10-digit SAP ID */
int is_valid_sap_id(long long sap)
{
    return (sap >= 1000000000LL && sap <= 9999999999LL);
}

/* Check if SAP ID is in allowed list */
int is_allowed(long long sap)
{
    for (int i = 0; i < allowed_count; i++)
    {
        if (allowed_sap_ids[i] == sap)
            return 1;
    }
    return 0;
}

/* Check if already voted */
int has_voted(long long sap)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        if (temp->sap_id == sap)
            return 1;
        temp = temp->link;
    }
    return 0;
}

/* Store vote */
void vote(long long sap, int party_vote)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->sap_id = sap;
    new_node->vote = party_vote;
    new_node->link = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node* temp = head;
        while (temp->link != NULL)
            temp = temp->link;

        temp->link = new_node;
    }
}

/* Count votes for a party */
int count_votes(int party)
{
    int count = 0;
    struct node* temp = head;

    while (temp != NULL)
    {
        if (temp->vote == party)
            count++;

        temp = temp->link;
    }
    return count;
}

/* Find winner */
int max_repeat()
{
    int votes1 = count_votes(1);
    int votes2 = count_votes(2);

    if (votes1 > votes2)
        return 1;
    else if (votes2 > votes1)
        return 2;
    else
        return 0;
}

/* Free linked list memory */
void free_memory()
{
    struct node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main()
{
    printf("=== Voting Access Setup ===\n");

    printf("Enter number of eligible voters (max %d): ", MAX_VOTERS);
    scanf("%d", &allowed_count);

    if (allowed_count > MAX_VOTERS)
    {
        printf("Too many voters. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < allowed_count; i++)
    {
        printf("Enter 10-digit SAP ID for voter %d: ", i + 1);
        scanf("%lld", &allowed_sap_ids[i]);

        if (!is_valid_sap_id(allowed_sap_ids[i]))
        {
            printf("Invalid SAP ID. Must be 10 digits.\n");
            i--;
        }
    }

    system("cls");

    printf("\n=== Voting Starts ===\n");

    while (1)
    {
        long long sap_id;
        int vote_choice;

        printf("\nEnter your SAP ID (0 to end voting): ");
        scanf("%lld", &sap_id);

        if (sap_id == 0)
            break;

        if (!is_valid_sap_id(sap_id))
        {
            printf("Error: SAP ID must be a 10-digit number.\n");
            continue;
        }

        if (!is_allowed(sap_id))
        {
            printf("Error: This SAP ID is not in the allowed list.\n");
            continue;
        }

        if (has_voted(sap_id))
        {
            printf("Error: This SAP ID has already voted.\n");
            continue;
        }

        printf("Select the party to vote for:\n");
        printf("1. Party_1\n");
        printf("2. Party_2\n");
        printf("Enter your choice: ");
        scanf("%d", &vote_choice);

        if (vote_choice != 1 && vote_choice != 2)
        {
            printf("Invalid party choice. Try again.\n");
            continue;
        }

        vote(sap_id, vote_choice);

        printf("Your vote has been recorded. Thank you!\n");

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    int result = max_repeat();

    printf("\nFinal Vote Tally:\n");
    printf("Party_1: %d votes\n", count_votes(1));
    printf("Party_2: %d votes\n", count_votes(2));

    if (result == 1)
        printf("\nParty_1 has obtained the maximum votes.\n");
    else if (result == 2)
        printf("\nParty_2 has obtained the maximum votes.\n");
    else
        printf("\nThe election ended in a tie!\n");

    free_memory();

    return 0;
}
