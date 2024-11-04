char* losingPlayer(int x, int y) {
    bool winner = true;
    while (x>=1 && y>=4){
        x--;
        y-=4;
        winner = !winner;
    }
    if (winner) return "Bob";
    return "Alice";
}
