# Searching-Movies-by-Separate-Chaining
## Problem
In this project our task is to build a search engine for the given data. Data is composed of
objects (records). Each object has three attributes: movie ID, average rating
and number of votes to review each movie. Your task is populate the data in
your hello search engine based on the average rating. You can use the search
engine to answer questions like:<br>
Which one is the most popular movie?<br>
Which one is the least popular movie?<br>
How many movies have same ratings?<br>
How many movies have lowest votes?<br>
How many movies have highest votes?<br>
How movie can be searched by ID?<br>
## Process
For performing operation like search engine by separate chaining technique.We
first, started working on reading data from file we read file string by string and
then store it in array.We stored first Movie Id then Rating and the we stored
Votes against each movie. We stored whole data in Linked List against key of
rating.In linked list we made node of four things first part for movie Id, second
part for storing Average rating, third part of storing votes and fourth part for
pointer that points to its next position. For making functions for search movies
we made separate class named Search and in this class we made objects of linked
list according to size of hash table. We made hash table of size 100 because it
was suitable for our purposes.
