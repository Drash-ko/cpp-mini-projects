# GitHub Supermarket 🛒

Simple console-based supermarket checkout program written in C++.

## Features

- Input number of unique items
- Choose between manual price entry or product code lookup
- Calculates total cost with quantity support
- Applies automatic discounts:
  - 10% for totals over 500
  - 15% for totals over 1000
- Displays total with two decimal precision

## Run

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o checkout
./checkout
```

## Built-in product codes

| Code | Price |
| --- | ---: |
| `2146` | `2.50` |
| `5764` | `3.20` |
| `6487` | `7.60` |
| `1345` | `1.20` |
| `7843` | `5.70` |
