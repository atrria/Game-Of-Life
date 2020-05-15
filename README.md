# [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life "Conway's Game of Life - Wikipedia") - cellular automaton


### Acording to the model:
- any live cell with fewer than two neighbours dies,
- any live cell with more than three neighbours dies,
- any live cell with two or three neighbours lives on to the next generation,
- any dead cell with three neighbours becomes a live cell.

The program by default simulates **100** generations of **25x50** toroidal array for the cell universe, meaning corners and vertical as well as horizontal borders are adjacent to each other.
User can specify both different number of generations and array size. 
Live cells are represented by *circles*, dead cells by *spaces*.

---
In plans: other variations of the automaton, allowing user to specify the conditions.
