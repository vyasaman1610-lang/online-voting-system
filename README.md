# Voting System in C (SAP ID Based)

## Overview
This project is a simple console-based voting system developed in C. It uses linked lists to store votes and ensures secure voting through SAP ID validation. The system prevents duplicate voting and verifies eligible voters before allowing them to cast a vote.

---

## Features
- SAP ID-based voter authentication
- Validation of 10-digit SAP IDs
- Restriction to pre-registered voters only
- Prevention of duplicate voting
- Dynamic vote storage using linked list
- Real-time vote counting
- Winner declaration (Party_1 vs Party_2)

---

## Technologies Used
- C Programming Language
- Linked List Data Structure
- Standard Input/Output Libraries

---

## How It Works
1. Admin enters the number of eligible voters.
2. System stores valid 10-digit SAP IDs.
3. Users enter their SAP ID to vote.
4. System checks:
   - Valid SAP ID format
   - Eligibility
   - Whether already voted
5. User selects a party (Party_1 or Party_2).
6. Votes are stored in a linked list.
7. Final result is displayed after voting ends.

---

## Menu Options
- Enter SAP ID to vote
- Choose Party_1 or Party_2
- Enter `0` to end voting and view results

---

## Project Structure
```text
voting_system.c
README.md
