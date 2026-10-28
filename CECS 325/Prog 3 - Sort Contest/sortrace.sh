#Name: Bryan Giang
#Class: CECS 325-01
#Project Name: Prog 3 – Sort Contest
#Due Date: 10-12-2026

#I certify that this program is my own original work. I did not copy any part of this program from
#any other source including inappropriate AI use. I did not share this program with anyone. I
#further certify that I typed each and every line of code in this program.

echo Generating 1000000 random numbers
sleep 1
./generate 1000000 -100000 100000 
sleep 1
echo Starting system sort
sleep 1
{ time sort -n numbers.dat > systemsort.out; } 2>> sortrace.log 
sleep 1
echo Starting mysort
sleep 1
{ time ./mysort numbers.dat mysort.out; } 2>> sortrace.log
sleep 1
wc mysort.out 
sort -c -n mysort.out 2>> sortrace.log


