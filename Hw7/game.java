package packageDogukan;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.io.*;
import java.util.Scanner;
import java.util.Random;

/**
* This class is the base class of the game, all operations are done here.
* @author Doğukan TAŞTAN
* @version 1.0
* @since 2022-01-28
*/

public class game implements pegSolitaire {

    /**
     *  
     * @param board1 array referenced for preparation of board1
     * @param board2 array referenced for preparation of board2
     * @param board3 array referenced for preparation of board3
     * @param board4 array referenced for preparation of board4
     * @param board5 array referenced for preparation of board5
     * @param board6 array referenced for preparation of board6
     */
    private int[][] board1={
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,1,1,1,1,1,0,0,0,0,0},
            {1,1,1,2,1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1,0,0,0,0},
            {0,1,1,1,1,1,0,0,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
    };
    private int[][] board2={
            {0,0,0,1,1,1,0,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,0,0},
            {1,1,1,1,2,1,1,1,1,0,0},
            {1,1,1,1,1,1,1,1,1,0,0},
            {0,0,0,1,1,1,0,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
    };
    private int[][] board3={
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,0,0,0},
            {1,1,1,2,1,1,1,1,0,0,0},
            {1,1,1,1,1,1,1,1,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
    };
    private int[][] board4={
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,0,0,0,0},
            {1,1,1,2,1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1,0,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,1,1,1,0,0,0,0,0,0},
            {0,0,0,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
    };
    private int[][] board5={
            {0,0,0,0,1,0,0,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0,0},
            {0,0,1,1,1,1,1,0,0,0,0},
            {0,1,1,1,1,1,1,1,0,0,0},
            {1,1,1,1,2,1,1,1,1,0,0},
            {0,1,1,1,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,0,0,0,0},
            {0,0,0,1,1,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
    };
    private int[][] board6={
            {0,0,0,0,2,0,0,0,0,0,0},
            {0,0,0,1,0,1,0,0,0,0,0},
            {0,0,1,0,1,0,1,0,0,0,0},
            {0,1,0,1,0,1,0,1,0,0,0},
            {1,0,1,0,1,0,1,0,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
    };

 /**
  *  
 * @param r1 Radio button to select Game1
 * @param r2 Radio button to select Game2
 * @param r3 Radio button to select Game3
 * @param r4 Radio button to select Game4
 * @param r5 Radio button to select Game5
 * @param r6 Radio button to select Game6
 */
   private JRadioButton r1=new JRadioButton("Game 1");
   private JRadioButton r2=new JRadioButton("Game 2");
   private JRadioButton r3=new JRadioButton("Game 3");
   private JRadioButton r4=new JRadioButton("Game 4");
   private JRadioButton r5=new JRadioButton("Game 5");
   private JRadioButton r6=new JRadioButton("Game 6");


 /**
  *  
 * @param selectedX x coordinate of the selected button is kept here
 * @param selectedY y coordinate of the selected button is kept here 
 * @param targetX x coordinate of the target button is kept here
 * @param targetY y coordinate of the target button is kept here
 * @param oldselectedX Old location information is kept here for use in the undo process
 * @param oldselectedY Old location information is kept here for use in the undo process 
 * @param oldtargetX  Old location information is kept here for use in the undo process
 * @param oldtargetY Old location information is kept here for use in the undo process
 */
    private int selectedX=-1,selectedY=-1;
    private int targetX=-1,targetY=-1;
    private int oldselectedX=-1,oldselectedY=-1;
    private int oldtargetX=-1,oldtargetY=-1;
    private int xt,jt;

  /**
 * @param arr 11x11 JButton array to avoid problems and be more general.
 * @param top  gridLayout for top
 * @param center gridLayout for center
 */
    private  JButton[][] arr=new JButton[11][11]; 
    private  JPanel top = new JPanel(new GridLayout(1,12,1,1));
    private JPanel center = new JPanel(new GridLayout(11,11,1,1));


//******************************************************************************************************************************************************************
      
    /**
    * The startedFunction function is a my main function where I manage everything
    */
    public void startedFunction() {
        
        /**
        * @param f main frame
        * @param file  for save operation
        * @param b locBtn class array
        */
        JFrame f=new JFrame("PegSolitaire--Dogukan TASTAN 1901042627");
        File file = new File("save.txt");
        locBtn [] b = new locBtn[121];
        
        for(xt=0;xt<11;xt++){
            for(jt=0;jt<11;jt++){
                arr[xt][jt]=new JButton("");
                b[xt * 11 + jt] = new locBtn(xt, jt, arr[xt][jt]);
            }
        }
        

        /**
        * In this cycle, the click function is added to all buttons and necessary adjustments are made.
        */
        for(xt = 0;xt<121;xt++) {
            locBtn [] temp = {b[xt]};
            
            b[xt].b.addMouseListener(new MouseListener() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    if(selectedX==-1 && selectedY==-1){
                        selectedX = temp[0].x;
                        selectedY = temp[0].y;
                    }else{
                        targetX = temp[0].x;
                        targetY = temp[0].y;
                        moveControl(f);
                    }
                }

                @Override
                public void mousePressed(MouseEvent e) { }
                @Override
                public void mouseReleased(MouseEvent e) { }
                @Override
                public void mouseEntered(MouseEvent e) { }
                @Override
                public void mouseExited(MouseEvent e) { }
            });
        }

        /**
        * @param bg Using the button group allows you to select at most 1 of the radio buttons at the same time.
        */
        ButtonGroup bg=new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        bg.add(r3);
        bg.add(r4);
        bg.add(r5);
        bg.add(r6);

        top.add(r1);
        top.add(r2);
        top.add(r3);
        top.add(r4);
        top.add(r5);
        top.add(r6);

        /**
        * @param start Start button fills the map according to the radio button selection and starts the game
        */
        JButton start=new JButton("Start");
        top.add(start);

         start.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                for(int i=0;i<11;i++){
                    for(int j=0;j<11;j++)
                        mapBuilder(arr[i][j],i,j,f);
                }
            }
        });


        /**
        * @param saveButton saveButton saves the game in txt format.
        */
        JButton saveButton=new JButton("Save");
        top.add(saveButton);

        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try(BufferedWriter br = new BufferedWriter(new FileWriter(file))){

                    if(r1.isSelected())
                        br.write("1\n");
                    else if(r2.isSelected())
                        br.write("2\n");
                    else if(r3.isSelected())
                        br.write("3\n");
                    else if(r4.isSelected())
                        br.write("4\n");
                    else if(r5.isSelected())
                        br.write("5\n");
                    else if(r6.isSelected())
                        br.write("6\n");

                    for(int i=0;i<11;i++){
                        for(int j=0;j<11;j++){
                            if(arr[i][j].getText()=="P")
                                br.write("P ");
                            else if(arr[i][j].getText()=="X")
                                br.write("X ");
                            else if(arr[i][j].getText()==" ")
                                br.write(". ");
                        }
                        br.write("\n");
                    }
                }
                catch (IOException a) {
                    System.out.println("Unable to read file " +file.toString());
                }
            }
        });

        /**
        * @param laodButton loadButton loads the game by reading it from txt.
        */
        JButton loadButton=new JButton("Load");
        top.add(loadButton);
       
        loadButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                boolean gameover;
                int score;
                String message;
                
                FileDialog dialog = new FileDialog((Frame)null, "Select File to Open");
                dialog.setMode(FileDialog.LOAD);
                dialog.setVisible(true);
                String path = dialog.getDirectory() + dialog.getFile();
                
                File load = new File(path);
               
                try( Scanner scanner = new Scanner(load)){
                    String type = scanner.next();
                    if(type.equals("1"))
                        r1.setSelected(true);
                    else if(type.equals("2"))
                        r2.setSelected(true);
                    else if(type.equals("3"))
                        r3.setSelected(true);
                    else if(type.equals("4"))
                        r4.setSelected(true);
                    else if(type.equals("5"))
                        r5.setSelected(true);
                    else if(type.equals("6"))
                        r6.setSelected(true);

                        for(int i=0;i<11;i++){
                            for(int j=0;j<11;j++){
                                String cell = scanner.next();
                                arr[i][j].setVisible(true);
                                center.add(arr[i][j]);
                                
                                if(cell.equals("X")){
                                    arr[i][j].setVisible(false);
                                }
                                else if(cell.equals("P")){
                                    arr[i][j].setText("P");
                                    
                                }
                                else if(cell.equals(".")){
                                    arr[i][j].setText(" ");
                                }    
                            } 
                        }
                }
                catch (IOException a) {
                    System.out.println("Unable to read file " +file.toString());
                }
                
                f.repaint();
                
                gameover=gameOverCheck();
                if(!gameover){
                    score=scoreCounter();
                    message=String.format("%s %d", "THE GAME IS OVER YOUR SCORE:",score);
                   
                    JOptionPane.showMessageDialog(null, message,"GAME OVER", JOptionPane.WARNING_MESSAGE);
                }
            }
        });


        /**
        * @param reset Resets the game, as it is similar to the start command, it calls it to reload.
        */
        JButton reset=new JButton("Reset");
        top.add(reset);

        reset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                start.doClick();
            }
        });

        /**
        * @param undo enables undo by replaying previously saved variables
        */
        JButton undo=new JButton("Undo");
        top.add(undo);

         undo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
               undoControl(f);

            }
        });


        /**
        * @param computerPlayButton starts autoplay mode
        */
        JButton computerPlayButton=new JButton("Auto Play");
        top.add(computerPlayButton);

          computerPlayButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                boolean gameover;
              
                while(true){
                    computer_move();
                    moveControl(f);
                    gameover=gameOverCheck();
                    if(!gameover)
                        break;
                }
            }
        });

        f.add(top,BorderLayout.PAGE_START);
        f.add(center,BorderLayout.LINE_START);

        f.setSize(1300,500);
        f.setVisible(true);
    }


    /**
    *  This function randomly generate a valid move.
    */
    public void computer_move(){
        Random r=new Random();
        boolean control;
        int flag=0;
         
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                if(arr[i][j].getText().equals("P")){
                    selectedX = i;
                    selectedY = j;
                    targetX = r.nextInt(11);
                    targetY = r.nextInt(11);
                    control=check(selectedX,selectedY,targetX,targetY);
                    if(control){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
    }  

    /**
    * This function counts pegs
    * @return score
    */
    public int scoreCounter(){
        
        int counter=0;
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                if(arr[i][j].getText().equals("P"))
                    counter++;
            }
        }
        return counter;
    }

    
    /**
    *  This function performs the undo operation
    */
    public void undoControl(JFrame f){

        boolean gameover;
        int score;
        String message;

        arr[oldselectedX][oldselectedY].setText("P");
        arr[oldtargetX][oldtargetY].setText(" ");
        arr[(oldselectedX+oldtargetX)/2][(oldselectedY+oldtargetY)/2].setText("P");
        f.repaint();

        gameover=gameOverCheck();
        if(gameover==false){
            score=scoreCounter();
            message=String.format("%s %d", "THE GAME IS OVER YOUR SCORE:",score);
           
            JOptionPane.showMessageDialog(null, message,"GAME OVER", JOptionPane.WARNING_MESSAGE);
        }
        else{
            selectedX=-1;
            selectedY=-1;
            targetX=-1;
            targetY=-1;
        }                                           
    }

    /**
    *  This function builds the map and prepares the game
    */
    public void mapBuilder(JButton b,int x,int y,JFrame f){
       
        if(r1.isSelected()){
            b.setVisible(true);
            if(board1[x][y]==0){
                b.setText("X");
                center.add(b);
                b.setVisible(false);

            }
            else if(board1[x][y]==1){
                b.setText("P");
                center.add(b);
            }
            else if(board1[x][y]==2){
                b.setText(" ");
                center.add(b);
            }
        }

        else if(r2.isSelected()){
            b.setVisible(true);
            if(board2[x][y]==0){
                b.setText("X");
                center.add(b);
                b.setVisible(false);

            }
            else if(board2[x][y]==1){
                b.setText("P");
                center.add(b);
            }
            else if(board2[x][y]==2){
                b.setText(" ");
                center.add(b);
            }
        }

        else if(r3.isSelected()){
            b.setVisible(true);
            if(board3[x][y]==0){
                b.setText("X");
                center.add(b);
                b.setVisible(false);

            }
            else if(board3[x][y]==1){
                b.setText("P");
                center.add(b);
            }
            else if(board3[x][y]==2){
                b.setText(" ");
                center.add(b);
            }
        }

        else if(r4.isSelected()){
            b.setVisible(true);
            if(board4[x][y]==0){
                b.setText("X");
                center.add(b);
                b.setVisible(false);

            }
            else if(board4[x][y]==1){
                b.setText("P");
                center.add(b);
            }
            else if(board4[x][y]==2){
                b.setText(" ");
                center.add(b);
            }
        }

        else if(r5.isSelected()){
            b.setVisible(true);
            if(board5[x][y]==0){
                b.setText("X");
                center.add(b);
                b.setVisible(false);

            }
            else if(board5[x][y]==1){
                b.setText("P");
                center.add(b);
            }
            else if(board5[x][y]==2){
                b.setText(" ");
                center.add(b);
            }
        }
        else if(r6.isSelected()){
            b.setVisible(true);
            if(board6[x][y]==0){
                b.setText("X");
                center.add(b);
                b.setVisible(false);

            }
            else if(board6[x][y]==1){
                b.setText("P");
                center.add(b);
            }
            else if(board6[x][y]==2){
                b.setText(" ");
                center.add(b);
            }
        }
     
        f.repaint();
    }

    /**
    * This function checks the validity of the move
    * @return true or false 
    */
    public boolean check(int fromX, int fromY, int toX, int toY){
        if(r6.isSelected() && arr[toX][toY].getText().equals(" ") && arr[fromX][fromY].getText().equals("P")  && arr[(fromX+toX)/2][(fromY+toY)/2].getText().equals("P")){
            return true;
        }
        else{

            if(!(Math.abs(fromX - toX) == 2 && fromY == toY) &&
                    !(Math.abs(fromY - toY) == 2 && fromX == toX)) return false;
            
            if(!(arr[fromX][fromY].getText().equals("P")) || !(arr[(fromX+toX)/2][(fromY+toY)/2].getText().equals("P"))  || !(arr[toX][toY].getText().equals(" "))) return false;
            return true;
        }    
    }

    /**
    * This function control the move
    */
    public void moveControl(JFrame f){

        boolean check = check(selectedX,selectedY,targetX,targetY);
        boolean gameover;
        int score;
        String message;

        if(check){

            oldselectedX=selectedX;
            oldselectedY=selectedY;
            oldtargetX=targetX;
            oldtargetY=targetY;

            if(r6.isSelected()){
                
                if(selectedY>1){
                    if((selectedX+2 == targetX)  && (selectedY-2==targetY)){
                        arr[(selectedX+1)][(selectedY-1)].setText(" "); 
                        arr[selectedX][selectedY].setText(" ");
                        arr[targetX][targetY].setText("P");
                    }
                }
                if(selectedY>1 && selectedX>1){
                    if((selectedX-2 == targetX)  && (selectedY-2==targetY)){
                        arr[(selectedX-1)][(selectedY-1)].setText(" "); 
                        arr[selectedX][selectedY].setText(" ");
                        arr[targetX][targetY].setText("P");
                    }
                }
                if(selectedX>1){
                    if((selectedX-2 == targetX)  && (selectedY+2==targetY)){
                        arr[(selectedX-1)][(selectedY+1)].setText(" ");
                        arr[selectedX][selectedY].setText(" ");
                        arr[targetX][targetY].setText("P");
                    }
                }   
                if((selectedX+2 == targetX)  && (selectedY+2==targetY)){
                    arr[(selectedX+1)][(selectedY+1)].setText(" "); 
                    arr[selectedX][selectedY].setText(" ");
                    arr[targetX][targetY].setText("P");
                }

                if((selectedX  == targetX)  && (selectedY+4==targetY)){
                    arr[(selectedX)][(selectedY)+2].setText(" "); 
                    arr[selectedX][selectedY].setText(" ");
                    arr[targetX][targetY].setText("P");
                }
                if(selectedX>1){
                    if((selectedX == targetX)  && (selectedY-4==targetY)){
                        arr[(selectedX)][(selectedY-2)].setText(" "); 
                        arr[selectedX][selectedY].setText(" ");
                        arr[targetX][targetY].setText("P");
                    }
                }
            }
            else { 
                arr[selectedX][selectedY].setText(" ");
                arr[targetX][targetY].setText("P");
                arr[(selectedX+targetX)/2][(selectedY+targetY)/2].setText(" ");  
            }
            
            f.repaint();
            selectedX=-1;
            selectedY=-1;
            targetX=-1;
            targetY=-1;
            
            gameover=gameOverCheck();
            if(!gameover){
                score=scoreCounter();
                message=String.format("%s %d", "THE GAME IS OVER YOUR SCORE:",score);
            
                JOptionPane.showMessageDialog(null, message,"GAME OVER", JOptionPane.WARNING_MESSAGE);
            } 
         }
        else{
            selectedX=targetX;
            selectedY=targetY;
            targetX=-1;
            targetY=-1;
        }                                           
    }

    /**
    * This function checks if the game is over
    */
    public boolean gameOverCheck(){

        boolean check1;
        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
                
                if(r6.isSelected()){
                    if(i<9 && j<9){
                        check1=check(i, j, i + 2, j+2);
                        if(check1)
                            return true;
                    }
                    if(i>1 && j>1){
                        check1=check(i, j, i - 2, j-2);
                        if(check1)
                            return true;
                    }
                    if(j<7){
                        check1=check(i, j, i, j+4 );
                        if(check1)
                            return true;
                    }
                    if(j>3){
                        check1=check(i, j, i, j-4);
                        if(check1)
                            return true;
                    }
                    if(i<9 && j>1){
                        check1=check(i, j, i + 2, j-2);
                        if(check1)
                            return true;
                    }
                    if(i>1 && j<9){
                        check1=check(i, j, i - 2, j+2);
                        if(check1)
                            return true;
                    }
                }
                else{
                    if(i<9){
                        check1=check(i, j, i + 2, j);
                        if(check1)
                            return true;
                    }
                    if(i>1){
                        check1=check(i, j, i - 2, j);
                        if(check1)
                            return true;
                    }
                    if(j<9){
                        check1=check(i, j, i, j + 2);
                        if(check1)
                            return true;
                    }
                    if(j>1){
                        check1=check(i, j, i, j - 2);
                        if(check1)
                            return true;
                    }
                }
            }
        }
        return false;
    }
}

//**********************************************************************************************************************************************************************
// Dogukan TASTAN 1901042627