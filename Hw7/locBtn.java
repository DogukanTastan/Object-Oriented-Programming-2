package packageDogukan;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
* This class is required because a special case occurs in buttons, button data is kept in this class.
* @author Doğukan TAŞTAN
* @version 1.0
* @since 2022-01-28
*/

public class locBtn{

    int x;
    int y;
    JButton b;

   /**
     * @param x coordinate x
     * @param y tcoordinate y
     * @param b button
     */
    
    public locBtn(int x, int y, JButton b){
        this.x = x;
        this.y = y;
        this.b = b;
    }
}