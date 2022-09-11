# Jumpers  
### How to play  
 Game starts with 8 player's pawns and 8 computer's pawns on the board:  
 ```
   a b c d  
1 C C C C  
2 C C C C  
3 * * * *  
4 * * * *   
5 Y Y Y Y  
6 Y Y Y Y   
```
C - computer's pawn  
Y - player's (your) pawn  
\* - empty field on the board  

Under the board, the message is displayed:  
```
What move do you want to make?
```  
It's player's turn to move their pawn.
Player inputs the position of the pawn, they want to move and then final position of the pawn.  
For example:  
```
5a  
4a 
```
The move must obey following rules:
* One moves only their pawn.
* Pieces can move in eight possible directions (orthogonally and diagonally).
* Pawn can be moved to the any adjacent empty square.
* An adjacent pawn can be jumped if there is an adjacent empty square on the directly opposite side of that piece.  

After player, it is computer's turn to move.  
Player and computer make move one after another, until one of them fill all the squares on the other side of the board.
