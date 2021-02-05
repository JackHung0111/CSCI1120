class DualKnightsTour {
public:
    DualKnightsTour(int r1, int c1, int r2, int c2);
    void print() const;
    bool isValid(char knight, int r, int c) const;
    bool hasMoreMoves() const;
    bool move(char knight, int r, int c);
private:
    char board[6][6];
    int posR1, posC1, posR2, posC2;
    int steps1, steps2;
    int consec1, consec2;
};
