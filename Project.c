import json
import os
from datetime import datetime

DATA_FILE = "transactions.json"

# Load existing transactions if file exists
def load_transactions():
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, "r") as f:
            return json.load(f)
    return []

# Save transactions to file
def save_transactions(transactions):
    with open(DATA_FILE, "w") as f:
        json.dump(transactions, f, indent=4)

# Add a transaction
def add_transaction(transactions):
    try:
        amount = float(input("Enter amount (use negative for expenses): "))
        category = input("Enter category (e.g., food, transport, entertainment, income): ").strip()
        date_str = input("Enter date (YYYY-MM-DD) [leave blank for today]: ").strip()
        if not date_str:
            date_str = datetime.today().strftime("%Y-%m-%d")
        transaction = {"amount": amount, "category": category, "date": date_str}
        transactions.append(transaction)
        save_transactions(transactions)
        print("Transaction added successfully!\n")
    except ValueError:
        print("Invalid input. Transaction not added.\n")

# View transactions
def view_transactions(transactions):
    if not transactions:
        print("No transactions found.\n")
        return
    
    choice = input("Filter by (a)ll, (c)ategory, or (d)ate? ").lower().strip()
    filtered = transactions

    if choice == 'c':
        category = input("Enter category: ").strip()
        filtered = [t for t in transactions if t["category"].lower() == category.lower()]
    elif choice == 'd':
        date = input("Enter date (YYYY-MM-DD): ").strip()
        filtered = [t for t in transactions if t["date"] == date]

    if not filtered:
        print("No matching transactions found.\n")
        return

    print("\nTransactions:")
    for t in filtered:
        print(f"{t['date']} | {t['category']} | {'+' if t['amount'] > 0 else ''}{t['amount']}")
    print()

# View summary
def view_summary(transactions):
    income = sum(t["amount"] for t in transactions if t["amount"] > 0)
    expenses = sum(-t["amount"] for t in transactions if t["amount"] < 0)
    balance = income - expenses

    print("\nSummary:")
    print(f"Total Income: {income}")
    print(f"Total Expenses: {expenses}")
    print(f"Remaining Balance: {balance}\n")

# ASCII Bar Chart of expenses by category
def view_expense_chart(transactions):
    from collections import defaultdict
    categories = defaultdict(float)
    for t in transactions:
        if t["amount"] < 0:
            categories[t["category"]] += -t["amount"]

    if not categories:
        print("No expenses to show.\n")
        return

    print("\nExpense Chart:")
    for cat, amt in categories.items():
        bars = "#" * int(amt // 10)  # scale factor
        print(f"{cat:15} | {bars} {amt}")
    print()

# Main menu
def main():
    transactions = load_transactions()

    while True:
        print("--- Personal Finance Manager ---")
        print("1. Add Transaction")
        print("2. View Transactions")
        print("3. View Summary")
        print("4. View Expense Chart")
        print("5. Exit")
        choice = input("Choose an option: ").strip()

        if choice == '1':
            add_transaction(transactions)
        elif choice == '2':
            view_transactions(transactions)
        elif choice == '3':
            view_summary(transactions)
        elif choice == '4':
            view_expense_chart(transactions)
        elif choice == '5':
            print("Goodbye!")
            break
        else:
            print("Invalid option. Please try again.\n")

if __name__ == "__main__":
    main()
