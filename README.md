# CS50_2020_C
My solutions for the CS50's Introduction to Computer Science 2020 course Problem Sets 2 and 3: Readability, Caesar, Substitution, Plurality, Runoff and Tideman. C programming language.

## readability.c
The utility computes the approximate grade level needed to comprehend some text based on [the Coleman-Liau index](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index).

Compilation note: use `-lm` at the END of compilation command to avoid error arised by the use of <math.h> `round()` function.

Usage: ./readability.

Input: a text up to 1000 sumbols.

Output:
 - a number of letters in the text
 - a number of words based on a number of spaces in the text
 - a number of sentences based on a number of '.', '!' and '?' symbols in the text
 - a grade calculated by [the Coleman-Liau index](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index) formula
 
## caesar.c
The utility encrypts messages using [Caesar’s cipher](https://en.wikipedia.org/wiki/Caesar_cipher).

Usage: ./caesar [KEY], where [KEY] is a positive integer.

Input: a text up to 255 alphabetic sumbols [a-z][A-Z]. Case sensitive.

Output: encoded text.

## substitution.c
The utility implements a [substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher).

Usage: ./substitution [KEY], where [KEY] is a sequence of uniq 26 alphabetic symbols [a-z, A-Z], case insensitive in any order.

Input: a text up to 255 symbols.
Output: a text encoded with the [KEY].

## plurality.c
The program emulates simple [plurality voting](https://en.wikipedia.org/wiki/Plurality_(voting)) system.

Usage: ./plurality [CANDIDATES], where [CANDIDATES] is a list of candidates names divided by spaces.

Input:
 - positive integer number of voters.
 - top choice candidate for every voter - name of respective candidate.
 - 
Output: the winner's name.

## runoff.c
The program implements [the instant runoff voting](https://en.wikipedia.org/wiki/Instant-runoff_voting) system.

Usage: ./runoff [CANDIDATES], where [CANDIDATES] is a list of candidates names divided by spaces.

Input:
- positive integer number of voters.
- ranks for all candidate by every voter - ranked names of candidate.
- 
Output: the winner's name.

## tideman.c
The program implements [the ranked pairs](https://en.wikipedia.org/wiki/Ranked_pairs) voting system.

Usage: ./runoff [CANDIDATES], where [CANDIDATES] is a list of candidates names divided by spaces.

Input:
- positive integer number of voters.
- ranks for all candidate by every voter - ranked names of candidate.
- 
Output: the winner's name.
