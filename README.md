# Bank Account Management System

A simple C++ implementation of a bank account management system demonstrating object-oriented programming principles including inheritance and polymorphism.

## Overview

This project implements a basic banking system with features for depositing, withdrawing, and managing account information. It uses an abstract base class `BankAccount` with a concrete implementation in `MyBankAccount` to showcase inheritance and virtual functions in C++.

## Features

- **Deposit Money**: Add funds to your account (with validation for positive amounts)
- **Withdraw Money**: Remove funds from your account with balance verification
- **View Account Information**: Display current account details including name and balance
- **Change PIN**: Update your account PIN for security
- **User Authentication**: Simple PIN-based authentication for account operations

## Project Structure

- `main.cpp` - Contains all source code including the abstract base class, derived class, and main program logic
- `run.sh` - Build and run script for the project

## Building and Running

### On Linux/macOS:
```bash
bash run.sh
```

### On Windows:
```powershell
g++ main.cpp -o a.exe
.\a.exe
```

Or manually:
```bash
g++ main.cpp -o a.exe
./a.exe
```

## Usage

1. Start the program and enter your credentials:
   - **Name**: Ngong (default account name)
   - **PIN**: p (default account PIN)

2. Select an option from the menu:
   - **1) Deposit** - Enter amount to add to your account
   - **2) Withdrawal** - Enter amount to withdraw from your account
   - **3) See Information** - View your account details
   - **4) Change Pin** - Update your PIN
   - **0) Exit** - Exit the program

## Default Account Credentials

- **Name**: Ngong
- **PIN**: p
- **Initial Balance**: 0

## Class Design

### BankAccount (Abstract Base Class)
- **Public Members**: 
  - `name`: Account holder's name
  - `pin`: Account PIN
- **Private Members**:
  - `amount`: Account balance
- **Virtual Methods**:
  - `deposit()`: Add funds to account
  - `withdraw()`: Remove funds from account
  - `displayInfo()`: Show account information
  - `changePin()`: Update account PIN

### MyBankAccount (Derived Class)
Implements all virtual methods from the base class with the following business logic:
- Validates user credentials before any operation
- Ensures deposit and withdrawal amounts are positive
- Checks for sufficient balance before withdrawal
- Updates PIN only when old PIN matches

## Validation Rules

- **Deposit**: Amount must be greater than 0
- **Withdrawal**: Amount must be greater than 0 and cannot exceed current balance
- **All Operations**: Name and PIN must match account credentials

## Error Messages

- "You are too poor" - Attempt to deposit or withdraw negative/zero amount
- "User name and pin code do not match" - Invalid credentials
- "Insufficient Balance" - Attempt to withdraw more than available balance

## Requirements

- C++ compiler (GCC/G++ recommended)
- Standard C++ library support

## Notes

- This is a basic implementation for educational purposes
- Uses simple string comparison for authentication (not secure for production)
- Balance is stored as an integer (assumes currency in whole units)
- Session-based: Changes persist only during program execution
