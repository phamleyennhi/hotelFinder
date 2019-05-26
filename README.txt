Programming Assignment 3
Jakub Podmokly, Nhi Pham Le Yen
May 8th, 2019

In this program, we develop a hotel-finder application termed hotelFinder that can help you search for a hotel in a specific city. The identification of hotels will be based on the key produced by the combination of hotelName and cityName.

Usage: Usage ./hotelFinder -f <filename>


Our program can handle the following types of commands:

- find k: Find the element having a key k and display the entire record together with the number of comparisons made and the actual time taken by the find execution.

– add s: The data provided by string s consisting hotelName, cityName, stars, price, countryName, address corresponding to a hotel are to be inserted. If the element already exists, you will receive a warning to the standard error.

– delete k: Delete the hotel record with key k. If no such element exists, print out a warning message to the standard error.

– dump f: Dump the content of the entire structure(s) into the file f and sort the content of the file f according to the hotelName in alphabetically increasing order.

– allinCity c: List all hotels in the city c.

– quit: terminate the program.



Thank you for using our software!

Copyright 2019 Jakub Podmokly, Nhi Pham Le Yen

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

