// *************************
// Title: Lab 10 - ECE 264
// Author: Nick Brenner
// *************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

enum Suit {SPADES, DIAMONDS, HEARTS, CLUBS};

struct Card
{
    enum Rank rank;
    enum Suit suit;
};

struct Card *createCards(int deckCount);

void shuffleCards(struct Card *cards, int deckCount);

int printfCards(struct Card *card, int deckCount);

int main()
{
    struct Card *cards;
    cards = createCards(1);  // Call function to get an array of cards 
    printfCards(cards, 1);  // Call function to print cards
    shuffleCards(cards, 1);   // Shuffle the cards

    printf("Shuffled deck:\n");
    printfCards(cards, 1);  // Print the deck after the shuffle
    
    
    free(cards);  // Free the allocated memory
}

struct Card* createCards(int deckCount)
{
    struct Card* cards = malloc(deckCount * 52 * sizeof(struct Card));  // Allocate space for the array
    const enum Rank rankArray[] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    const enum Suit suitArray[] = {SPADES, DIAMONDS, HEARTS, CLUBS};
    int numCards = deckCount*52;  // Get the number of cards
    int j=0;
    int k=1;

    for (int i=0; i<numCards; i++) // For each card, assign a rank and suit
    {
        cards[i].rank = rankArray[k];
        cards[i].suit = suitArray[j];
        j++;
        k++;

        if (j>3)  // To cycle through the 4 suits, j must be reset to 0 after 3
        {
            j=0;
        }
        if (k>13)  // To cycle through the 13 ranks, k must be reset to 1 after 13
        {
            k=1;
        }
    }

    return cards;
}

int printfCards(struct Card *cards, int deckCount)
{
    int numCards = deckCount*52;
    
    for (int i=0; i<numCards; i++)
    {
        switch(cards[i].rank)  // Switch statement to print the correct card title for each card based on the rank
        {
            case 1:
                printf("(Ace,");
                break;
            case 2:
                printf("(2,");
                break;
            case 3:
                printf("(3,");
                break;
            case 4:
                printf("(4,");
                break;
            case 5:
                printf("(5,");
                break;
            case 6:
                printf("(6,");
                break;
            case 7:
                printf("(7,");
                break;
            case 8:
                printf("(8,");
                break;
            case 9:
                printf("(9,");
                break;
            case 10:
                printf("(10,");
                break;
            case 11:
                printf("(Jack,");
                break;
            case 12:
                printf("(Queen,");
                break;
            case 0:
                printf("(King,");
        }

        switch (cards[i].suit)  // Switch statement to print the suit of each card based on the suit index
        {
            case 0:
                printf("Spades)\n");
                break;
            case 1:
                printf("Diamonds)\n");
                break;
            case 2:
                printf("Hearts)\n");
                break;
            case 3:
                printf("Clubs)\n");
        }
    }

    printf("\n");
}

void shuffleCards(struct Card *cards, int deckCount)
{
    int numCards = deckCount*52;
    struct Card tempCard;

    srand(time(NULL));

    for (int i=0; i<numCards; i++)
    {
        int j = (rand()%numCards) + 1;  // For each card, generate a random index that it will switch places with in the deck
        tempCard = cards[i];  // Using a temp card variable, switch the position in the array of the card and the card at the random index generated
        cards[i] = cards[j];
        cards[j] = tempCard;
    }
}