days=int(input("enter the days:"))
year=days//365
remaining_days=days%365
month=remaining_days//30
daysleft=remaining_days%30
print("year:",year)
print("days:",days)
print("month:",month)