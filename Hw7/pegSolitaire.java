package packageDogukan;
import java.awt.*;
import javax.swing.*;
/**
* This class is the interface class.
* @author Doğukan TAŞTAN
* @version 1.0
* @since 2022-01-28
*/

interface pegSolitaire{

    public void mapBuilder(JButton b,int x,int y,JFrame f);
    public void startedFunction();
    public boolean check(int fromX, int fromY, int toX, int toY);
    public void moveControl(JFrame f);
    public boolean gameOverCheck();
    public int scoreCounter();
    public void computer_move();
}